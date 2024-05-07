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


	/** * 字符串转换 SoftObjectPtr 
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
	template< class T >
	static T ClampLimitScopes(T Index, T Min, T Max, T& Indexes);

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

	/** * 判断是否是范围内的值 
	* Index 目标值
	* Min 最小值
	* Max 最大值
	* return 返回是否在限制内
	*/
	template< class T >
	static bool IsClampLimitScopes(T Index, T Min, T Max);

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

	/** * 获取该Actor玩家控制器是否本地 
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* return 返回获取索引
	*/
	UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
	static int GetNameStringsIndex(TArray<FNameStrings>& NameStringsArray, const FString& Name);

	/** * 设置NameStringsArray Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll 
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* InString 是输入的值
	* Cmd 是操作指令,Set,SetAll,Add,AddUnique,Remove,RemoveAll
	* return 返回获取索引
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static int SetNameStringsArray(TArray<FNameStrings>& NameStringsArray, const FString& Name, const FString& InString, const FString& Cmd = "Set");

	/** * 获取附近落地位置,射线获取玩家附加可以落点的位置
	* Location 初始射线位置
	* Forward 初始射线方向
	* TraceTypeQuerys 响应的射线类型
	* ActorsToIgnore 忽略的演员组
	* Distance 射线距离
	* DropDistance 射线的落下的距离
	* Scope 射线范围
	* Num 重试次数
	* return 返回最终位置
	*/
	UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
	static FVector FrontScopeRay(UObject* World, const FVector& Location, const FVector& Forward, const TEnumAsByte<ETraceTypeQuery>& TraceTypeQuerys, const TArray<AActor*>& ActorsToIgnore, float Distance = 100, float DropDistance = 200, float Scope = 80, int Num = 22);

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

};
