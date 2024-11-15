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
#include "Components/ActorComponent.h"
#include "Config/UniversalEnum.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"

#include "MovementSoundsComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNIVERSALFUNCTIONLIBRARY_API UMovementSoundsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovementSoundsComponent();

	/** * 自动生成音效组件来补充缺失的 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DefaultSoundCues")
	bool bSpawnAudioComponent = true;

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DefaultSoundCues")
	float FootprintVolumeMultiplier = 1.0f;

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DefaultSoundCues")
	float FootprintPitchMultiplier = 1.0f;

	/** * 忽略碰撞 */
	UPROPERTY(BlueprintReadWrite, Category = "DefaultSoundCues")
	TArray<TObjectPtr<AActor>> ActorsToIgnore;

	/** * 脚步音效组件 */
	UPROPERTY(BlueprintReadWrite, Category = "DefaultSoundCues")
	TArray<TObjectPtr<UAudioComponent>> FootprintAudioComponents;

	/** * 默认脚步声音组 */
	UPROPERTY(BlueprintReadWrite, Category = "DefaultSoundCues")
	TArray<TObjectPtr<USoundCue>> DefaultFootprintSoundCue;

	/** * 默认脚步声音组,声音代表左右脚步,或多种 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DefaultSoundCues")
	TArray<TSoftObjectPtr<USoundCue>> SoftDefaultFootprintSoundCues;

	/** * 自定义脚步声音组 */
	UPROPERTY(BlueprintReadWrite, Category = "DefaultSoundCues")
	TArray<TObjectPtr<USoundCue>> CustomFootprintSoundCue;

	/** * 自定义脚步声音组,用于顶替默认的声音,如自定义是高跟鞋的音效 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomSoundCues")
	TArray<TSoftObjectPtr<USoundCue>> SoftCustomFootprintSoundCues;


	/** * 默认跳跃声音组 */
	UPROPERTY(BlueprintReadWrite, Category = "DefaultSoundCues")
	TArray<TObjectPtr<USoundCue>> DefaultJumpSoundCue;

	/** * 默认跳跃声音组,表示不同的跳跃,轻松的跳跃,负重的跳跃 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DefaultSoundCues")
	TArray<TSoftObjectPtr<USoundCue>> SoftDefaultJumpSoundCues;

	/** * 自定义跳跃声音组 */
	UPROPERTY(BlueprintReadWrite, Category = "DefaultSoundCues")
	TArray<TObjectPtr<USoundCue>> CustomJumpSoundCue;

	/** * 自定义跳跃声音组 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomSoundCues")
	TArray<TSoftObjectPtr<USoundCue>> SoftCustomJumpSoundCues;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual void SetFootprintAudioComponents(TArray<UAudioComponent*> InFootprintAudioComponents);

	/** * */
	virtual USoundCue* GetSoundCuesIndex(TArray<TSoftObjectPtr<USoundCue>>& InSoftSoundCues, TArray<TObjectPtr<USoundCue>>& InSoundCue, int InIndex = 0);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual void SetSoftDefaultFootprintSoundCues(TArray<TSoftObjectPtr<USoundCue>> InSoftDefaultFootprintSoundCues);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual USoundCue* GetDefaultFootprintSoundCues(int InIndex);


	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual void SetSoftCustomFootprintSoundCues(TArray<TSoftObjectPtr<USoundCue>> InSoftCustomFootprintSoundCues);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual USoundCue* GetCustomFootprintSoundCues(int InIndex);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual USoundCue* GetFootprintSoundCues(int InIndex);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual bool PlayFootprintSoundCue(int InIndex = 0, ECollisionPhysicalMaterialClassEnum InCollisionPhysicalMaterialClassEnum = ECollisionPhysicalMaterialClassEnum::Dirt, float VolumeMultiplier = 1.0f, float PitchMultiplier = 1.0f, float StartTime = 0.0f);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual void SetSoftDefaultJumpSoundCues(TArray<TSoftObjectPtr<USoundCue>> InSoftDefaultJumpSoundCues);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual USoundCue* GetDefaultJumpSoundCues(int InIndex);


	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual void SetSoftCustomJumpSoundCues(TArray<TSoftObjectPtr<USoundCue>> InSoftCustomJumpSoundCues);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual USoundCue* GetCustomJumpSoundCues(int InIndex);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual USoundCue* GetJumpSoundCues(int InIndex);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual UAudioComponent* SpawnFootprintAudioComponent(int InIndex);
		
};
