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



#include "UniversalFunctionLibrarys.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h" //游戏静态库
#include "Kismet/KismetMathLibrary.h" //官方函数库
#include "Components/ActorComponent.h"
#include "Kismet/KismetSystemLibrary.h" //官方函数库
#include "Runtime/Engine/Public/DelayAction.h" //延迟的函数库
#include "UniversalFunctionLibrary/Public/Config/UniversalStruct.h"
#include "Components/DecalComponent.h"
#include "Materials/MaterialInterface.h"
#include "AssetRegistry/AssetRegistryModule.h"



UUniversalFunctionLibrarys::UUniversalFunctionLibrarys()
{
	
}


const TCHAR* UUniversalFunctionLibrarys::ESetCmdToString(ESetCmd InSetCmd)
{
	switch (InSetCmd)
	{
	case ESetCmd::Set:
		return TEXT("Set");
	case ESetCmd::SetAll:
		return TEXT("SetAll");
	case ESetCmd::Add:
		return TEXT("Add");
	case ESetCmd::AddUnique:
		return TEXT("AddUnique");
	case ESetCmd::Remove:
		return TEXT("Remove");
	case ESetCmd::RemoveAll:
		return TEXT("RemoveAll");
	case ESetCmd::Swap:
		return TEXT("Swap");
	case ESetCmd::SwapOther:
		return TEXT("SwapOther");
	}
	ensure(false);
	return TEXT("Unknown");
}

TSoftClassPtr<UObject> UUniversalFunctionLibrarys::StringCastTSoftClassPtr(const FString& PathString)
{
	if (PathString.Len() > 22 && PathString.StartsWith(TEXT("/Script/Engine.Blueprint")) && PathString.EndsWith(TEXT("_C'")) == false)
	{
		return TSoftClassPtr<UObject>(StringCastTSoftClassPtr(PathString.Mid(0, PathString.Len() - 1) + TEXT("_C'")));
	}
	return TSoftClassPtr<UObject>(PathString);
}

TSoftObjectPtr<UObject> UUniversalFunctionLibrarys::StringCastTSoftObjectPtr(const FString& PathString)
{
	return TSoftObjectPtr<UObject>(PathString);
}

FSoftObjectPath UUniversalFunctionLibrarys::StringCastFSoftObjectPath(const FString& PathString)
{
	return FSoftObjectPath(PathString);
}

UClass* UUniversalFunctionLibrarys::StringLoadClassAsset(const FString& PathString)
{
	TSoftClassPtr<UObject> SoftClassPtr = StringCastTSoftClassPtr(PathString);
	return SoftClassPtr.IsNull() && SoftClassPtr.IsValid() ? SoftClassPtr.Get() : SoftClassPtr.LoadSynchronous();
}

UObject* UUniversalFunctionLibrarys::StringLoadObjectAsset(const FString& PathString)
{
	TSoftObjectPtr<UObject> SoftObjectPtr = StringCastTSoftObjectPtr(PathString);
	return SoftObjectPtr.IsNull() && SoftObjectPtr.IsValid() ? SoftObjectPtr.Get() : SoftObjectPtr.LoadSynchronous();
}

UClass* UUniversalFunctionLibrarys::AssetDataLoadClass(const FAssetData& AssetData)
{
	if (AssetData.IsValid())
	{
		if (AssetData.AssetClassPath.ToString() == TEXT("/Script/Engine.Blueprint"))
		{
		}
		else
		{

		}
	}
	return nullptr;
}


int UUniversalFunctionLibrarys::FindStringParseIndex(const FString& SourceString, const FString& FindString, const FString& SensitiveString, int Index)
{
	int OnIndex = -1;
	int IgnoreIndex = 0;
	for (size_t i = Index; i < SourceString.Len(); i++)
	{
		if (!SensitiveString.Equals("") && SensitiveString == SourceString.Mid(i, 1))
		{
			IgnoreIndex++;
			continue;
		}
		if (FindString == SourceString.Mid(i, 1))
		{
			if (IgnoreIndex)
			{
				IgnoreIndex--;
				continue;
			}
			else
			{
				return i;
			}
		}
	}
	return -1;
}

TArray<FString> UUniversalFunctionLibrarys::StringParseIntoArray(const FString& SourceString, int MaxIndex)
{
	TArray<FString> Strings;
	int Index = 0;
	int TIndex;
	Strings.Reset();
	if (MaxIndex < 0 && MaxIndex != -1 || !SourceString.Len())
	{
		return Strings;
	}
	for (size_t i = 0; i < SourceString.Len(); i++)
	{
		/** * 检测空格,取消注释则开启 */
		/*if (SourceString.Mid(i, 1) == " ")
		{
			if (i == Index + 1 || i == Index)
			{
				Index++;
				continue;
			}
			TIndex = Strings.Add(SourceString.Mid(Index, i - Index));
			if (MaxIndex == -1 || MaxIndex > TIndex)
			{
				Index = i + 1;
				continue;
			}
			return Strings;
		}*/
		if (SourceString.Mid(i, 1) == TEXT(",") || SourceString.Mid(i, 1) == TEXT(";"))
		{
			TIndex = Strings.Add(SourceString.Mid(Index, i - Index));
			if (MaxIndex == -1 || MaxIndex > TIndex)
			{
				Index = i + 1;
				continue;
			}
			return Strings;
		}
		if (SourceString.Mid(i, 1) == TEXT("\""))
		{
			TIndex = FindStringParseIndex(SourceString, TEXT("\""), TEXT(""), i + 1); //SourceString.Find("\"", ESearchCase::IgnoreCase, ESearchDir::FromStart, i + 1);
			if (TIndex != -1)
			{
				i = size_t(TIndex + 1);
				TIndex = Strings.Add(SourceString.Mid(Index + 1, i - Index - 2));
				if (MaxIndex == -1 || MaxIndex > TIndex)
				{
					Index = i + 1;
					continue;
				}
				return Strings;
			}
			Strings.Add(SourceString.Mid(Index, SourceString.Len() - Index));
			return Strings;
		}
		if (SourceString.Mid(i, 1) == TEXT("{"))
		{
			TIndex = FindStringParseIndex(SourceString, TEXT("}"), TEXT("{"), i + 1);
			if (TIndex != -1)
			{
				i = size_t(TIndex + 1);
				TIndex = Strings.Add(SourceString.Mid(Index + 1, i - Index - 2));
				if (MaxIndex == -1 || MaxIndex > TIndex)
				{
					Index = i + 1;
					continue;
				}
				return Strings;
			}
			Strings.Add(SourceString.Mid(Index, SourceString.Len() - Index));
			return Strings;
		}
	}
	if (SourceString.Len() > Index)
	{
		Strings.Add(SourceString.Mid(Index, SourceString.Len() - Index));
	}
	return Strings;
}

FString UUniversalFunctionLibrarys::GetIndexStringParseIntoArray(const FString& SourceString, int MaxIndex)
{
	TArray<FString> Strings = StringParseIntoArray(SourceString, MaxIndex);
	return Strings.Num() > MaxIndex ? Strings[MaxIndex] : "";
}

TArray<FString> UUniversalFunctionLibrarys::StringParseIntoArrayLong(const FString& SourceString, int MaxIndex)
{
	TArray<FString> Strings;
	Strings.Reset();
	int Index = 0;
	int TIndex = 0;
	if (MaxIndex < 0 && MaxIndex != -1)
	{
		return Strings;
	}
	for (size_t i = 0; i < SourceString.Len(); i++)
	{
		if (SourceString.Mid(i, 1) == TEXT(";"))
		{
			TIndex = Strings.Add(SourceString.Mid(Index, i - Index + 1));
			if (MaxIndex == -1 || MaxIndex > TIndex)
			{
				Index = i + 1;
				continue;
			}
			return Strings;
		}
		if (SourceString.Mid(i, 1) == TEXT("\""))
		{
			TIndex = FindStringParseIndex(SourceString, TEXT("\""), TEXT(""), i + 1);
			if (MaxIndex == -1 || TIndex != -1)
			{
				i = TIndex;
				continue;
			}
		}
		if (SourceString.Mid(i, 1) == TEXT("{"))
		{
			TIndex = FindStringParseIndex(SourceString, TEXT("}"), TEXT("{"), i + 1);
			if (MaxIndex == -1 || TIndex != -1)
			{
				i = TIndex;
				continue;
			}
		}
	}
	if (SourceString.Len() != Index)
	{
		Strings.Add(SourceString.Mid(Index, SourceString.Len() - Index) + TEXT(";"));
	}
	return Strings;
}

int UUniversalFunctionLibrarys::FindBeginString(const TArray<FString>& Strings, const FString& SourceString)
{
	if (SourceString.Len())
	{
		for (size_t i = 0; i < Strings.Num(); i++)
		{
			if (SourceString == Strings[i].Mid(0, SourceString.Len()))
			{
				FString String = Strings[i].Mid(SourceString.Len(), 1);
				if (String == TEXT(",") || String == TEXT(";") || String == TEXT(" ") || String.IsEmpty())
				{
					return i;
				}
			}
		}
	}
	return -1;
}

TArray<int> UUniversalFunctionLibrarys::FindBeginStrings(const TArray<FString>& Strings, const FString& SourceString)
{
	TArray<int> Indexs;
	if (SourceString.Len())
	{
		for (size_t i = 0; i < Strings.Num(); i++)
		{
			if (SourceString == Strings[i].Mid(0, SourceString.Len()))
			{
				FString String = Strings[i].Mid(SourceString.Len(), 1);
				if (String == TEXT(",") || String == TEXT(";") || String == TEXT(" ") || String.IsEmpty())
				{
					Indexs.Add(i);
				}
			}
		}
	}
	return Indexs;
}

FString UUniversalFunctionLibrarys::AppendParseString(const FString& NameString, const FString& DataString)
{
	return FString::Printf(TEXT("%s,%s"), *NameString, *DataString);
}

FString UUniversalFunctionLibrarys::AppendParseStrings(const FString& NameString, const FString& DataNameString, const FString& DataString, bool ChildAppendParse)
{
	if (ChildAppendParse)
	{
		return  FString::Printf(TEXT("%s,{%s}"), *NameString, *AppendParseString(DataNameString, DataString));
	}
	else
	{
		return FString::Printf(TEXT("%s,{%s,%s}"), *NameString, *DataNameString, *DataString);
	}
}

int UUniversalFunctionLibrarys::SetStringsDataString(TArray<FString>& Strings, const FString& DataNameString, const FString& DataString, const FString& Cmd)
{
	int Index = FindBeginString(Strings, DataNameString);
	if (Index != -1)
	{
		if (Cmd == TEXT("Set"))
		{
			Strings[Index] = AppendParseString(DataNameString, DataString);
		}
		if (Cmd == TEXT("SetAll"))
		{
			Strings[Index] = AppendParseString(DataNameString, DataString);
		}
		if (Cmd == TEXT("Add"))
		{
			Strings[Index] = AppendParseString(Strings[Index], DataString);
		}
		if (Cmd == TEXT("AddU"))
		{
			Strings[Index] = AppendParseString(Strings[Index], DataString);
		}
		if (Cmd == TEXT("Remove"))
		{
			Strings.RemoveAt(Index);
		}
		if (Cmd == TEXT("RemoveAll"))
		{
			Strings.RemoveAt(Index);
		}
	}
	else
	{
		if (Cmd == TEXT("Set") || Cmd == TEXT("SetAll") || Cmd == TEXT("Add") || Cmd == TEXT("AddU"))
		{
			Index = Strings.Add(AppendParseString(DataNameString, DataString));
		}
	}
	return Index;
}

FString UUniversalFunctionLibrarys::GetNowTimerToString()
{
	return FString::Printf(TEXT("%d~%d~%d~%d~%d~%d~%d")
		, UKismetMathLibrary::Now().GetYear(), UKismetMathLibrary::Now().GetMonth()
		, UKismetMathLibrary::Now().GetDay(), UKismetMathLibrary::Now().GetHour()
		, UKismetMathLibrary::Now().GetMinute(), UKismetMathLibrary::Now().GetSecond()
		, UKismetMathLibrary::Now().GetMillisecond());
}

FString UUniversalFunctionLibrarys::NewUIDToString(bool bComplex, bool bEndSemicolon)
{
	FString UID = FString::Printf(TEXT("%s~%d"), *UUniversalFunctionLibrarys::GetNowTimerToString(), UKismetMathLibrary::RandomIntegerInRange(bComplex ? 222 : 0, bComplex ? 2222 : 222));
	if (bEndSemicolon)
	{
		UID += TEXT(";");
	}
	return UID;
}

bool UUniversalFunctionLibrarys::PlayerCameraRay(AActor* Owner, FHitResult& OutHit, TArray<AActor*> ActorsToIgnore, ETraceTypeQuery TraceTypeQuery, float Distance)
{
	if (Owner && Owner->GetWorld()->GetFirstPlayerController() && Owner->GetWorld()->GetFirstPlayerController()->PlayerCameraManager)
	{
		const FVector Start = Owner->GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation();
		const FVector End = Start + Owner->GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetActorForwardVector() * Distance;
		if (UKismetSystemLibrary::LineTraceSingle(Owner, Start, End, TraceTypeQuery, false, ActorsToIgnore, EDrawDebugTrace::ForOneFrame, OutHit, true))
		{
			return true;
		}
		OutHit.Location = End;
		return false;
	}
	return false;
}



int UUniversalFunctionLibrarys::ClampLimitIntScopes(int Index, int Min, int Max, int& Indexes)
{
	return ClampLimitScopes(Index, Min, Max, Indexes);
}

float UUniversalFunctionLibrarys::ClampLimitFloatScopes(float Index, float Min, float Max, float& Indexes)
{
	return ClampLimitScopes(Index, Min, Max, Indexes);
}


bool UUniversalFunctionLibrarys::IsClampLimitIntScopes(int Index, int Min, int Max)
{
	return IsClampLimitScopes(Index, Min, Max);
}

bool UUniversalFunctionLibrarys::IsClampLimitFloatScopes(float Index, float Min, float Max)
{
	return IsClampLimitScopes(Index, Min, Max);;
}

float UUniversalFunctionLibrarys::GetSlowNumerical(float Numerical, float EndNumerical, float SlowNumerical)
{
	if (Numerical == EndNumerical)
	{
		return EndNumerical;
	}
	if (Numerical > EndNumerical)
	{
		if (Numerical - SlowNumerical <= EndNumerical)
		{
			return EndNumerical;
		}
		else
		{
			return Numerical - SlowNumerical;
		}
	}
	if (Numerical + SlowNumerical >= EndNumerical)
	{
		return EndNumerical;
	}
	return Numerical + SlowNumerical;
}


void UUniversalFunctionLibrarys::DestroyComponentAllChild(const USceneComponent* SceneComponent)
{
	if (SceneComponent)
	{
		TArray<USceneComponent*> pSceneRootChilds = SceneComponent->GetAttachChildren();
		for (int i = 0; i < pSceneRootChilds.Num(); i++)
		{
			pSceneRootChilds[i]->DestroyComponent();
		}
	}
}

FVector UUniversalFunctionLibrarys::StringToVector(const FString& SourceString)
{
	FVector Vector;
	/*TArray<FString> Strings = StringParseIntoArray(SourceString);
	if (Strings.Num() > 2)
	{
		Vector.X = FCString::Atof(*Strings[0]);
		Vector.Y = FCString::Atof(*Strings[1]);
		Vector.Z = FCString::Atof(*Strings[2]);
		return Vector;
	}
	SourceString.ParseIntoArray(Strings, *FString(" "), true);
	if (Strings.Num() > 2)
	{
		Vector.X = FCString::Atof(*Strings[0].Mid(2, Strings[0].Len() - 2));
		Vector.Y = FCString::Atof(*Strings[1].Mid(2, Strings[1].Len() - 2));
		Vector.Z = FCString::Atof(*Strings[2].Mid(2, Strings[2].Len() - 2));
		return Vector;
	}
	SourceString.ParseIntoArray(Strings, *FString("~"), true);
	if (Strings.Num() > 2)
	{
		Vector.X = FCString::Atof(*Strings[0].Mid(2, Strings[0].Len() - 2));
		Vector.Y = FCString::Atof(*Strings[1].Mid(2, Strings[1].Len() - 2));
		Vector.Z = FCString::Atof(*Strings[2].Mid(2, Strings[2].Len() - 2));
		return Vector;
	} */
	Vector.InitFromString(SourceString);
	return Vector;
}

FVector2D UUniversalFunctionLibrarys::StringToVector2D(const FString& SourceString)
{
	FVector2D Vector2D;
	TArray<FString> Strings = StringParseIntoArray(SourceString);
	if (Strings.Num() > 1)
	{
		Vector2D.X = FCString::Atof(*Strings[0]);
		Vector2D.Y = FCString::Atof(*Strings[1]);
		return Vector2D;
	}
	SourceString.ParseIntoArray(Strings, *FString(TEXT(" ")), true);
	if (Strings.Num() > 1)
	{
		Vector2D.X = FCString::Atof(*Strings[0].Mid(2, Strings[0].Len() - 2));
		Vector2D.Y = FCString::Atof(*Strings[1].Mid(2, Strings[1].Len() - 2));
		return Vector2D;
	}
	SourceString.ParseIntoArray(Strings, *FString(TEXT("~")), true);
	if (Strings.Num() > 1)
	{
		Vector2D.X = FCString::Atof(*Strings[0].Mid(2, Strings[0].Len() - 2));
		Vector2D.Y = FCString::Atof(*Strings[1].Mid(2, Strings[1].Len() - 2));
		return Vector2D;
	}
	Vector2D.InitFromString(SourceString);
	return Vector2D;
}

FVector2D UUniversalFunctionLibrarys::Vector2DSwapXY(const FVector2D& SwapVector2D)
{
	return FVector2D(SwapVector2D.Y, SwapVector2D.X);
}

TArray<UActorComponent*> UUniversalFunctionLibrarys::GetActorComponents(const AActor* Actor, const TSubclassOf<UActorComponent>& ComponentClass)
{
	if (Actor != nullptr) /** * 判断重要值不是空的 */
	{
		TArray<UActorComponent*> ActorComponents; /** * 创建ActorComponent 组 */
		Actor->GetComponents(ComponentClass, ActorComponents); /** * 获取该Actor所有组件 */
		return ActorComponents;
	}
	return TArray<UActorComponent*>();
}

TArray<UActorComponent*> UUniversalFunctionLibrarys::GetActorAllComponents(const AActor* Actor, const TSubclassOf<UActorComponent>& ComponentClass)
{
	if (!Actor)
	{
		return TArray<UActorComponent*>();
	}
	/* 搜索附加Actor */
	TArray<AActor*> Actors;
	Actor->GetAttachedActors(Actors); /* * 获取Actor绑定的所有Actor */

	/* 创建临时储存物品的组件需求 */
	TArray<UActorComponent*> Components;
	TArray<UActorComponent*> ActorComponents;

	Actor->GetComponents(ComponentClass, Components); /** * 获取Actor里的所有组件 */
	if (Components.Num() > 0)
	{
		for (size_t i = 0; i < Components.Num(); i++)
		{
			if (Components[i])
			{
				ActorComponents.Add(Components[i]);
			}
		}
	}
	for (size_t i = 0; i < Actors.Num(); i++)
	{
		Actors[i]->GetComponents(ComponentClass, Components); /** * 获取Actor绑定的Actor里的所有组件 */
		if (Components.Num() > 0)
		{
			for (size_t j = 0; j < Components.Num(); j++)
			{
				if (Components[j])
				{
					ActorComponents.Add(Components[j]);
				}
			}
		}
	}
	return ActorComponents;
}

TArray<UActorComponent*> UUniversalFunctionLibrarys::GetActorComponentsByTag(const AActor* Actor, const FName& Tag, int Index)
{
	TInlineComponentArray<UActorComponent*> ComponentsByClass;
	TArray<UActorComponent*> ComponentsByTag;
	if (!Actor)
	{
		return MoveTemp(ComponentsByTag);
	}
	Actor->GetComponents(UActorComponent::StaticClass(), ComponentsByClass); /** * 获取该Actor所有组件 */
	ComponentsByTag.Reserve(Index = -1 ? ComponentsByClass.Num() : Index + 1);
	for (UActorComponent* Component : ComponentsByClass)
	{
		if (Component->ComponentHasTag(Tag))
		{
			ComponentsByTag.Push(Component);
			if (ComponentsByTag.Num() > Index)
			{
				return ComponentsByTag;
			}
		}
	}
	return MoveTemp(ComponentsByTag);
}

UActorComponent* UUniversalFunctionLibrarys::GetActorComponentByTag(const AActor* Actor, const FName& Tag)
{
	TArray<UActorComponent*> TagComponents = GetActorComponentsByTag(Actor, Tag, 0);
	if (TagComponents.Num() > 0)
	{
		return TagComponents[0];
	}
	return nullptr;
}

AController* UUniversalFunctionLibrarys::GetActorController(AActor* Actor)
{
	if (Actor == nullptr)
	{
		return nullptr;
	}
	APawn* Pawn = Cast<APawn>(Actor);
	if (Pawn)
		return Pawn->GetController();
	return GetActorController(Actor->GetOwner());
}

APlayerController* UUniversalFunctionLibrarys::GetActorPlayerController(AActor* Actor)
{
	AController* Controller = GetActorController(Actor);
	if (Controller)
		return Cast<APlayerController>(Controller);
	return nullptr;

}

bool UUniversalFunctionLibrarys::GetActorIsLocalPlayerController(AActor* Actor)
{
	APlayerController* PlayerController = GetActorPlayerController(Actor);
	if (PlayerController)
		return PlayerController->IsLocalController();
	return false;
}

TArray<FString> UUniversalFunctionLibrarys::GetStringsScopes(const TArray<FString>& Strings, int Index, int EndIndex)
{
	TArray<FString> TStrings;
	for (size_t i = Index; i < (EndIndex == -1 ? Strings.Num() : EndIndex); i++)
	{
		TStrings.Add(Strings[i]);
	}
	return TStrings;
}

TArray<FName> UUniversalFunctionLibrarys::StringsToNames(const TArray<FString>& Strings)
{
	TArray<FName> Names;
	for (size_t i = 0; i < Strings.Num(); i++)
	{
		Names.Add(*Strings[i]);
	}
	return Names;
}

TArray<FString> UUniversalFunctionLibrarys::NamesToStrings(const TArray<FName>& Names)
{
	TArray<FString> Strings;
	for (size_t i = 0; i < Names.Num(); i++)
	{
		Strings.Add(Names[i].ToString());
	}
	return Strings;
}

int UUniversalFunctionLibrarys::GetStringStringsIndex(const TArray<FStringStrings>& StringStringsArray, const FString& Name)
{
	return FStringStrings::GetArrayNameIndex(StringStringsArray, Name);
}

FString UUniversalFunctionLibrarys::GetStringStringsIndexData(const TArray<FStringStrings>& StringStringsArray, const FString& Name)
{
	return FStringStrings::GetArrayNameIndexData(StringStringsArray, Name);
}

int UUniversalFunctionLibrarys::SetStringStringsArray(TArray<FStringStrings>& StringStringsArray, const FString& Name, const FString& InString, ESetCmd SetCmd)
{
	return FStringStrings::SetArrayNameData(StringStringsArray, Name, InString, SetCmd);
}

FVector UUniversalFunctionLibrarys::FrontScopeRay(UObject* World, const FVector& Location, const FVector& Forward, const TEnumAsByte<ETraceTypeQuery>& TraceTypeQuerys, const TArray<AActor*>& ActorsToIgnore, float Distance, float Scope, float DropDistance, int Num)
{
	FHitResult OutHit;
	if (World)
	{
		FVector PlayWorldLocation = Location + Forward * Distance;
		if (UKismetSystemLibrary::LineTraceSingle(World, Location, PlayWorldLocation, TraceTypeQuerys, false, ActorsToIgnore, EDrawDebugTrace::ForDuration, OutHit, true))
		{
			PlayWorldLocation = Location;
		}
		FVector DownWorldLocation;
		FVector EndWorldLocation;
		for (size_t i = 0; i < Num; i++)
		{
			DownWorldLocation.Y = PlayWorldLocation.Y - FMath::FRandRange(Scope * -1, Scope);
			DownWorldLocation.X = PlayWorldLocation.X - FMath::FRandRange(Scope * -1, Scope);
			DownWorldLocation.Z = PlayWorldLocation.Z;
			if (UKismetSystemLibrary::LineTraceSingle(World, PlayWorldLocation, DownWorldLocation, TraceTypeQuerys, false, ActorsToIgnore, EDrawDebugTrace::ForDuration, OutHit, true) == false)
			{
				EndWorldLocation = DownWorldLocation;
				EndWorldLocation.Z = PlayWorldLocation.Z - DropDistance;
				if (UKismetSystemLibrary::LineTraceSingle(World, DownWorldLocation, EndWorldLocation, TraceTypeQuerys, false, ActorsToIgnore, EDrawDebugTrace::ForDuration, OutHit, true))
				{
					return OutHit.ImpactPoint;
				}
			}
		}
	}
	if (UKismetSystemLibrary::LineTraceSingle(World, Location, { Location.X ,Location.Y, Location.Z - DropDistance * 10 }, TraceTypeQuerys, false, ActorsToIgnore, EDrawDebugTrace::ForDuration, OutHit, true))
	{
		return OutHit.ImpactPoint;
	}
	return Location;
}

FVector2D UUniversalFunctionLibrarys::GetXYClampSize(float X, float Y, float XMax, float YMax)
{
	if (X <= XMax)
	{
		if (Y <= YMax)
		{
			return FVector2D(X, Y);
		}
		else
		{
			return FVector2D(YMax / Y * X, YMax);
		}
	}
	if (Y <= YMax)
	{
		return FVector2D(XMax, XMax / X * Y);
	}
	if (X / Y < XMax / YMax)
	{
		return FVector2D(X / Y * YMax, YMax);
	}
	return FVector2D(XMax, XMax / (X / Y));
}


void UUniversalFunctionLibrarys::SetInputModeAndMouse(UObject* World, bool bControl)
{
	if (World && World->GetWorld() && World->GetWorld()->GetFirstPlayerController())
	{
		World->GetWorld()->GetFirstPlayerController()->bShowMouseCursor = bControl;
		if (bControl)
		{

			FInputModeGameAndUI InputMode;
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			InputMode.SetHideCursorDuringCapture(true);

			World->GetWorld()->GetFirstPlayerController()->SetInputMode(InputMode);
		}
		else
		{
			FInputModeGameOnly InputMode;
			World->GetWorld()->GetFirstPlayerController()->SetInputMode(InputMode);
		}
	}
}

int UUniversalFunctionLibrarys::GetStringColorsNameIndex(const TArray<FStringColor>& InStringColorArray, const FName& InName)
{
	return FStringColor::GetArrayNameIndex(InStringColorArray, InName);
}

FStringColor UUniversalFunctionLibrarys::GetStringColorsNameIndexData(const TArray<FStringColor>& InStringColorArray, const FName& InName)
{
	return FStringColor::GetArrayNameIndexData(InStringColorArray, InName);
}

int UUniversalFunctionLibrarys::SetStringColorsNameData(UPARAM(ref) TArray<FStringColor>& InStringColorArray, const FStringColor& InStringColor)
{
	return FStringColor::SetArrayNameData(InStringColorArray, InStringColor);
}

int UUniversalFunctionLibrarys::GetStringImageDatasNameIndex(const TArray<FStringImageData>& InStringImageDataArray, const FName& InName)
{
	return FStringImageData::GetArrayNameIndex(InStringImageDataArray, InName);
}

FStringImageData UUniversalFunctionLibrarys::GetStringImageDatasNameIndexData(const TArray<FStringImageData>& InStringImageDataArray, const FName& InName)
{
	return FStringImageData::GetArrayNameIndexData(InStringImageDataArray, InName);
}


int UUniversalFunctionLibrarys::SetStringImageDatasNameData(UPARAM(ref)TArray<FStringImageData>& InStringImageDataArray, const FStringImageData& InStringImageData)
{
	return FStringImageData::SetArrayNameData(InStringImageDataArray, InStringImageData);
}

bool UUniversalFunctionLibrarys::RemoveStringImageDatasName(UPARAM(ref) TArray<FStringImageData>& InStringImageDataArray, const FName& InName)
{
	return  FStringImageData::RemoveArrayNameData(InStringImageDataArray, InName);
}

float UUniversalFunctionLibrarys::GenerateWeightedRandomFloat(float MinValue, float MaxValue, float BiasFactor)
{
	return GenerateWeightedRandom(MinValue, MaxValue, BiasFactor);
}

FString UUniversalFunctionLibrarys::StringsGet(const TArray<FString>& Strings, int Index)
{
	return Strings.IsValidIndex(Index) ? Strings[Index] : FString();
}

FName UUniversalFunctionLibrarys::NamesGet(const TArray<FName>& Names, int Index)
{
	return Names.IsValidIndex(Index) ? Names[Index] : NAME_None;
}

/** * 屏幕打印字符串 */
void UUniversalFunctionLibrarys::PrintString(const UObject* Object, const FString& String, float Tim, const FName Key)
{
	UKismetSystemLibrary::PrintString(Object, String, true, false, FColor::Blue, Tim, Key);
}

/** * 延迟时间,转接对应名字的函数 */
void UUniversalFunctionLibrarys::CustomDelay(UObject* WorldContextObject, float Duration, const FString& ExecutionFunction)
{
	if (!WorldContextObject)
	{
		return;
	}
	if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		FLatentActionInfo Latentinfo;
		Latentinfo.CallbackTarget = WorldContextObject;
		Latentinfo.ExecutionFunction = *ExecutionFunction;
		Latentinfo.Linkage = 0;
		Latentinfo.UUID = FMath::RandRange(0, 222);
		LatentActionManager.AddNewAction(WorldContextObject, Latentinfo.UUID, new FDelayAction(Duration, Latentinfo));

	}
}

AActor* UUniversalFunctionLibrarys::SpawnActor(UObject* World, UClass* Class, const FVector& Location, const FQuat& Rotation, const FVector& Scale3D, AActor* Owner, APawn* Instigator)
{
	if (World && Class)
	{
		FTransform Transform;
		Transform.SetLocation(Location);
		Transform.SetRotation(Rotation); //FQuat::MakeFromEuler({ Rotation.Pitch, Rotation.Yaw, Rotation.Roll })
		Transform.SetScale3D(Scale3D);
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = Owner;
		SpawnParameters.Instigator = Instigator;
		return World->GetWorld()->SpawnActor<AActor>(Class, Transform, SpawnParameters);
	}
	return nullptr;
}

AActor* UUniversalFunctionLibrarys::SpawnActor(UObject* World, UClass* Class, FTransform const& Transform, AActor* Owner, APawn* Instigator)
{
	return SpawnActor(World, Class, Transform.GetLocation(), Transform.GetRotation(), Transform.GetScale3D(), Owner, Instigator);
}

AActor* UUniversalFunctionLibrarys::SpawnActor(UObject* World, UClass* Class, const FVector& Location, const FRotator& Rotation, const FVector& Scale3D, AActor* Owner, APawn* Instigator)
{
	return SpawnActor(World, Class, Location, FQuat(Rotation), Scale3D, Owner, Instigator);
}

AActor* UUniversalFunctionLibrarys::SpawnActor(UObject* World, TSoftClassPtr<AActor> SoftActorClass, const FVector& Location, const FRotator& Rotation, const FVector& Scale3D, AActor* Owner, APawn* Instigator)
{
	if (SoftActorClass.IsNull())
	{
		return nullptr;
	}
	if (SoftActorClass.IsValid() == false)
	{
		SoftActorClass.LoadSynchronous();
	}
	return SpawnActor(World, SoftActorClass.Get(), Location, FQuat(Rotation), Scale3D, Owner, Instigator);
}





UDecalComponent* UUniversalFunctionLibrarys::SpawnDecalAtLocation(AActor* Owner, UMaterialInterface* MaterialInterface, FVector Location, FRotator Rotation, FVector Scale3D, float LifeSpan, float FadeScreeSize)
{
	if (Owner)
	{
		if (MaterialInterface)
		{
			UDecalComponent* DecalComponent = UGameplayStatics::SpawnDecalAtLocation(Owner->GetWorld(), MaterialInterface, Scale3D, Location, Rotation, LifeSpan); //生成贴花
			if (DecalComponent)
			{
				DecalComponent->SetFadeScreenSize(FadeScreeSize); //设置贴花范围显示位置
				return DecalComponent;
			}
		}
	}
	return nullptr;
}


UDecalComponent* UUniversalFunctionLibrarys::SpawnDecalAtLocation(AActor* Owner, UMaterialInterface* MaterialInterface, FVector Location, FVector Rotation, FVector Scale3D, float LifeSpan, float FadeScreeSize)
{
	if (Owner)
	{
		if (MaterialInterface)
		{
			UDecalComponent* DecalComponent = UGameplayStatics::SpawnDecalAtLocation(Owner->GetWorld(), MaterialInterface, Scale3D, Location, Rotation.ToOrientationRotator(), LifeSpan); //生成贴花
			if (DecalComponent)
			{
				DecalComponent->SetFadeScreenSize(FadeScreeSize); //设置贴花范围显示位置
				return DecalComponent;
			}
		}
	}
	return nullptr;
}

UDecalComponent* UUniversalFunctionLibrarys::SpawnDecalAttached(AActor* Owner, UMaterialInterface* MaterialInterface, USceneComponent* AttachComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale3D, EAttachLocation::Type LocationType, float LifeSpan, float FadeScreeSize)
{
	if (Owner)
	{
		if (MaterialInterface)
		{
			UDecalComponent* DecalComponent = UGameplayStatics::SpawnDecalAttached(MaterialInterface, Scale3D, AttachComponent, AttachPointName, AttachComponent->GetSocketTransform(AttachPointName).InverseTransformPosition(Location), UKismetMathLibrary::InverseTransformRotation(AttachComponent->GetSocketTransform(AttachPointName), Rotation), LocationType, LifeSpan); //生成贴花并计算好对应的相对位置,旋转
			if (DecalComponent)
			{
				DecalComponent->SetFadeScreenSize(FadeScreeSize);//设置贴花范围显示位置
				return DecalComponent;
			}
		}
	}
	return nullptr;
}

UDecalComponent* UUniversalFunctionLibrarys::SpawnDecalAttached(AActor* Owner, UMaterialInterface* MaterialInterface, USceneComponent* AttachComponent, FName AttachPointName, FVector Location, FVector Rotation, FVector Scale3D, EAttachLocation::Type LocationType, float LifeSpan, float FadeScreeSize)
{
	if (Owner)
	{
		if (MaterialInterface)
		{
			UDecalComponent* DecalComponent = UGameplayStatics::SpawnDecalAttached(MaterialInterface, Scale3D, AttachComponent, AttachPointName, AttachComponent->GetSocketTransform(AttachPointName).InverseTransformPosition(Location), UKismetMathLibrary::InverseTransformRotation(AttachComponent->GetSocketTransform(AttachPointName), Rotation.ToOrientationRotator()), LocationType, LifeSpan); //生成贴花并计算好对应的相对位置,旋转
			if (DecalComponent)
			{
				DecalComponent->SetFadeScreenSize(FadeScreeSize); //设置贴花范围显示位置
				return DecalComponent;
			}
		}
	}
	return nullptr;
}

bool UUniversalFunctionLibrarys::CompositeDataTableAddDataTable(UCompositeDataTable* InCompositeDataTable, UDataTable* TableToAdd)
{
	if (InCompositeDataTable && TableToAdd)
	{
		InCompositeDataTable->AddParentTable(TableToAdd);
		return true;
	}
	return false;
}

bool UUniversalFunctionLibrarys::CompositeDataTableRemoveDataTable(UCompositeDataTable* InCompositeDataTable, UDataTable* TableToRemove)
{
	if (InCompositeDataTable && TableToRemove)
	{
		InCompositeDataTable->RemoveParentTable(TableToRemove);
		return true;
	}
	return false;
}

/** * 字符串异步加载 */
//void UUniversalFunctionLibrarys::StringAssetLoad(const FString& String, FStreamableDelegate StreamableDelegate)
//{
	//if(String.IsEmpty() == false  && UAssetManager::Get().IsValid())
	//{
	//	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(StringLoadObjectAsset(String), StreamableDelegate);
	//}
//}



TArray<FAssetData> UUniversalFunctionLibrarys::FindPathAssets(const FName& PathName, bool bRecursive)
{
	// 确保AssetRegistryModule已加载
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
	TArray<FAssetData> AssetDatas;
	AssetRegistry.GetAssetsByPath(PathName, AssetDatas, bRecursive);
	return AssetDatas;
}

TArray<FName> UUniversalFunctionLibrarys::FindSubPaths(const FName& PathName, bool bRecursive)
{
	// 确保AssetRegistryModule已加载
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
	TArray<FName> PathNames;
	AssetRegistry.GetSubPaths(PathName, PathNames, bRecursive);
	return PathNames;
}

bool UUniversalFunctionLibrarys::IsOwnerClient(AActor* InOwner)
{
	return (InOwner && InOwner->HasAuthority() && InOwner->GetRemoteRole() == ROLE_AutonomousProxy);
}

UActorComponent* UUniversalFunctionLibrarys::AddSoftActorComponent(AActor* InOwner, TSoftClassPtr<UActorComponent> InActorComponentSoftClassPtr)
{
	if (InOwner == nullptr || InActorComponentSoftClassPtr.IsNull())
	{
		return nullptr;
	}
	if (InActorComponentSoftClassPtr.IsValid() == false)
	{
		InActorComponentSoftClassPtr.LoadSynchronous();
	}
	UActorComponent* NewComponent = NewObject<UActorComponent>(InOwner, InActorComponentSoftClassPtr.Get());
	if (NewComponent)
	{
		NewComponent->RegisterComponent();
	}
	return nullptr;
}
