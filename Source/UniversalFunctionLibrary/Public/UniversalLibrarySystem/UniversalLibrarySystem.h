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
#include "UObject/NoExportTypes.h"
#include "UniversalLibrarySystem.generated.h"

/**
 * 
 */
UCLASS()
class UNIVERSALFUNCTIONLIBRARY_API UUniversalLibrarySystem : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, DisplayName = "GUniversalLibrarySystem")
	static UUniversalLibrarySystem* Get();

	/** * * 委托宏1个输入 */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUniversalGameState, uint8, Mode);

	/** * * 碰撞 */
	UPROPERTY(BlueprintAssignable, Category = "ItemActor|On")
	FUniversalGameState OnGameState;

public:
	
	/** * 开始游戏 */
	virtual void PlayGame(bool bPlay = true);


};
