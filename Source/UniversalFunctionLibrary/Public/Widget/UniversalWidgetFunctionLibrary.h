// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/Widget.h"


#include "UniversalWidgetFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class UNIVERSALFUNCTIONLIBRARY_API UUniversalWidgetFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UUniversalWidgetFunctionLibrary();
	/** 控件 */

	/** 获取父类位置 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static FVector2D GetParentLocation(UWidget* Widget);

	/** 获取所有父类位置 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static FVector2D GetAllParentLocation(UWidget* Widget);

	/** 设置Widget控件位置 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static void SetWidgetPosition(UWidget* Widget, const FVector2D& Position);

	/** 设置Image资源 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static void SetWidgetSize(UWidget* Widget, const FVector2D& Size, USizeBox* SizeBox = nullptr);

	/** 设置Image资源 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static void SetImageResource(UImage* Image, UObject* Resource, const FString& ParameterName = "MaterialTexture");

	/** 获取鼠标位置 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static FVector2D GetMousePositionOnViewport(UObject* WorldContextObject, bool bViewportScale = false);

	/** 获取视口位置 */
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
	static FVector2D GetViewportSize(UObject* WorldContextObject);
};
