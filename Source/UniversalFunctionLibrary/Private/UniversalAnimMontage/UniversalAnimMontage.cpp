// Fill out your copyright notice in the Description page of Project Settings.


#include "UniversalAnimMontage/UniversalAnimMontage.h"
#include "Animation/AnimMontage.h"
#include "Components/SkeletalMeshComponent.h"

UUniversalAnimMontage::UUniversalAnimMontage()
{
}

UUniversalAnimMontage::~UUniversalAnimMontage()
{
}


UUniversalAnimMontage* UUniversalAnimMontage::CreateProxyObjectForPlayMontage(
	class USkeletalMeshComponent* InSkeletalMeshComponent,
	class UAnimMontage* MontageToPlay,
	FName InTagName,
	float PlayRate,
	float StartingPosition,
	FName StartingSection,
	bool  InAutoDestroy)
{
	UUniversalAnimMontage* Proxy = NewObject<UUniversalAnimMontage>();
	Proxy->TagName = InTagName;
	Proxy->AutoDestroy = InAutoDestroy;
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->PlayMontage(InSkeletalMeshComponent, MontageToPlay, PlayRate, StartingPosition, StartingSection);
	Proxy->Init(InSkeletalMeshComponent);
	return Proxy;
}


float UUniversalAnimMontage::PlayMontage(class USkeletalMeshComponent* InSkeletalMeshComponent,
	class UAnimMontage* MontageToPlay,
	float PlayRate,
	float StartingPosition,
	FName StartingSection)
{
	MontageLength = 0.0f;
	if (InSkeletalMeshComponent)
	{
		if (UAnimInstance* AnimInstance = InSkeletalMeshComponent->GetAnimInstance())
		{
			MontageLength = AnimInstance->Montage_Play(MontageToPlay, PlayRate, EMontagePlayReturnType::MontageLength, StartingPosition);
			if (MontageLength > 0.f)
			{
				AnimInstancePtr = AnimInstance;
				if (FAnimMontageInstance* MontageInstance = AnimInstance->GetActiveInstanceForMontage(MontageToPlay))
				{
					MontageInstanceID = MontageInstance->GetInstanceID();
				}

				if (StartingSection != NAME_None)
				{
					AnimInstance->Montage_JumpToSection(StartingSection, MontageToPlay);
				}

				BlendingOutDelegate.BindUObject(this, &UUniversalAnimMontage::OnMontageBlendingOut);
				AnimInstance->Montage_SetBlendingOutDelegate(BlendingOutDelegate, MontageToPlay);

				MontageEndedDelegate.BindUObject(this, &UUniversalAnimMontage::OnMontageEnded);
				AnimInstance->Montage_SetEndDelegate(MontageEndedDelegate, MontageToPlay);
			}
		}
	}

	if (MontageLength < 0.f)
	{
		OnInterrupted.Broadcast(TagName, NAME_None);
	}

	return MontageLength;
}

float UUniversalAnimMontage::PlayMontage(USkeletalMeshComponent* InSkeletalMeshComponent, UAnimMontage* MontageToPlay, FName InTagName, float PlayRate, float StartingPosition, FName StartingSection)
{
	TagName = InTagName;
	return PlayMontage(InSkeletalMeshComponent, MontageToPlay, PlayRate, StartingPosition, StartingSection);
}

void UUniversalAnimMontage::Init(USkeletalMeshComponent* InSkeletalMeshComponent)
{
	if (UAnimInstance* AnimInstance = InSkeletalMeshComponent->GetAnimInstance())
	{
		AnimInstance->OnPlayMontageNotifyBegin.AddDynamic(this, &UUniversalAnimMontage::OnNotifyBeginReceived);
		AnimInstance->OnPlayMontageNotifyEnd.AddDynamic(this, &UUniversalAnimMontage::OnNotifyEndReceived);
	}
}

bool UUniversalAnimMontage::IsNotifyValid(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload) const
{
	return ((MontageInstanceID != INDEX_NONE) && (BranchingPointNotifyPayload.MontageInstanceID == MontageInstanceID));
}


void UUniversalAnimMontage::OnNotifyBeginReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload)
{
	if (IsNotifyValid(NotifyName, BranchingPointNotifyPayload))
	{
		OnNotifyBegin.Broadcast(TagName, NotifyName, BranchingPointNotifyPayload);
	}
}


void UUniversalAnimMontage::OnNotifyEndReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload)
{
	if (IsNotifyValid(NotifyName, BranchingPointNotifyPayload))
	{
		OnNotifyEnd.Broadcast(TagName, NotifyName, BranchingPointNotifyPayload);
	}
}


void UUniversalAnimMontage::OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted)
{
	if (bInterrupted)
	{
		OnInterrupted.Broadcast(TagName, NAME_None);
		bInterruptedCalledBeforeBlendingOut = true;
	}
	else
	{
		OnBlendOut.Broadcast(TagName, NAME_None);
	}
}

void UUniversalAnimMontage::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (!bInterrupted)
	{
		OnCompleted.Broadcast(TagName, NAME_None);
	}
	else if (!bInterruptedCalledBeforeBlendingOut)
	{
		OnInterrupted.Broadcast(TagName, NAME_None);
	}
	if (AutoDestroy)
	{
		ConditionalBeginDestroy();
	}
}

void UUniversalAnimMontage::UnbindDelegates()
{
	if (UAnimInstance* AnimInstance = AnimInstancePtr.Get())
	{
		AnimInstance->OnPlayMontageNotifyBegin.RemoveDynamic(this, &UUniversalAnimMontage::OnNotifyBeginReceived);
		AnimInstance->OnPlayMontageNotifyEnd.RemoveDynamic(this, &UUniversalAnimMontage::OnNotifyEndReceived);
	}
}

void UUniversalAnimMontage::BeginDestroy()
{
	UnbindDelegates();
	OnDestroy.Broadcast(this, TagName);
	Super::BeginDestroy();
}
