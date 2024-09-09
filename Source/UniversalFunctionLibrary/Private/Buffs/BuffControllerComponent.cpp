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
		TArray<UActorComponent*> ActorComponents;
		GetOwner()->GetComponents(UBuffControllerComponent::StaticClass(), ActorComponents, false);
		for (size_t i = 0; i < ActorComponents.Num(); i++)
		{
			if (ActorComponents[i] && Cast<UBuffActorComponent>(ActorComponents[i]))
			{
				AddBuffComponent(Cast<UBuffActorComponent>(ActorComponents[i]), false);
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
			if (InBuffActorComponent->OnComponentDestroy.IsAlreadyBound(this, &UBuffControllerComponent::ComponentDestroy_Event))
			{
				InBuffActorComponent->OnComponentDestroy.RemoveDynamic(this, &UBuffControllerComponent::ComponentDestroy_Event);
			}
		}
		else
		{
			BuffActorComponents.Add(InBuffActorComponent);
			OnBuffActorComponent.Broadcast(InBuffActorComponent, 1);
			if (!InBuffActorComponent->OnComponentDestroy.IsAlreadyBound(this, &UBuffControllerComponent::ComponentDestroy_Event))
			{
				InBuffActorComponent->OnComponentDestroy.AddDynamic(this, &UBuffControllerComponent::ComponentDestroy_Event);
			}
		}
	}
}


void UBuffControllerComponent::ComponentDestroy_Event(UBuffActorComponent* InBuffActorComponent, bool bDestroyingHierarchy)
{
	if (InBuffActorComponent)
	{
		AddBuffComponent(InBuffActorComponent, true);
	}
}