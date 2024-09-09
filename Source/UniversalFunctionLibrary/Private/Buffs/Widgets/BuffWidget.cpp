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


#include "Buffs/Widgets/BuffWidget.h"

void UBuffWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (BuffActorComponent)
	{
		SetBuffActorComponent(BuffActorComponent, true);
	}
}

void UBuffWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UBuffWidget::SetBuffActorComponent(UBuffActorComponent* InBuffActorComponent, bool bForceSet)
{
	if (bForceSet)
	{
		BuffActorComponent = nullptr;
	}
	if (BuffActorComponent != InBuffActorComponent)
	{
		if (BuffActorComponent)
		{
			BuffActorComponent->OnComponentName.RemoveDynamic(this, &UBuffWidget::OnComponentName_Event);
			BuffActorComponent->OnComponentHUDVisible.RemoveDynamic(this, &UBuffWidget::OnComponentHUDVisible_Event);
			BuffActorComponent->OnComponentDestroyTime.RemoveDynamic(this, &UBuffWidget::OnComponentDestroyTime_Event);
		}
		BuffActorComponent = InBuffActorComponent;
		if (BuffActorComponent)
		{
			BuffActorComponent->OnComponentName.AddDynamic(this, &UBuffWidget::OnComponentName_Event);
			BuffActorComponent->OnComponentHUDVisible.AddDynamic(this, &UBuffWidget::OnComponentHUDVisible_Event);
			BuffActorComponent->OnComponentDestroyTime.AddDynamic(this, &UBuffWidget::OnComponentDestroyTime_Event);
		}
	}
}

void UBuffWidget::OnComponentName_Event(UBuffActorComponent* InBuffActorComponent, const FName& InName)
{
	BPOnComponentName_Event(InBuffActorComponent, InName);
}

void UBuffWidget::OnComponentHUDVisible_Event(UBuffActorComponent* InBuffActorComponent, uint8 InHUDVisible)
{
	BPOnComponentHUDVisible_Event(InBuffActorComponent, InHUDVisible);
}

void UBuffWidget::OnComponentDestroyTime_Event(UBuffActorComponent* InBuffActorComponent, float InDestroyTime)
{
	BPOnComponentDestroyTime_Event(InBuffActorComponent, InDestroyTime);
}

void UBuffWidget::BPOnComponentName_Event_Implementation(UBuffActorComponent* InBuffActorComponent, const FName& InName)
{
}

void UBuffWidget::BPOnComponentHUDVisible_Event_Implementation(UBuffActorComponent* InBuffActorComponent, uint8 InHUDVisible)
{
}

void UBuffWidget::BPOnComponentDestroyTime_Event_Implementation(UBuffActorComponent* InBuffActorComponent, float InDestroyTime)
{
}
