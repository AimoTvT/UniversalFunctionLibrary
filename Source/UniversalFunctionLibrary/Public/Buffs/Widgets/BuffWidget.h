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
#include "Blueprint/UserWidget.h"
#include "Buffs/BuffActorComponent.h"


#include "BuffWidget.generated.h"


/**
 * 
 */
UCLASS()
class UNIVERSALFUNCTIONLIBRARY_API UBuffWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** *  */
	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true), Category = "Item|Variable")
	TObjectPtr<UBuffActorComponent> BuffActorComponent;



public:

	virtual void NativeConstruct() override;

	virtual void NativeDestruct() override;

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void SetBuffActorComponent(UBuffActorComponent* InBuffActorComponent, bool bForceSet = false);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void OnComponentName_Event(UBuffActorComponent* InBuffActorComponent, const FName& InName);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void OnComponentHUDVisible_Event(UBuffActorComponent* InBuffActorComponent, uint8 InHUDVisible);

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void OnComponentDestroyTime_Event(UBuffActorComponent* InBuffActorComponent, float InDestroyTime);

	/** * 蓝图专用运行, */
	UFUNCTION(BlueprintNativeEvent, Category = "Buff|Function")
	void BPOnComponentName_Event(UBuffActorComponent* InBuffActorComponent, const FName& InName);

	/** * 蓝图专用运行, */
	UFUNCTION(BlueprintNativeEvent, Category = "Buff|Function")
	void BPOnComponentHUDVisible_Event(UBuffActorComponent* InBuffActorComponent, uint8 InHUDVisible);

	/** * 蓝图专用运行, */
	UFUNCTION(BlueprintNativeEvent, Category = "Buff|Function")
	void BPOnComponentDestroyTime_Event(UBuffActorComponent* InBuffActorComponent, float InDestroyTime);


};
