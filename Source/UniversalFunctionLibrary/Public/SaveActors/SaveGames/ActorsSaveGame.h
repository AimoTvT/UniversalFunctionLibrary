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
#include "GameFramework/SaveGame.h"
#include "Config/UniversalStruct.h"


#include "ActorsSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class UNIVERSALFUNCTIONLIBRARY_API UActorsSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	/** * 保存标签名字 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorsSaveGame")
	FName SaveTagName = TEXT("SaveGame");

	/** * Actor数据和序列化保存 */
	UPROPERTY(BlueprintReadWrite, Category = "ActorsSaveGame")
	TArray<FActorSaveData> ActorSaveData;


public:
	/** *  */
	UFUNCTION(BlueprintCallable, Category = "Player|Function")
	virtual int SaveTagActors(FName InSaveTagName = TEXT("SaveGame"));

	/** *  */
	UFUNCTION(BlueprintCallable, Category = "Player|Function")
	virtual int SaveActors(const TArray<AActor*>& InAllActors);

	/** *  */
	UFUNCTION(BlueprintCallable, Category = "Player|Function")
	virtual int LoadActors(bool bRemoveSaveActor = false);




};
