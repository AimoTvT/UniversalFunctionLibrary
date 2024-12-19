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
#include "Net/UnrealNetwork.h" 
#include "Components/ActorComponent.h"

#include "BuffActorComponent.generated.h"

class UBuffWidget;

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNIVERSALFUNCTIONLIBRARY_API UBuffActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBuffActorComponent();

	/** * 名字 */
	UPROPERTY(ReplicatedUsing = OnRep_Name, EditAnywhere, BlueprintReadWrite, Category = "Buff")
	FName Name;

	/** * 优先级 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buff")
	uint8 Priority = 0;

	/** * HUD可视 */
	UPROPERTY(ReplicatedUsing = OnRep_HUDVisible, EditAnywhere, BlueprintReadWrite, Category = "Buff")
	uint8 HUDVisible = 1;

	/** * 优先级 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buff")
	uint8 Priority1 = 0;

	/** * 优先级 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buff")
	uint8 Priority2 = 0;

	/** * 剩余破坏的时间 */
	UPROPERTY(ReplicatedUsing = OnRep_DestroyTime, EditAnywhere, BlueprintReadWrite, Category = "Buff")
	float DestroyTime;

	/** * 最大破坏时间,0.0不破坏 */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Buff")
	float DestroyTimeMax;

	/** * 破坏时间计算间隔 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buff")
	float DestroyTimeInterval = 0.1f;

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buff", meta = (DisplayThumbnail = true, AllowedClasses = "/Script/Engine.Texture,/Script/Engine.MaterialInterface,/Script/Engine.SlateTextureAtlasInterface", DisallowedClasses = "/Script/MediaAssets.MediaTexture"))
	TSoftObjectPtr<UObject> IconSoftObject = TSoftObjectPtr<UObject>(FString(TEXT("/Script/Engine.Texture2D'/ResourcesExpansions/Textures/Touch/T_NL.T_NL'")));

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buff")
	TSoftClassPtr<UBuffWidget> BuffWidget = TSoftClassPtr<UBuffWidget>(FString(TEXT("/Script/UMGEditor.WidgetBlueprint'/UniversalFunctionLibrary/Buffs/Widgets/BP_BuffWidget.BP_BuffWidget_C'")));


	/** * 定时器 */
	UPROPERTY(BlueprintReadWrite, Category = "ItemActor")
	FTimerHandle BuffTimerHandle;



	/** * * 组件删除委托 */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBuffActorComponentDestroyedSignature, UBuffActorComponent*, InBuffActorComponent, bool, bDestroyingHierarchy);

	/** * *  */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FComponentName, UBuffActorComponent*, InBuffActorComponent, const FName&, InName);

	/** * *  */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FComponentHUDVisible, UBuffActorComponent*, InBuffActorComponent, uint8, InHUDVisible);

	/** * *  */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FComponentDestroyTime, UBuffActorComponent*, InBuffActorComponent, float, InDestroyTime);

	/** * * 组件删除委托 */
	UPROPERTY(BlueprintAssignable, Category = "Component|On")
	FBuffActorComponentDestroyedSignature OnBuffComponentDestroyed;

	/** * *  */
	UPROPERTY(BlueprintAssignable, Category = "Component|On")
	FComponentName OnComponentName;

	/** * *  */
	UPROPERTY(BlueprintAssignable, Category = "Component|On")
	FComponentHUDVisible OnComponentHUDVisible;

	/** * *  */
	UPROPERTY(BlueprintAssignable, Category = "Component|On")
	FComponentDestroyTime OnComponentDestroyTime;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	/** * * 重写同步策略 */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void OnRep_Name();

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void OnRep_HUDVisible();

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void OnRep_DestroyTime();

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void SetName(const FName& InName);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void SetHUDVisible(uint8 InHUDVisible = 1);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void SetDestroyTime(float InDestroyTime);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void AddDestroyTime(float InDestroyTime);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void BuffTimerHandle_Event();


};
