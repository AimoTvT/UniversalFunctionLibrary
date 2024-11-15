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
#include "GameFramework/Actor.h"
#include "SaveActor.generated.h"

UCLASS()
class UNIVERSALFUNCTIONLIBRARY_API ASaveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASaveActor();

	/** * 保存标签名字,记得一并改动Tags的同标签 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGame")
	FName SaveTagName = TEXT("SaveGame");

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "SaveGame|Function")
	virtual bool IsSaveActor();

	UFUNCTION(BlueprintCallable, Category = "SaveGame|Function")
	virtual void SetSaveActor(bool bSave);

};