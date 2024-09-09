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

#include "Buffs/BuffActorComponent.h"
#include "Buffs/BuffControllerComponent.h"

// Sets default values for this component's properties
UBuffActorComponent::UBuffActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);  /** * 开启复制 */
	// ...
}


// Called when the game starts
void UBuffActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	if (GetOwner())
	{
		UActorComponent* ActorComponent = GetOwner()->GetComponentByClass(UBuffControllerComponent::StaticClass());
		if (ActorComponent)
		{
			UBuffControllerComponent* BuffControllerComponent = Cast<UBuffControllerComponent>(ActorComponent);
			if (BuffControllerComponent)
			{
				BuffControllerComponent->AddBuffComponent(this, false);
			}
		}
		if (GetOwner()->HasAuthority())
		{
			if (DestroyTimeMax > 0.0f && GetWorld()->GetTimerManager().IsTimerActive(BuffTimerHandle) == false)
			{
				GetWorld()->GetTimerManager().SetTimer(BuffTimerHandle, this, &UBuffActorComponent::BuffTimerHandle_Event, DestroyTimeInterval, true); /** * 初始化设置定时器 */
			}
		}
	}
}


void UBuffActorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(UBuffActorComponent, Name, COND_None);
	DOREPLIFETIME_CONDITION(UBuffActorComponent, HUDVisible, COND_None);
	DOREPLIFETIME_CONDITION(UBuffActorComponent, DestroyTime, COND_None);
	DOREPLIFETIME_CONDITION(UBuffActorComponent, DestroyTimeMax, COND_None);

	//SetCustomIsActiveOverride();
}



void UBuffActorComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);
	OnComponentDestroy.Broadcast(this, bDestroyingHierarchy);
}


// Called every frame
void UBuffActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}

void UBuffActorComponent::OnRep_Name()
{
	OnComponentName.Broadcast(this, Name);
}

void UBuffActorComponent::OnRep_HUDVisible()
{
	OnComponentHUDVisible.Broadcast(this, HUDVisible);
}

void UBuffActorComponent::OnRep_DestroyTime()
{
	OnComponentDestroyTime.Broadcast(this, DestroyTime);
}

void UBuffActorComponent::SetName(const FName& InName)
{
	if (Name != InName)
	{
		Name = InName;
		OnRep_Name();
	}
}

void UBuffActorComponent::SetHUDVisible(uint8 InHUDVisible)
{
	if (HUDVisible != InHUDVisible)
	{
		HUDVisible = InHUDVisible;
		OnRep_HUDVisible();
	}
}

void UBuffActorComponent::SetDestroyTime(float InDestroyTime)
{
	if (DestroyTime != InDestroyTime)
	{
		DestroyTime = InDestroyTime;
		OnRep_DestroyTime();
	}
}

void UBuffActorComponent::AddDestroyTime(float InDestroyTime)
{
	SetDestroyTime(DestroyTime + InDestroyTime);
}

void UBuffActorComponent::BuffTimerHandle_Event()
{
	if (DestroyTime > 0.0f)
	{
		AddDestroyTime(DestroyTimeInterval * -1.0f);
	}
	else
	{
		if (GetWorld()->GetTimerManager().IsTimerActive(BuffTimerHandle))
		{
			GetWorld()->GetTimerManager().ClearTimer(BuffTimerHandle);
		}
		DestroyComponent();
	}
}

