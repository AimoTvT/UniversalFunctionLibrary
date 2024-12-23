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
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/Engine.h"
#include "Engine/EngineTypes.h"
#include "Config/UniversalStruct.h"
#include "Engine/CompositeDataTable.h"
#include "AssetRegistry/AssetData.h"

#include "UniversalFunctionLibrarys.generated.h"




/** *
 *
 */
UCLASS()
class UNIVERSALFUNCTIONLIBRARY_API UUniversalFunctionLibrarys : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UUniversalFunctionLibrarys();

	


	/** * ESetCmdToString
	* InSetCmd 枚举
	* return 名字字符串
	*/
	static const TCHAR* ESetCmdToString(ESetCmd InSetCmd);

	/** * 字符串转换SoftClassPtr 
	* PathString 类路径
	* return 软引用类
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
	static TSoftClassPtr<UObject> StringCastTSoftClassPtr(const FString& PathString);

	/** * 字符串转换 SoftObjectPtr 
	* PathString 资源路径
	* return 软引用
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
	static TSoftObjectPtr<UObject> StringCastTSoftObjectPtr(const FString& PathString);

	/** * 字符串转换 FSoftObjectPath 
	* PathString 资源路径
	* return 返回软引用路径
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
	static FSoftObjectPath StringCastFSoftObjectPath(const FString& PathString);


	/** * 字符串加载 Class 
	* PathString 类路径
	* return 类指针
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Load")
	static UClass* StringLoadClassAsset(const FString& PathString);

	/** * 字符串加载 Object 
	* PathString 资源路径
	* return Object指针
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Load")
	static UObject* StringLoadObjectAsset(const FString& PathString);

	/** * 
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Load")
	static UClass* AssetDataLoadClass(const FAssetData& AssetData);


	

	/** * 解析字符串 */

	/** * 获取字符串子串,并跳过敏感子串 
	* C++ 使用的,本插件自己使用,不建议调用,所以并不再多解释
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
	static int FindStringParseIndex(const FString& SourceString, const FString& FindString, const FString& SensitiveString, int Index = -1);

	/** * 解析字符串,分隔符号支持 , ; " { } 
	* C++ 使用的,本插件自己使用,不建议调用,所以并不再多解释
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
	static TArray<FString> StringParseIntoArray(const FString& SourceString, int MaxIndex = -1);

	/** * 解析字符串,分隔符号支持 , ; " { } 
	* C++ 使用的,本插件自己使用,不建议调用,所以并不再多解释
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
	static FString GetIndexStringParseIntoArray(const FString& SourceString, int MaxIndex = 1);

	/** * 解析为长字符串,分隔符号支持 ; " { } 
	* C++ 使用的,本插件自己使用,不建议调用,所以并不再多解释
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
	static TArray<FString> StringParseIntoArrayLong(const FString& SourceString, int MaxIndex = -1);

	/** * 解析开头字符是否相等,如果相等判读后一位是否== , ; " ,真返回索引 
	* C++ 使用的,本插件自己使用,不建议调用,所以并不再多解释
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
	static int FindBeginString(const TArray<FString>& Strings, const FString& SourceString);

	/** * 解析开头字符是否相等,如果相等判读后一位是否== , ; " ,真返回索引组 
	* C++ 使用的,本插件自己使用,不建议调用,所以并不再多解释
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
	static TArray<int> FindBeginStrings(const TArray<FString>& Strings, const FString& SourceString);

	/** * 附加可解析字符串 
	* C++ 使用的,本插件自己使用,不建议调用,所以并不再多解释
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
	static FString AppendParseString(const FString& NameString, const FString& DataString);

	/** * 附加可解析字符串组 
	* C++ 使用的,本插件自己使用,不建议调用,所以并不再多解释
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
	static FString AppendParseStrings(const FString& NameString, const FString& DataNameString, const FString& DataString, bool ChildAppendParse = true);

	/** * 附加可解析字符串组 
	* C++ 使用的,本插件自己使用,不建议调用,所以并不再多解释
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
	static int SetStringsDataString(TArray<FString>& Strings, const FString& DataNameString, const FString& DataString, const FString& Cmd = TEXT("Set"));

	/** * 返回时间字符串,分隔符号( , ),可选结尾分号 
	* return 时间字符串
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|String")
	static FString GetNowTimerToString();

	/** * 返回时间为唯一UID,可选复杂随机结尾,可选结尾分号 
	* bComplex 复杂
	* bEndSemicolon 是否加分好 (;)
	* return 返回值编码字符串
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|String")
	static FString NewUIDToString(bool bComplex = false, bool bEndSemicolon = false);

	/** * 玩家摄像机射线检测 
	* Owner 目标玩家
	* OutHit 射线返回值
	* ActorsToIgnore 忽略演员组
	* TraceTypeQuery 射线类型
	* Distance 射线距离
	* return 返回是否检测到
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Player")
	static bool PlayerCameraRay(AActor* Owner, FHitResult& OutHit, TArray<AActor*> ActorsToIgnore, ETraceTypeQuery TraceTypeQuery, float Distance = 500);

	/** * 数值范围内并返回引用多余的数 
	* Index 目标值
	* Min 最小值
	* Max 最大值
	* Indexes 多余的数
	* return 返回限制值
	*/
	template<typename T >
	static T ClampLimitScopes(T Index, T Min, T Max, T& Indexes)
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
		/*if (Index + Min > Max)
		{
			Indexes = Index + Min - Max;
		}*/
		Indexes = 0;
		return Index;
	}

	/** * Int数值范围内并返回引用多余的数 
	* Index 目标值
	* Min 最小值
	* Max 最大值
	* Indexes 多余的数
	* return 返回限制值
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static int ClampLimitIntScopes(int Index, int Min, int Max, int& Indexes);

	/** * Float数值范围内并返回引用多余的数 
	* Index 目标值
	* Min 最小值
	* Max 最大值
	* Indexes 多余的数
	* return 返回限制值
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static float ClampLimitFloatScopes(float Index, float Min, float Max, float& Indexes);

	/** * 数值范围内并返回引用有效数
	* Index 目标值
	* Min 最小值
	* Max 最大值
	* Indexes 有效数,默认填入添加的数值
	* return 返回限制值
	*/
	template<typename T >
	static T AddClampLimitScopes(T Index, T Min, T Max, T& AddIndexes)
	{
		T TIndex = Index + AddIndexes;
		if (TIndex < Min)
		{
			AddIndexes = Min - Index;
			return Min;
		}
		if (TIndex > Max)
		{
			AddIndexes = Max - Index;
			return Max;
		}
		return TIndex;
	}


	/** * 判断是否是范围内的值 
	* Index 目标值
	* Min 最小值
	* Max 最大值
	* return 返回是否在限制内
	*/
	template< class T >
	static bool IsClampLimitScopes(T Index, T Min, T Max)
	{
		return Index >= Min && Index <= Max;
	}

	/** * Int判断是否是范围内的值 
	* Index 目标值
	* Min 最小值
	* Max 最大值
	* return 返回是否在限制内
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static bool IsClampLimitIntScopes(int Index, int Min, int Max);

	/** * Float判断是否是范围内的值 
	* Index 目标值
	* Min 最小值
	* Max 最大值
	* return 返回是否在限制内
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static bool IsClampLimitFloatScopes(float Index, float Min, float Max);

	/** * 获取缓慢数值 
	* Numerical 目标值
	* EndNumerical 结束值
	* SlowNumerical 插值数
	* return 返回得到的插值 
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static float GetSlowNumerical(float Numerical, float EndNumerical, float SlowNumerical);

	/** * 删除组件的所有子类 
	* SceneComponent 目标组件
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static void DestroyComponentAllChild(const USceneComponent* SceneComponent);

	/** * 字符串转换Vector 
	* SourceString 需要转化的字符串
	* return 返回Vector
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static FVector StringToVector(const FString& SourceString);

	/** * 字符串转换Vector2D 
	* SourceString 需要转化的字符串
	* return 返回Vector2D
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static FVector2D StringToVector2D(const FString& SourceString);


	/** * Vector2DXY交换 
	* SwapVector2D 目标 Vector2D
	* return 返回交换后的Vector2D
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static FVector2D Vector2DSwapXY(const FVector2D& SwapVector2D);

	/** * 获取所有组件 
	* Actor 目标演员
	* ComponentClass 组件类型
	* return 返回获取组件组
	*/
	static TArray<UActorComponent*> GetActorComponents(const AActor* Actor, const TSubclassOf<UActorComponent>& ComponentClass);


	/** * 获取该Actor对应的所有组件,包括绑定
	* Actor 目标演员
	* ComponentClass 组件类型
	* return 返回获取组件组
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static TArray<UActorComponent*> GetActorAllComponents(const AActor* Actor, const TSubclassOf<UActorComponent>& ComponentClass);

	/** * 获取该Actor对应的Tag标签可选数量索引组件 
	* Actor 目标演员
	* Tag 对应的标签
	* Index 获得数量的限制
	* return 返回获取组件组
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static TArray<UActorComponent*> GetActorComponentsByTag(const AActor* Actor, const FName& Tag, int Index = -1);

	/** * 获取该Actor对应的Tag标签组件 
	* Actor 目标演员
	* Tag 对应的标签
	* return 返回获取组件组
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static UActorComponent* GetActorComponentByTag(const AActor* Actor, const FName& Tag);

	/** * 获取该Actor控制器 
	* Actor 目标演员
	* return 返回获取控制器 
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static AController* GetActorController(AActor* Actor);

	/** * 获取该Actor玩家控制器 
	* Actor 目标演员
	* return 返回获取玩家控制器 
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static APlayerController* GetActorPlayerController(AActor* Actor);

	/** * 获取该Actor玩家控制器是否本地 
	* Actor 目标演员
	* return 返回是否本地 
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static bool GetActorIsLocalPlayerController(AActor* Actor);



	/** * 获取组内部分/全部值 
	* Index 开始索引
	* EndIndex 结束索引
	* return 返回获取字符串组
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static TArray<FString> GetStringsScopes(const TArray<FString>& Strings, int Index = 0, int EndIndex = -1);

	/** * 字符串组转名字组 
	* TArray<FString> To TArray<FName>
	* return 返回转化名字组
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static TArray<FName> StringsToNames(const TArray<FString>& Strings);

	/** * 名字组转字符串组 
	* TArray<FName> To TArray<FString>
	* return 返回转化字符串组
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static TArray<FString> NamesToStrings(const TArray<FName>& Strings);

	/** * 获取名字字符串组对应名字索引
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (StringStrings.Name)
	* return 返回获取索引
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static int GetStringStringsIndex(const TArray<FStringStrings>& StringStringsArray, const FString& Name);

	/** * 获取名字字符串组对应名字索引数据
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (StringStrings.Name)
	* return 返回获取索引字符串值
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static FString GetStringStringsIndexData(const TArray<FStringStrings>& StringStringsArray, const FString& Name);

	/** * 设置StringStringsArray Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll 
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (StringStrings.Name)
	* InString 是输入的值
	* Cmd 是操作指令,Set,SetAll,Add,AddUnique,Remove,RemoveAll
	* return 返回获取索引
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static int SetStringStringsArray(TArray<FStringStrings>& StringStringsArray, const FString& Name, const FString& InString, ESetCmd SetCmd = ESetCmd::Set);

	/** * 获取附近落地位置,射线获取玩家附加可以落点的位置
	* Location 初始射线位置
	* Forward 初始射线方向
	* TraceTypeQuerys 响应的射线类型
	* ActorsToIgnore 忽略的演员组
	* Distance 射线距离
	* Scope 射线范围
	* DropDistance 射线的落下的距离
	* Num 重试次数
	* return 返回最终位置
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static FVector FrontScopeRay(UObject* World, const FVector& Location, const FVector& Forward, const TEnumAsByte<ETraceTypeQuery>& TraceTypeQuerys, const TArray<AActor*>& ActorsToIgnore, float Distance = 100, float Scope = 80, float DropDistance = 200, int Num = 22);

	/** * 获取XY限制大小 
	* X,Y 是大小
	* XMax,YMax,最大值返回值值不会超过这些值
	* 返回的也是对应比例的大小
	* return 返回限制大小
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static FVector2D GetXYClampSize(float X, float Y, float XMax, float YMax);

	/** * 设置控制
	* World 目标世界
	* bControl 是否控制
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static void SetInputModeAndMouse(UObject* World, bool bControl);

	/** * 获取名字字符串组对应名字索引
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (Name)
	* return 返回获取索引
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static int GetStringColorsNameIndex(const TArray<FStringColor>& InStringColorArray, const FName& InName);

	/** * 获取名字字符串组对应名字索引数据
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (Name)
	* return 返回获取索引字符串值
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static FStringColor GetStringColorsNameIndexData(const TArray<FStringColor>& InStringColorArray, const FName& InName);

	/** * 设置Array Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (Name)
	* return 返回获取索引  C++ 结构体里如何添加该结构体Array时的函数
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static int SetStringColorsNameData(UPARAM(ref) TArray<FStringColor>& InStringColorArray, const FStringColor& InStringColor);


	/** * 获取名字字符串组对应名字索引
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (Name)
	* return 返回获取索引
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static int GetStringImageDatasNameIndex(const TArray<FStringImageData>& InStringImageDataArray, const FName& InName);

	/** * 获取名字字符串组对应名字索引数据
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (Name)
	* return 返回获取索引字符串值
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static FStringImageData GetStringImageDatasNameIndexData(const TArray<FStringImageData>& InStringImageDataArray, const FName& InName);

	/** * 设置Array Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (Name)
	* return 返回获取索引  C++ 结构体里如何添加该结构体Array时的函数
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static int SetStringImageDatasNameData(UPARAM(ref) TArray<FStringImageData>& InStringImageDataArray, const FStringImageData& InStringImageData);

	/** * 获取名字字符串组对应名字索引
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (Name)
	* return 返回获取索引
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static bool RemoveStringImageDatasName(UPARAM(ref) TArray<FStringImageData>& InStringImageDataArray, const FName& InName);

	/** * 函数来生成一个带有偏置的随机数值
	* MinValue 最小值
	* MaxValue 最大值	
	* RareValue 0~10值越大值返回的随机值越接近最大值
	* return 返回是否在限制内
	*/
	template< class T >
	static T GenerateWeightedRandom(T MinValue, T MaxValue, float RareValue)
	{
		return FMath::Lerp(MaxValue, MinValue, FMath::Pow(FMath::FRand(), RareValue));;
	}
	/** * 函数来生成一个带有偏置的随机数值
	* MinValue 最小值
	* MaxValue 最大值
	* RareValue 0~10值越大值返回的随机值越接近最大值
	* return 返回是否在限制内
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static float GenerateWeightedRandomFloat(float MinValue, float MaxValue, float RareValue);

	/** * 获取字符串组有效值
	* C++ 使用的,本插件自己使用的并不开放蓝图,不建议调用,所以并不再多解释
	*/
	static FString StringsGet(const TArray<FString>& Strings, int Index = 0);

	/** * 获取名字组有效值
	* C++ 使用的,本插件自己使用的并不开放蓝图,不建议调用,所以并不再多解释
	*/
	static FName NamesGet(const TArray<FName>& Names, int Index);


	/** * 屏幕打印字符串 
	* C++ 使用的,本插件自己使用的并不开放蓝图,不建议调用,所以并不再多解释
	*/
	static void PrintString(const UObject* Object, const FString& String, float Tim = 2.0f, const FName Key = NAME_None);

	/** * 延迟时间,转接对应名字的函数 
	* C++ 使用的,本插件自己使用的并不开放蓝图,不建议调用,所以并不再多解释
	*/
	static void CustomDelay(UObject* WorldContextObject, float Duration, const FString& ExecutionFunction);


	/** * 生成的演员 
	* C++ 使用的,本插件自己使用的并不开放蓝图,不建议调用,所以并不再多解释
	*/
	static AActor* SpawnActor(UObject* World, UClass* Class, const FVector& Location, const FQuat& Rotation = FQuat({ 0.0f, 0.0f, 0.0f }), const FVector& Scale3D = FVector(1.0f, 1.0f, 1.0f), AActor* Owner = nullptr, APawn* Instigator = nullptr);
	static AActor* SpawnActor(UObject* World, UClass* Class, const FTransform& Transform, AActor* Owner = nullptr, APawn* Instigator = nullptr);
	static AActor* SpawnActor(UObject* World, UClass* Class, const FVector& Location, const FRotator& Rotation = FRotator(0.0f, 0.0f, 0.0f), const FVector& Scale3D = FVector(1.0f, 1.0f, 1.0f), AActor* Owner = nullptr, APawn* Instigator = nullptr);
	static AActor* SpawnActor(UObject* World, TSoftClassPtr<AActor> SoftActorClass, const FVector& Location, const FRotator& Rotation, const FVector& Scale3D, AActor* Owner, APawn* Instigator);


	/** * 生成贴花并映射位置 
	* C++ 使用的,本插件自己使用的并不开放蓝图,不建议调用,所以并不再多解释
	*/
	static UDecalComponent* SpawnDecalAtLocation(AActor* Owner, UMaterialInterface* MaterialInterface, FVector Location, FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f), FVector Scale3D = FVector(1.0f, 1.0f, 1.0f), float LifeSpan = 0, float FadeScreeSize = 0);
	static UDecalComponent* SpawnDecalAtLocation(AActor* Owner, UMaterialInterface* MaterialInterface, FVector Location, FVector Rotation = FVector(0.0f, 0.0f, 0.0f), FVector Scale3D = FVector(1.0f, 1.0f, 1.0f), float LifeSpan = 0, float FadeScreeSize = 0);

	/** * 生成贴花并绑定物体 
	* C++ 使用的,本插件自己使用的并不开放蓝图,不建议调用,所以并不再多解释
	*/
	static UDecalComponent* SpawnDecalAttached(AActor* Owner, UMaterialInterface* MaterialInterface, USceneComponent* AttachComponent, FName AttachPointName, FVector Location, FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f), FVector Scale3D = FVector(1.0f, 1.0f, 1.0f), EAttachLocation::Type LocationType = EAttachLocation::KeepRelativeOffset, float LifeSpan = 0, float FadeScreeSize = 0);
	static UDecalComponent* SpawnDecalAttached(AActor* Owner, UMaterialInterface* MaterialInterface, USceneComponent* AttachComponent, FName AttachPointName, FVector Location, FVector Rotation = FVector(0.0f, 0.0f, 0.0f), FVector Scale3D = FVector(1.0f, 1.0f, 1.0f), EAttachLocation::Type LocationType = EAttachLocation::KeepRelativeOffset, float LifeSpan = 0, float FadeScreeSize = 0);



	//#include "Runtime/Engine/Classes/Engine/AssetManager.h"  //异步加载资源的头文件 
	/** * 字符串异步加载 
	* C++ 使用的,本插件自己使用的并不开放蓝图
	*/
	//UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	//static void StringAssetLoad(const FString& String, FStreamableDelegate StreamableDelegate);

	template<typename T>
	static int SetNameArray(TArray<FName>& InNames, TArray<T>& InArray, const FName& InName, const T& Data, bool Remove = false)
	{
		if (InName.IsNone())
		{
			return -1;
		}
		int Index = InNames.Find(InName);
		if (Remove)  /** 判断是否删除 */
		{
			InNames.RemoveAt(Index);
			InArray.RemoveAt(Index);
			return -1;
		}
		if (Index == -1)
		{
			Index = InNames.Add(InName);
		}
		if (!InArray.IsValidIndex(Index))
		{
			InArray.SetNum(Index + 1);
		}
		InArray[Index] = Data;
		return Index;
	}

	/** *
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|DataTable")
	static bool CompositeDataTableAddDataTable(UCompositeDataTable* InCompositeDataTable, UDataTable* TableToAdd);

	/** *
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|DataTable")
	static bool CompositeDataTableRemoveDataTable(UCompositeDataTable* InCompositeDataTable, UDataTable* TableToRemove);


	/** *
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static TArray<FAssetData> FindPathAssets(const FName& directoryPath, bool bRecursive = false);

	/** *
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static TArray<FName> FindSubPaths(const FName& PathName, bool bRecursive = false);

	/** * 获取拥有者是否拥有客户端
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static bool IsOwnerClient(AActor* InOwner);


	/** * 
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static UActorComponent* AddSoftActorComponent(AActor* InOwner,TSoftClassPtr<UActorComponent> InActorComponentSoftClassPtr);
	


	/** *
	*/
	//UFUNCTION(BlueprintCallable, Category = "Multithreading")
	//static void PerformHeavyTaskAsync1(UObject* InObject, FName TaskAsyncFunction, FName ReturnFunction)
	//{
	//	if (InObject == nullptr)
	//	{
	//		UE_LOG(LogTemp, Log, TEXT("InObject = Null")); 
	//		return;
	//	}
	//	// 启动一个异步任务来执行繁重的计算
	//	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [InObject, TaskAsyncFunction, ReturnFunction]()
	//		{

	//			if (InObject && !TaskAsyncFunction.IsNone())
	//			{
	//				UFunction* BlueprintFunction = InObject->FindFunction(TaskAsyncFunction);

	//				if (BlueprintFunction)
	//				{
	//					// 4. 执行该函数
	//					// 准备参数（假设蓝图函数接受一个 int32 参数）
	//					//struct
	//					//{
	//					//	int32 Value;
	//					//} Params;

	//					//Params.Value = 42;  // 设置参数值

	//					// 使用 FFrame 来调用蓝图中的函数
	//					UE_LOG(LogTemp, Log, TEXT("%s->TaskAsync = Paly"), *InObject->GetName());
	//					InObject->ProcessEvent(BlueprintFunction, nullptr);
	//				}
	//			}
	//			UE_LOG(LogTemp, Log, TEXT("AsyncTask = GameThread = Play"));
	//			if (!GWorld || !GWorld->HasBegunPlay())
	//			{
	//				UE_LOG(LogTemp, Log, TEXT("Editor or Game is closing, stopping thread..."));
	//				return;  // 退出后台任务
	//			}
	//			// 执行计算完之后的回调（返回主线程）
	//			AsyncTask(ENamedThreads::GameThread, [InObject, ReturnFunction]()
	//				{
	//					// 在主线程执行结果处理
	//					if (InObject && !ReturnFunction.IsNone())
	//					{
	//						UFunction* BlueprintFunction = InObject->FindFunction(ReturnFunction);

	//						if (BlueprintFunction)
	//						{
	//							// 4. 执行该函数
	//							// 准备参数（假设蓝图函数接受一个 int32 参数）
	//							//struct
	//							//{
	//							//	int32 Value;
	//							//} Params;

	//							//Params.Value = 42;  // 设置参数值

	//							// 使用 FFrame 来调用蓝图中的函数
	//							InObject->ProcessEvent(BlueprintFunction, nullptr);
	//						}
	//						UE_LOG(LogTemp, Log, TEXT("%s->TaskAsync = End"), InObject ? *InObject->GetName() : TEXT("???"));
	//					}
	//				});
	//		});
	//}



	//DECLARE_DYNAMIC_DELEGATE(FBlueprintDelegate);

	//UFUNCTION(BlueprintCallable, Category = "Multithreading")
	//static void PerformHeavyTaskAsyncBlueprintDelegate(FBlueprintDelegate BlueprintDelegateA, FBlueprintDelegate BlueprintDelegateB)
	//{
	//	// 启动一个异步任务来执行繁重的计算
	//	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [BlueprintDelegateA, BlueprintDelegateB]()
	//		{
	//			//事件A是否绑定
	//			if (BlueprintDelegateA.IsBound())
	//			{
	//				//事件A执行
	//				BlueprintDelegateA.Execute();
	//			}
	//			//事件B是否 空 绑定,防止中途编辑器退出游戏
	//			if (!BlueprintDelegateB.IsBound())
	//			{
	//				return;
	//			}
	//			// 执行计算完之后的回调（返回主线程）
	//			AsyncTask(ENamedThreads::GameThread, [BlueprintDelegateB]()
	//				{
	//					//事件B是否绑定
	//					if (BlueprintDelegateB.IsBound())
	//					{
	//						//事件B执行
	//						BlueprintDelegateB.Execute();
	//					}
	//				});
	//		});
	//};


	//// 定义一个带有一个 int 参数的委托
	//DECLARE_DYNAMIC_DELEGATE_OneParam(FBlueprintDelegateInt, int32, Value);

	//UFUNCTION(BlueprintCallable, Category = "Multithreading")
	//static void PerformHeavyTaskAsyncBlueprintDelegateInt32(FBlueprintDelegateInt BlueprintDelegateA, int InNumA, FBlueprintDelegate BlueprintDelegateB)
	//{
	//	// 启动一个异步任务来执行繁重的计算
	//	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [BlueprintDelegateA, InNumA, BlueprintDelegateB]()
	//		{
	//			//事件A是否绑定
	//			if (BlueprintDelegateA.IsBound())
	//			{
	//				//事件A执行
	//				BlueprintDelegateA.Execute(InNumA);
	//			}
	//			//事件B是否 空 绑定,防止中途编辑器退出游戏
	//			if (!BlueprintDelegateB.IsBound())
	//			{
	//				return;
	//			}
	//			// 执行计算完之后的回调（返回主线程）
	//			AsyncTask(ENamedThreads::GameThread, [BlueprintDelegateB]()
	//				{
	//					//事件B是否绑定
	//					if (BlueprintDelegateB.IsBound())
	//					{
	//						//事件B执行
	//						BlueprintDelegateB.Execute();
	//					}
	//				});
	//		});
	//};

}; 
