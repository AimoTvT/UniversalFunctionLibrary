// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/UniversalWidgetFunctionLibrary.h"
#include "Components/PanelWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "UMG/Public/Components/Image.h"
#include "UMG/Public/Components/SizeBox.h"
#include "Engine/Classes/Materials/MaterialInstanceDynamic.h"

UUniversalWidgetFunctionLibrary::UUniversalWidgetFunctionLibrary()
{
}

FVector2D UUniversalWidgetFunctionLibrary::GetParentLocation(UWidget* Widget)
{
	if (Widget)
	{
		return Widget->GetParent()->GetPaintSpaceGeometry().GetLocalPositionAtCoordinates({ 0.0,0.0 });
	}
	return FVector2D();
}

FVector2D UUniversalWidgetFunctionLibrary::GetAllParentLocation(UWidget* Widget)
{
	FVector2D Vector2D = { 0.0,0.0 };
	if (Widget)
	{
		Vector2D = Widget->GetPaintSpaceGeometry().GetLocalPositionAtCoordinates({ 0.0,0.0 });
		UPanelWidget* PanelWidget = Widget->GetParent();
		if (PanelWidget)
		{
			Vector2D += PanelWidget->GetPaintSpaceGeometry().GetLocalPositionAtCoordinates({ 0.0,0.0 });
			while (PanelWidget)
			{
				Vector2D += PanelWidget->GetPaintSpaceGeometry().GetLocalPositionAtCoordinates({ 0.0,0.0 });
				PanelWidget = PanelWidget->GetParent();
			}
		}
	}
	return Vector2D;
}

void UUniversalWidgetFunctionLibrary::SetWidgetPosition(UWidget* Widget, FVector2D Position)
{
	if (Widget->Slot)
	{
		UCanvasPanelSlot* CanvasPanelSlot = Cast<UCanvasPanelSlot>(Widget->Slot);
		if (CanvasPanelSlot)
		{
			CanvasPanelSlot->SetPosition(Position);
		}
	}
}

void UUniversalWidgetFunctionLibrary::SetWidgetSize(UWidget* Widget, FVector2D Size, USizeBox* SizeBox)
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

void UUniversalWidgetFunctionLibrary::SetImageResource(UImage* Image, UObject* Resource, FName ParameterName)
{
	if (Image && Resource)
	{
		if (Cast<UTexture2D>(Resource))
		{
			UMaterialInstanceDynamic* MaterialInstanceDynamic = Image->GetDynamicMaterial();
			if (MaterialInstanceDynamic)
			{
				MaterialInstanceDynamic->SetTextureParameterValue(ParameterName, Cast<UTexture2D>(Resource));
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