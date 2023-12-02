// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/UniversalWidgetFunctionLibrary.h"
#include "Components/PanelWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "UMG/Public/Components/Image.h"
#include "UMG/Public/Components/SizeBox.h"
#include "UMG/public/Blueprint/WidgetLayoutLibrary.h"
#include "Engine/Classes/Materials/MaterialInstanceDynamic.h"

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
	FVector2D Vector2D = { 0.0,0.0 };
	while (Widget)
	{
		Vector2D += Widget->GetPaintSpaceGeometry().GetLocalPositionAtCoordinates({ 0.0,0.0 });
		Widget = Widget->GetParent();
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

void UUniversalWidgetFunctionLibrary::SetWidgetSize(UWidget* Widget, const FVector2D& Size, USizeBox* SizeBox)
{
	if (Widget->Slot)
	{
		UCanvasPanelSlot* CanvasPanelSlot = Cast<UCanvasPanelSlot>(Widget->Slot);
		if (CanvasPanelSlot)
		{
			CanvasPanelSlot->SetSize(Size);
		}
	}
	if (SizeBox)
	{
		SizeBox->SetWidthOverride(Size.X);
		SizeBox->SetHeightOverride(Size.Y);
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

FVector2D UUniversalWidgetFunctionLibrary::GetMousePositionOnViewport(UObject* WorldContextObject)
{
	return UWidgetLayoutLibrary::GetMousePositionOnViewport(WorldContextObject);
}

FVector2D UUniversalWidgetFunctionLibrary::GetViewportSize(UObject* WorldContextObject)
{
	return UWidgetLayoutLibrary::GetViewportSize(WorldContextObject);
}