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


#include "Widget/UniversalWidgetFunctionLibrary.h"
#include "Components/PanelWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Engine/Texture2D.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Materials/MaterialInstanceDynamic.h"

UUniversalWidgetFunctionLibrary::UUniversalWidgetFunctionLibrary()
{
}

FVector2D UUniversalWidgetFunctionLibrary::GetParentLocation(UWidget* Widget)
{
	if (Widget)
	{
		return Widget->GetPaintSpaceGeometry().GetLocalPositionAtCoordinates({ 0.0,0.0 });
	}
	return FVector2D();
}

FVector2D UUniversalWidgetFunctionLibrary::GetAllParentLocation(UWidget* Widget)
{
	FVector2D Vector2D = FVector2D(0.0f, 0.0f);
	while (Widget)
	{
		Vector2D += Widget->GetPaintSpaceGeometry().GetLocalPositionAtCoordinates({ 0.0,0.0 });
		Widget = Widget->GetParent(); //这个报错可能是编辑器判断bug,不影响编译和使用
	}
	return Vector2D;
}

void UUniversalWidgetFunctionLibrary::SetWidgetPosition(UWidget* Widget, const FVector2D& Position)
{
	if (Widget)
	{
		if (Widget->Slot)
		{
			UCanvasPanelSlot* CanvasPanelSlot = Cast<UCanvasPanelSlot>(Widget->Slot);
			if (CanvasPanelSlot)
			{
				CanvasPanelSlot->SetPosition(Position);
			}
		}
		else
		{
			UUserWidget* UserWidget = Cast<UUserWidget>(Widget);
			if (UserWidget)
			{
				UserWidget->SetPositionInViewport(Position);
			}
		}
	}
}

void UUniversalWidgetFunctionLibrary::SetWidgetSize(UWidget* Widget, const FVector2D& InSize, USizeBox* SizeBox)
{
	if (Widget->Slot)
	{
		UCanvasPanelSlot* CanvasPanelSlot = Cast<UCanvasPanelSlot>(Widget->Slot);
		if (CanvasPanelSlot)
		{
			CanvasPanelSlot->SetSize(InSize);
			return;
		}
	}
	if (SizeBox)
	{
		SizeBox->SetWidthOverride(InSize.X);
		SizeBox->SetHeightOverride(InSize.Y);
		return;
	}
}

void UUniversalWidgetFunctionLibrary::SetImageResource(UImage* Image, UObject* Resource, const FString& ParameterName)
{
	if (Image && Resource)
	{
		if (Cast<UTexture2D>(Resource))
		{
			UMaterialInstanceDynamic* MaterialInstanceDynamic = Image->GetDynamicMaterial();
			if (MaterialInstanceDynamic)
			{
				MaterialInstanceDynamic->SetTextureParameterValue(*ParameterName, Cast<UTexture2D>(Resource));
			}
			else
			{
				Image->SetBrushFromTexture(Cast<UTexture2D>(Resource));
			}
		}
		if (Cast<UMaterialInstance>(Resource))
		{
			Image->SetBrushFromMaterial(Cast<UMaterialInstance>(Resource));
		}
	}
}

FVector2D UUniversalWidgetFunctionLibrary::GetMousePositionOnViewport(UObject* WorldContextObject, bool bViewportScale)
{
	if (bViewportScale)
	{
		return  UWidgetLayoutLibrary::GetMousePositionOnViewport(WorldContextObject) * UWidgetLayoutLibrary::GetViewportScale(WorldContextObject);
	}
	return UWidgetLayoutLibrary::GetMousePositionOnViewport(WorldContextObject);
}

FVector2D UUniversalWidgetFunctionLibrary::GetViewportSize(UObject* WorldContextObject)
{
	return UWidgetLayoutLibrary::GetViewportSize(WorldContextObject);
}

TSoftClassPtr<UWidget> UUniversalWidgetFunctionLibrary::StringCastTSoftWidgetClassPtr(const FString& PathString)
{
	if (PathString.Len() > 22 && PathString.StartsWith(TEXT("/Script/Engine.Blueprint")) && PathString.EndsWith(TEXT("_C'")) == false)
	{
		return TSoftClassPtr<UWidget>(StringCastTSoftWidgetClassPtr(PathString.Mid(0, PathString.Len() - 1) + TEXT("_C'")));
	}
	return TSoftClassPtr<UWidget>(PathString);
}

TSoftClassPtr<UUserWidget> UUniversalWidgetFunctionLibrary::StringCastTSoftUserWidgetClassPtr(const FString& PathString)
{
	if (PathString.Len() > 22 && PathString.StartsWith(TEXT("/Script/Engine.Blueprint")) && PathString.EndsWith(TEXT("_C'")) == false)
	{
		return TSoftClassPtr<UUserWidget>(StringCastTSoftUserWidgetClassPtr(PathString.Mid(0, PathString.Len() - 1) + TEXT("_C'")));
	}
	return TSoftClassPtr<UUserWidget>(PathString);
}

