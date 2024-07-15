// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"


#include "UniversalAnimMontage.generated.h"
/**
 * 
 */
UCLASS()
class UNIVERSALFUNCTIONLIBRARY_API UUniversalAnimMontage : public UObject
{
	GENERATED_BODY()

public:
	UUniversalAnimMontage();
	~UUniversalAnimMontage();

	/** * 标签组  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags")
	FName TagName;

	bool AutoDestroy = false;

	float MontageLength = 0.0f;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMontagePlayDelegate, FName, TagName, FName, NotifyName);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnMontageNotifyPlayDelegate, FName, TagName, FName, NotifyName, const FBranchingPointNotifyPayload&, BranchingPointPayload);


	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDestroy, UUniversalAnimMontage*, UniversalAnimMontage, FName, TagName);


	UPROPERTY(BlueprintAssignable)
	FOnMontageNotifyPlayDelegate OnNotifyBegin;

	UPROPERTY(BlueprintAssignable)
	FOnMontageNotifyPlayDelegate OnNotifyEnd;

	// Called when Montage starts blending out and is not interrupted
	UPROPERTY(BlueprintAssignable)
	FOnMontagePlayDelegate OnBlendOut;

	// Called when Montage has been interrupted (or failed to play)
	UPROPERTY(BlueprintAssignable)
	FOnMontagePlayDelegate OnInterrupted;

	// Called when Montage finished playing and wasn't interrupted , 
	UPROPERTY(BlueprintAssignable)
	FOnMontagePlayDelegate OnCompleted;

	UPROPERTY(BlueprintAssignable)
	FOnDestroy OnDestroy;

	// Called to perform the query internally
	static UUniversalAnimMontage* CreateProxyObjectForPlayMontage(
		class USkeletalMeshComponent* InSkeletalMeshComponent,
		class UAnimMontage* MontageToPlay,
		FName InTagName,
		float PlayRate = 1.f,
		float StartingPosition = 0.f,
		FName StartingSection = NAME_None,
		bool  InAutoDestroy = false);

public:
	//~ Begin UObject Interface
	virtual void BeginDestroy() override;
	//~ End UObject Interface

protected:
	UFUNCTION()
	void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
	void OnNotifyBeginReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);

	UFUNCTION()
	void OnNotifyEndReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);

private:
	TWeakObjectPtr<UAnimInstance> AnimInstancePtr;
	int32 MontageInstanceID = INDEX_NONE;
	uint32 bInterruptedCalledBeforeBlendingOut : 1;

	void Init(USkeletalMeshComponent* InSkeletalMeshComponent);

	bool IsNotifyValid(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload) const;
	void UnbindDelegates();

	FOnMontageBlendingOutStarted BlendingOutDelegate;
	FOnMontageEnded MontageEndedDelegate;

public:
	// Attempts to play a montage with the specified settings. Returns whether it started or not.
	float PlayMontage(
		class USkeletalMeshComponent* InSkeletalMeshComponent,
		class UAnimMontage* MontageToPlay,
		float PlayRate = 1.f,
		float StartingPosition = 0.f,
		FName StartingSection = NAME_None);

	float PlayMontage(
		class USkeletalMeshComponent* InSkeletalMeshComponent,
		class UAnimMontage* MontageToPlay,
		FName InTagName,
		float PlayRate = 1.f,
		float StartingPosition = 0.f,
		FName StartingSection = NAME_None);


};