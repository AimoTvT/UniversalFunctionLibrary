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



#include "SaveActors/SaveActor.h"

// Sets default values
ASaveActor::ASaveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Tags.Add(SaveTagName);
}

// Called when the game starts or when spawned
void ASaveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASaveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ASaveActor::IsSaveActor()
{
	return Tags.Find(SaveTagName) != -1;
}

void ASaveActor::SetSaveActor(bool bSave)
{
	if (bSave)
	{
		Tags.AddUnique(SaveTagName);
		return;
	}
	Tags.Remove(SaveTagName);
	return;
}
