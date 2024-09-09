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