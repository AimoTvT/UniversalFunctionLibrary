/**
* Copyright: Aimo_皑墨
* Open Source Date: Jun 5, 2023
* BiLiBiLi (哔哩哔哩) address: https://space.bilibili.com/146962867
* making address: https://github.com/AimoTvT/UniversalFunctionLibrary
* We welcome the contributions of powerful movers and movers to join this plugin
* Build powerful plugins together!!
*
* 版权所有权: Aimo_皑墨
* 开源时间: 2023年6月29日
* BiLiBiLi(哔哩哔哩)地址: https://space.bilibili.com/146962867
* GitHub地址: https://github.com/AimoTvT/UniversalFunctionLibrary
* 欢迎有实力的大佬/萌新加入本插件的贡献
* 一起打造强大的插件!!!
*/



#include "MovementSounds/MovementSoundsComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UMovementSoundsComponent::UMovementSoundsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);  /** * 开启复制 */

	// ...
}


// Called when the game starts
void UMovementSoundsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UMovementSoundsComponent::SetFootprintAudioComponents(TArray<UAudioComponent*> InFootprintAudioComponents)
{
	for (size_t i = 0; i < FootprintAudioComponents.Num(); i++)
	{
		if (FootprintAudioComponents[i] && FootprintAudioComponents[i]->ComponentTags.Find(UMovementSoundsComponent::GetFName()))
		{
			FootprintAudioComponents[i]->DestroyComponent();
		}
	}
	FootprintAudioComponents = InFootprintAudioComponents;
}

USoundCue* UMovementSoundsComponent::GetSoundCuesIndex(TArray<TSoftObjectPtr<USoundCue>>& InSoftSoundCues, TArray<TObjectPtr<USoundCue>>& InSoundCue, int InIndex)
{
	if (InSoundCue.IsValidIndex(InIndex))
	{
		if (InSoundCue[InIndex])
		{
			return InSoundCue[InIndex];
		}
	}
	if (InSoftSoundCues.IsValidIndex(InIndex))
	{
		if (InSoftSoundCues[InIndex].IsNull())
		{
			return nullptr;
		}
		if (InSoftSoundCues[InIndex].IsValid() == false)
		{
			InSoftSoundCues[InIndex].LoadSynchronous();
		}
		if (InSoundCue.IsValidIndex(InIndex) == false)
		{
			InSoundCue.SetNum(InSoftSoundCues.Num());
		}
		if (InSoftSoundCues[InIndex].Get())
		{
			InSoundCue[InIndex] = InSoftSoundCues[InIndex].Get();
			return InSoundCue[InIndex];
		}
		return nullptr;
	}
	if (InSoftSoundCues.Num())
	{
		return GetSoundCuesIndex(InSoftSoundCues, InSoundCue, 0);
	}
	return nullptr;
}

void UMovementSoundsComponent::SetSoftDefaultFootprintSoundCues(TArray<TSoftObjectPtr<USoundCue>> InSoftDefaultFootprintSoundCues)
{
	SoftDefaultFootprintSoundCues = InSoftDefaultFootprintSoundCues;
	DefaultFootprintSoundCue.Empty();
	DefaultFootprintSoundCue.SetNum(SoftDefaultFootprintSoundCues.Num());
}

USoundCue* UMovementSoundsComponent::GetDefaultFootprintSoundCues(int InIndex)
{
	return GetSoundCuesIndex(SoftDefaultFootprintSoundCues, DefaultFootprintSoundCue, InIndex);
}

void UMovementSoundsComponent::SetSoftCustomFootprintSoundCues(TArray<TSoftObjectPtr<USoundCue>> InSoftCustomFootprintSoundCues)
{
	SoftCustomFootprintSoundCues = InSoftCustomFootprintSoundCues;
	CustomFootprintSoundCue.Empty();
	CustomFootprintSoundCue.SetNum(SoftCustomFootprintSoundCues.Num());
}

USoundCue* UMovementSoundsComponent::GetCustomFootprintSoundCues(int InIndex)
{
	return GetSoundCuesIndex(SoftCustomFootprintSoundCues, CustomFootprintSoundCue, InIndex);
}

USoundCue* UMovementSoundsComponent::GetFootprintSoundCues(int InIndex)
{
	return SoftCustomFootprintSoundCues.Num() ? GetCustomFootprintSoundCues(InIndex) : GetDefaultFootprintSoundCues(InIndex);
}

bool UMovementSoundsComponent::PlayFootprintSoundCue(int InIndex, ECollisionPhysicalMaterialClassEnum InCollisionPhysicalMaterialClassEnum, float VolumeMultiplier, float PitchMultiplier, float StartTime)
{
	if (FootprintAudioComponents.IsValidIndex(InIndex) && FootprintAudioComponents[InIndex])
	{
		USoundCue* SoundCue = GetFootprintSoundCues(InIndex);
		if (SoundCue)
		{
			if (FootprintAudioComponents[InIndex]->Sound != SoundCue)
			{
				FootprintAudioComponents[InIndex]->SetSound(SoundCue);
			}
			if (FootprintAudioComponents[InIndex]->VolumeMultiplier != VolumeMultiplier * FootprintVolumeMultiplier)
			{
				FootprintAudioComponents[InIndex]->SetVolumeMultiplier(VolumeMultiplier * FootprintVolumeMultiplier);
			}
			if (FootprintAudioComponents[InIndex]->PitchMultiplier != PitchMultiplier * FootprintPitchMultiplier)
			{
				FootprintAudioComponents[InIndex]->SetPitchMultiplier(PitchMultiplier * FootprintPitchMultiplier);
			}
			FootprintAudioComponents[InIndex]->SetIntParameter(TEXT("CollisionPhysicalMaterialClassEnum"), int(InCollisionPhysicalMaterialClassEnum));
			FootprintAudioComponents[InIndex]->Play(StartTime);
			return true;
		}
	}
	if (bSpawnAudioComponent)
	{
		if (SpawnFootprintAudioComponent(InIndex))
		{
			return PlayFootprintSoundCue(InIndex, InCollisionPhysicalMaterialClassEnum, VolumeMultiplier, PitchMultiplier, StartTime);
		}
	}
	return false;
}


void UMovementSoundsComponent::SetSoftDefaultJumpSoundCues(TArray<TSoftObjectPtr<USoundCue>> InSoftDefaultJumpSoundCues)
{
	SoftDefaultJumpSoundCues = InSoftDefaultJumpSoundCues;
	DefaultJumpSoundCue.Empty();
	DefaultJumpSoundCue.SetNum(SoftDefaultJumpSoundCues.Num());
}

USoundCue* UMovementSoundsComponent::GetDefaultJumpSoundCues(int InIndex)
{
	return GetSoundCuesIndex(SoftDefaultJumpSoundCues, DefaultJumpSoundCue, InIndex);
}

void UMovementSoundsComponent::SetSoftCustomJumpSoundCues(TArray<TSoftObjectPtr<USoundCue>> InSoftCustomJumpSoundCues)
{
	SoftCustomJumpSoundCues = InSoftCustomJumpSoundCues;
	CustomJumpSoundCue.Empty();
	CustomJumpSoundCue.SetNum(SoftCustomJumpSoundCues.Num());
}

USoundCue* UMovementSoundsComponent::GetCustomJumpSoundCues(int InIndex)
{
	return GetSoundCuesIndex(SoftCustomJumpSoundCues, CustomJumpSoundCue, InIndex);
}

USoundCue* UMovementSoundsComponent::GetJumpSoundCues(int InIndex)
{
	return SoftCustomJumpSoundCues.Num() ? GetCustomJumpSoundCues(InIndex) : GetDefaultJumpSoundCues(InIndex);
}

UAudioComponent* UMovementSoundsComponent::SpawnFootprintAudioComponent(int InIndex)
{
	if (GetOwner() && SoftDefaultFootprintSoundCues.IsValidIndex(InIndex) || SoftCustomFootprintSoundCues.IsValidIndex(InIndex))
	{
		if (FootprintAudioComponents.IsValidIndex(InIndex))
		{
			if (FootprintAudioComponents[InIndex])
			{
				FootprintAudioComponents[InIndex]->DestroyComponent();
			}
		}
		else
		{
			FootprintAudioComponents.SetNum(InIndex + 1);
		}
		UAudioComponent* NewComponent = NewObject<UAudioComponent>(GetOwner());
		FootprintAudioComponents[InIndex] = NewComponent;
		if (NewComponent)
		{
			NewComponent->ComponentTags.Add(UMovementSoundsComponent::GetFName());
		}
		return NewComponent;
	}
	return nullptr;
}
