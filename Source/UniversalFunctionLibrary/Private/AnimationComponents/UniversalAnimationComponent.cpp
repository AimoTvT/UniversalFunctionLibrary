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



#include "AnimationComponents/UniversalAnimationComponent.h"

// Sets default values for this component's properties
UUniversalAnimationComponent::UUniversalAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);  /** * 开启复制 */
	ComponentTags.Add(TEXT("AnimComponent"));
	// ...
}


// Called when the game starts
void UUniversalAnimationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	if (GetOwner() && Cast<APawn>(GetOwner()) && Cast<APawn>(GetOwner())->GetController())
	{
		bLocalController = Cast<APawn>(GetOwner())->GetController()->IsLocalController();
	}

}


// Called every frame
void UUniversalAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

