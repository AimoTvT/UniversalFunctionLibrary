/**
* Copyright: Aimo_皑墨
* Open source protocol: MIT License
;* Open Source Date: Jun 5, 2023
* BiLiBiLi (哔哩哔哩) address: https://space.bilibili.com/146962867
* making address: https://github.com/AimoTvT/UniversalFunctionLibrary
* We welcome the contributions of powerful movers and movers to join this plugin
* Build powerful plugins together!!
*
* 版权所有权: Aimo_皑墨
* 开源协议: MIT License
* 开源时间: 2023年6月29日
* BiLiBiLi(哔哩哔哩)地址: https://space.bilibili.com/146962867
* GitHub地址: https://github.com/AimoTvT/UniversalFunctionLibrary
* 欢迎有实力的大佬/萌新加入本插件的贡献
* 一起打造强大的插件!!!
*/

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/Widget.h"


#include "UniversalWidgetFunctionLibrary.generated.h"

/** *
 *
 */
UCLASS()
class UNIVERSALFUNCTIONLIBRARY_API UUniversalWidgetFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UUniversalWidgetFunctionLibrary();
	/** * 控件 */

	/** * 获取父类位置 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static FVector2D GetParentLocation(UWidget* Widget);

	/** * 获取所有父类位置 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static FVector2D GetAllParentLocation(UWidget* Widget);

	/** * 设置Widget控件位置 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static void SetWidgetPosition(UWidget* Widget, const FVector2D& Position);

	/** * 设置Image资源 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static void SetWidgetSize(UWidget* Widget, const FVector2D& InSize, USizeBox* SizeBox = nullptr);

	/** * 设置Image资源 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static void SetImageResource(UImage* Image, UObject* Resource, const FString& ParameterName = "MaterialTexture");

	/** * 获取鼠标位置 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static FVector2D GetMousePositionOnViewport(UObject* WorldContextObject, bool bViewportScale = false);

	/** * 获取视口位置 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static FVector2D GetViewportSize(UObject* WorldContextObject);

	/** * 字符串转换 SoftWidgetObjectPtr */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
	static TSoftClassPtr<UWidget> StringCastTSoftWidgetClassPtr(const FString& PathString);

	/** * 字符串转换 SoftUserWidgetObjectPtr */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
	static TSoftClassPtr<UUserWidget> StringCastTSoftUserWidgetClassPtr(const FString& PathString);

};
