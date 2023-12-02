// Fill out your copyright notice in the Description page of Project Settings.


#include "UniversalFunctionLibrarys.h"
#include "Kismet/GameplayStatics.h" //游戏静态库
#include "Kismet/KismetMathLibrary.h" //官方函数库
#include "Kismet/KismetSystemLibrary.h" //官方函数库
#include "Runtime/Engine/Public/DelayAction.h" //延迟的函数库

//#include "Engine/Classes/Particles/ParticleSystem.h"  //粒子头文件
#include "Engine/Classes/Components/DecalComponent.h" //贴花







UUniversalFunctionLibrarys::UUniversalFunctionLibrarys()
{

}

TSoftClassPtr<UObject> UUniversalFunctionLibrarys::StringCastTSoftClassPtr(const FString& PathString)
{
	if (PathString.Len() > 22 && PathString.StartsWith("/Script/Engine.Blueprint") && PathString.EndsWith("_C'") == false)
	{
		return TSoftClassPtr<UObject>(StringCastTSoftClassPtr(PathString.Mid(0, PathString.Len() - 1) + "_C'"));
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
		/** 检测空格,取消注释则开启 */
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
		if (SourceString.Mid(i, 1) == "," || SourceString.Mid(i, 1) == ";")
		{
			TIndex = Strings.Add(SourceString.Mid(Index, i - Index));
			if (MaxIndex == -1 || MaxIndex > TIndex)
			{
				Index = i + 1;
				continue;
			}
			return Strings;
		}
		if (SourceString.Mid(i, 1) == "\"")
		{
			TIndex = FindStringParseIndex(SourceString, "\"", "", i + 1); //SourceString.Find("\"", ESearchCase::IgnoreCase, ESearchDir::FromStart, i + 1);
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
		if (SourceString.Mid(i, 1) == "{")
		{
			TIndex = FindStringParseIndex(SourceString, "}", "{", i + 1);
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
		if (SourceString.Mid(i, 1) == ";")
		{
			TIndex = Strings.Add(SourceString.Mid(Index, i - Index + 1));
			if (MaxIndex == -1 || MaxIndex > TIndex)
			{
				Index = i + 1;
				continue;
			}
			return Strings;
		}
		if (SourceString.Mid(i, 1) == "\"")
		{
			TIndex = FindStringParseIndex(SourceString, "\"", "", i + 1);
			if (MaxIndex == -1 || TIndex != -1)
			{
				i = TIndex;
				continue;
			}
		}
		if (SourceString.Mid(i, 1) == "{")
		{
			TIndex = FindStringParseIndex(SourceString, "}", "{", i + 1);
			if (MaxIndex == -1 || TIndex != -1)
			{
				i = TIndex;
				continue;
			}
		}
	}
	if (SourceString.Len() != Index)
	{
		Strings.Add(SourceString.Mid(Index, SourceString.Len() - Index) + ";");
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
				if (String == "," || String == ";" || String == " " || String == "")
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
				if (String == "," || String == ";" || String == " " || String == "")
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
	return NameString + "," + DataString + ";";
}

FString UUniversalFunctionLibrarys::AppendParseStrings(const FString& NameString, const FString& DataNameString, const FString& DataString, bool ChildAppendParse)
{
	if (ChildAppendParse)
	{
		return NameString + ",{" + AppendParseString(DataNameString, DataString) + "};";
	}
	else
	{
		return NameString + ",{" + DataNameString + DataString + "};";
	}
}

FString UUniversalFunctionLibrarys::GetNowTimerToString()
{
	FString Time = "";
	Time += FString::FromInt(UKismetMathLibrary::Now().GetYear());
	Time += "~";
	Time += FString::FromInt(UKismetMathLibrary::Now().GetMonth());
	Time += "~";
	Time += FString::FromInt(UKismetMathLibrary::Now().GetDay());
	Time += "~";
	Time += FString::FromInt(UKismetMathLibrary::Now().GetHour());
	Time += "~";
	Time += FString::FromInt(UKismetMathLibrary::Now().GetMinute());
	Time += "~";
	Time += FString::FromInt(UKismetMathLibrary::Now().GetSecond());
	Time += "~";
	Time += FString::FromInt(UKismetMathLibrary::Now().GetMillisecond());
	return Time;
}

FString UUniversalFunctionLibrarys::NewUIDToString(bool Complex, bool EndSemicolon)
{
	FString UID = "";

	UID += UUniversalFunctionLibrarys::GetNowTimerToString();
	UID += "~";
	UID += FString::FromInt(UKismetMathLibrary::RandomIntegerInRange(0, 222));
	if (Complex)
	{
		UID += FString::FromInt(UKismetMathLibrary::RandomIntegerInRange(222, 2222));
	}if (EndSemicolon)
	{
		UID += ";";
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


template< class T >
T UUniversalFunctionLibrarys::ClampLimitScopes(T Index, T Min, T Max, T& Indexes)
{
	if (Index < Min)
	{
		Indexes = Index - Min;
		return Min;
	}
	if (Index > Max)
	{
		Indexes = Index - Max;
		return Max;
	}
	Indexes = 0;
	return Index;
}

int UUniversalFunctionLibrarys::ClampLimitIntScopes(int Index, int Min, int Max, int& Indexes)
{
	return ClampLimitScopes(Index, Min, Max, Indexes);
}

float UUniversalFunctionLibrarys::ClampLimitFloatScopes(float Index, float Min, float Max, float& Indexes)
{
	return ClampLimitScopes(Index, Min, Max, Indexes);
}


template<class T>
bool UUniversalFunctionLibrarys::IsClampLimitScopes(T Index, T Min, T Max)
{
	return Index >= Min && Index <= Max;
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

void UUniversalFunctionLibrarys::SetInputModeAndMouse(UObject* Object, bool Control)
{
	if (Object && Object->GetWorld() && Object->GetWorld()->GetFirstPlayerController())
	{
		Object->GetWorld()->GetFirstPlayerController()->bShowMouseCursor = Control;
		if (Control)
		{

			FInputModeGameAndUI InputMode;
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			InputMode.SetHideCursorDuringCapture(true);

			Object->GetWorld()->GetFirstPlayerController()->SetInputMode(InputMode);
		}
		else
		{
			FInputModeGameOnly InputMode;
			Object->GetWorld()->GetFirstPlayerController()->SetInputMode(InputMode);
		}
	}
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
	SourceString.ParseIntoArray(Strings, *FString(" "), true);
	if (Strings.Num() > 1)
	{
		Vector2D.X = FCString::Atof(*Strings[0].Mid(2, Strings[0].Len() - 2));
		Vector2D.Y = FCString::Atof(*Strings[1].Mid(2, Strings[1].Len() - 2));
		return Vector2D;
	}
	SourceString.ParseIntoArray(Strings, *FString("~"), true);
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
			if (Components[i] != nullptr)
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
				if (Components[j] != nullptr)
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


FString UUniversalFunctionLibrarys::StringsGet(TArray<FString>& Strings, int Index)
{
	return Strings.IsValidIndex(Index) ? Strings[Index] : FString();
}

FVector UUniversalFunctionLibrarys::FrontScopeRay(UObject* World, const FVector& Location, const FVector& Forward, const TEnumAsByte<ETraceTypeQuery>& TraceTypeQuerys, const TArray<AActor*>& ActorsToIgnore, float Distance, float DownDistance, float Scope, int Num)
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
				EndWorldLocation.Z = PlayWorldLocation.Z - DownDistance;
				if (UKismetSystemLibrary::LineTraceSingle(World, DownWorldLocation, EndWorldLocation, TraceTypeQuerys, false, ActorsToIgnore, EDrawDebugTrace::ForDuration, OutHit, true))
				{
					return OutHit.ImpactPoint;
				}
			}
		}
	}
	if (UKismetSystemLibrary::LineTraceSingle(World, Location, { Location.X ,Location.Y, Location.Z - DownDistance * 10 }, TraceTypeQuerys, false, ActorsToIgnore, EDrawDebugTrace::ForDuration, OutHit, true))
	{
		return OutHit.ImpactPoint;
	}
	return Location;
}

/** 字符串异步加载 */
//void UUniversalFunctionLibrarys::StringAssetLoad(const FString& String, FStreamableDelegate StreamableDelegate)
//{
	//if(String != ""  && UAssetManager::Get().IsValid())
	//{
	//	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(StringLoadObjectAsset(String), StreamableDelegate);
	//}
//}


/** 屏幕打印字符串 */
void UUniversalFunctionLibrarys::PrintString(const UObject* Object, const FString& String, float Tim)
{
	UKismetSystemLibrary::PrintString(Object, String, true, false, FColor::Blue, Tim);
}

/** 延迟时间,转接对应名字的函数 */
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
		Latentinfo.UUID = UKismetMathLibrary::RandomIntegerInRange(0, 222);
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



UDecalComponent* UUniversalFunctionLibrarys::SpawnDecalAtLocation(AActor* Owner, UMaterialInstance* MaterialInstance, FVector Location, FRotator Rotation, FVector Scale3D, float LifeSpan, float FadeScreeSize)
{
	if (Owner)
	{
		if (MaterialInstance)
		{
			UDecalComponent* DecalComponent = UGameplayStatics::SpawnDecalAtLocation(Owner->GetWorld(), MaterialInstance, Scale3D, Location, Rotation, LifeSpan); //生成贴花
			if (DecalComponent)
			{
				DecalComponent->SetFadeScreenSize(FadeScreeSize); //设置贴花范围显示位置
				return DecalComponent;
			}
		}
	}
	return nullptr;
}


UDecalComponent* UUniversalFunctionLibrarys::SpawnDecalAtLocation(AActor* Owner, UMaterialInstance* MaterialInstance, FVector Location, FVector Rotation, FVector Scale3D, float LifeSpan, float FadeScreeSize)
{
	if (Owner)
	{
		if (MaterialInstance)
		{
			UDecalComponent* DecalComponent = UGameplayStatics::SpawnDecalAtLocation(Owner->GetWorld(), MaterialInstance, Scale3D, Location, Rotation.ToOrientationRotator(), LifeSpan); //生成贴花
			if (DecalComponent)
			{
				DecalComponent->SetFadeScreenSize(FadeScreeSize); //设置贴花范围显示位置
				return DecalComponent;
			}
		}
	}
	return nullptr;
}

UDecalComponent* UUniversalFunctionLibrarys::SpawnDecalAttached(AActor* Owner, UMaterialInstance* MaterialInstance, USceneComponent* AttachComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale3D, EAttachLocation::Type LocationType, float LifeSpan, float FadeScreeSize)
{
	if (Owner)
	{
		if (MaterialInstance)
		{
			UDecalComponent* DecalComponent = UGameplayStatics::SpawnDecalAttached(MaterialInstance, Scale3D, AttachComponent, AttachPointName, AttachComponent->GetSocketTransform(AttachPointName).InverseTransformPosition(Location), UKismetMathLibrary::InverseTransformRotation(AttachComponent->GetSocketTransform(AttachPointName), Rotation), LocationType, LifeSpan); //生成贴花并计算好对应的相对位置,旋转
			if (DecalComponent)
			{
				DecalComponent->SetFadeScreenSize(FadeScreeSize);//设置贴花范围显示位置
				return DecalComponent;
			}
		}
	}
	return nullptr;
}

UDecalComponent* UUniversalFunctionLibrarys::SpawnDecalAttached(AActor* Owner, UMaterialInstance* MaterialInstance, USceneComponent* AttachComponent, FName AttachPointName, FVector Location, FVector Rotation, FVector Scale3D, EAttachLocation::Type LocationType, float LifeSpan, float FadeScreeSize)
{
	if (Owner)
	{
		if (MaterialInstance)
		{
			UDecalComponent* DecalComponent = UGameplayStatics::SpawnDecalAttached(MaterialInstance, Scale3D, AttachComponent, AttachPointName, AttachComponent->GetSocketTransform(AttachPointName).InverseTransformPosition(Location), UKismetMathLibrary::InverseTransformRotation(AttachComponent->GetSocketTransform(AttachPointName), Rotation.ToOrientationRotator()), LocationType, LifeSpan); //生成贴花并计算好对应的相对位置,旋转
			if (DecalComponent)
			{
				DecalComponent->SetFadeScreenSize(FadeScreeSize); //设置贴花范围显示位置
				return DecalComponent;
			}
		}
	}
	return nullptr;
}