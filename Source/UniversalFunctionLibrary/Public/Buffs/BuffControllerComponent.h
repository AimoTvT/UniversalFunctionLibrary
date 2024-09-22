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
#include "BuffControllerComponent.generated.h"


class UBuffActorComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNIVERSALFUNCTIONLIBRARY_API UBuffControllerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBuffControllerComponent();

	UPROPERTY(BlueprintReadWrite, Category = "Buff")
	TArray<TObjectPtr<UBuffActorComponent>> BuffActorComponents;


	/** * * 委托宏2个输入 */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBuffActorComponent, UBuffActorComponent*, InBuffActorComponent, uint8, Mode);

	/** * * 碰撞 */
	UPROPERTY(BlueprintAssignable, Category = "Buff")
	FBuffActorComponent OnBuffActorComponent;

	/** * * 组件删除委托 */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBuffControllerComponentDestroyed, UBuffControllerComponent*, InBuffControllerComponent, bool, bDestroyingHierarchy);

	/** * * 组件删除委托 */
	UPROPERTY(BlueprintAssignable, Category = "Component|On")
	FBuffControllerComponentDestroyed OnBuffControllerComponentDestroyed;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void AddBuffComponent(UBuffActorComponent* InBuffActorComponent, bool bRemove = false);


	/** * */
	UFUNCTION(BlueprintCallable, Category = "Buff|Function")
	virtual void BuffComponentDestroy_Event(UBuffActorComponent* InBuffActorComponent, bool bDestroyingHierarchy);

		
};
