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


#include "Buffs/BuffControllerComponent.h"
#include "Buffs/BuffActorComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UBuffControllerComponent::UBuffControllerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UBuffControllerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	if (GetOwner())
	{
		TArray<UBuffActorComponent*> TBuffActorComponents;
		GetOwner()->GetComponents(UBuffActorComponent::StaticClass(), TBuffActorComponents, false);
		for (size_t i = 0; i < TBuffActorComponents.Num(); i++)
		{
			if (TBuffActorComponents[i])
			{
				AddBuffComponent(TBuffActorComponents[i], false);
			}
		}
	}
}



void UBuffControllerComponent::AddBuffComponent(UBuffActorComponent* InBuffActorComponent, bool bRemove)
{
	if (InBuffActorComponent)
	{
		if (BuffActorComponents.Find(InBuffActorComponent) != -1 && bRemove)
		{
			BuffActorComponents.Remove(InBuffActorComponent);
			OnBuffActorComponent.Broadcast(InBuffActorComponent, 0);
			if (InBuffActorComponent->OnBuffComponentDestroyed.IsAlreadyBound(this, &UBuffControllerComponent::BuffComponentDestroy_Event))
			{
				InBuffActorComponent->OnBuffComponentDestroyed.RemoveDynamic(this, &UBuffControllerComponent::BuffComponentDestroy_Event);
			}
		}
		else
		{
			BuffActorComponents.Add(InBuffActorComponent);
			OnBuffActorComponent.Broadcast(InBuffActorComponent, 1);
			if (!InBuffActorComponent->OnBuffComponentDestroyed.IsAlreadyBound(this, &UBuffControllerComponent::BuffComponentDestroy_Event))
			{
				InBuffActorComponent->OnBuffComponentDestroyed.AddDynamic(this, &UBuffControllerComponent::BuffComponentDestroy_Event);
			}
		}
	}
}


void UBuffControllerComponent::BuffComponentDestroy_Event(UBuffActorComponent* InBuffActorComponent, bool bDestroyingHierarchy)
{
	if (InBuffActorComponent)
	{
		AddBuffComponent(InBuffActorComponent, true);
	}
}