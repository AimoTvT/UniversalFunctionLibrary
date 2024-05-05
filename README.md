# UniversalFunctionLibrary
> - 名字: 万能函数库
> - 描述: 各种函数,精简,实用,目前尚未完善

## Engine version (>= 5.4.0)

> - Copyright: Aimo\_皑墨
> - Open source protocol: MIT License
> - QQ: 2422489737
> - wechat: Aimo_TvT
> - Email: 2422489737@qq.com
> - BiLiBiLi (哔哩哔哩) address: https://space.bilibili.com/146962867
> - Open source address(Git): https://github.com/AimoTvT/UniversalFunctionLibrary
> - We welcome the contributions of powerful movers and movers to join this plugin
> - Build powerful plugins together!!


## 引擎版本( >= 5.4.0 )

> - 版权所有权: Aimo\_皑墨
> - 开源协议: MIT License
> - QQ: 2422489737
> - 微信: Aimo_TvT
> - 邮箱: 2422489737@qq.com
> - BiLiBiLi(哔哩哔哩)地址: https://space.bilibili.com/146962867
> - 开源地址(Git): https://github.com/AimoTvT/UniversalFunctionLibrary
> - 欢迎有实力的大佬/萌新加入本插件的贡献
> - 一起打造强大的插件!!!

~~~ C++
"UniversalFunctionLibrarys.h"

/** * 字符串转换 SoftObjectPtr */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
static TSoftClassPtr<UObject> StringCastTSoftClassPtr(const FString& PathString);

/** * 字符串转换 SoftObjectPtr */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
static TSoftObjectPtr<UObject> StringCastTSoftObjectPtr(const FString& PathString);

/** * 字符串转换 FSoftObjectPath */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
static FSoftObjectPath StringCastFSoftObjectPath(const FString& PathString);


/** * 字符串加载 Class */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Load")
static UClass* StringLoadClassAsset(const FString& PathString);

/** * 字符串加载 Object */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Load")
static UObject* StringLoadObjectAsset(const FString& PathString);


/** * 解析字符串 */

/** * 获取字符串子串,并跳过敏感子串 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static int FindStringParseIndex(const FString& SourceString, const FString& FindString, const FString& SensitiveString, int Index = -1);

/** * 解析字符串,分隔符号支持 , ; " { } */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static TArray<FString> StringParseIntoArray(const FString& SourceString, int MaxIndex = -1);

/** * 解析字符串,分隔符号支持 , ; " { } */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static FString GetIndexStringParseIntoArray(const FString& SourceString, int MaxIndex = 1);

/** * 解析为长字符串,分隔符号支持 ; " { } */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static TArray<FString> StringParseIntoArrayLong(const FString& SourceString, int MaxIndex = -1);

/** * 解析开头字符是否相等,如果相等判读后一位是否== , ; " ,真返回索引 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static int FindBeginString(const TArray<FString>& Strings, const FString& SourceString);

/** * 解析开头字符是否相等,如果相等判读后一位是否== , ; " ,真返回索引组 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static TArray<int> FindBeginStrings(const TArray<FString>& Strings, const FString& SourceString);

/** * 附加可解析字符串 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static FString AppendParseString(const FString& NameString, const FString& DataString);

/** * 附加可解析字符串组 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static FString AppendParseStrings(const FString& NameString, const FString& DataNameString, const FString& DataString, bool ChildAppendParse = true);

/** * 附加可解析字符串组 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static int SetStringsDataString(TArray<FString>& Strings, const FString& DataNameString, const FString& DataString, const FString& Cmd = TEXT("Set"));

/** * 返回时间字符串,分隔符号( , ),可选结尾分号 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|String")
static FString GetNowTimerToString();

/** * 返回时间为唯一UID,可选复杂随机结尾,可选结尾分号 */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|String")
static FString NewUIDToString(bool bComplex = false, bool bEndSemicolon = false);

/** * 玩家摄像机射线检测 */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Player")
static bool PlayerCameraRay(AActor* Owner, FHitResult& OutHit, TArray<AActor*> ActorsToIgnore, ETraceTypeQuery TraceTypeQuery, float Distance = 500);

/** * 数值范围内并返回引用多余的数 */
template< class T >
static T ClampLimitScopes(T Index, T Min, T Max, T& Indexes);

/** * Int数值范围内并返回引用多余的数 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static int ClampLimitIntScopes(int Index, int Min, int Max, int& Indexes);

/** * Float数值范围内并返回引用多余的数 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static float ClampLimitFloatScopes(float Index, float Min, float Max, float& Indexes);

/** * 判断是否是范围内的值 */
template< class T >
static bool IsClampLimitScopes(T Index, T Min, T Max);

/** * Int判断是否是范围内的值 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static bool IsClampLimitIntScopes(int Index, int Min, int Max);

/** * Float判断是否是范围内的值 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static bool IsClampLimitFloatScopes(float Index, float Min, float Max);

/** * 获取缓慢数值 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static float GetSlowNumerical(float Numerical, float EndNumerical, float SlowNumerical);

/** * 显示鼠标并切换UI控制模式不影响移动 */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static void SetInputModeAndMouse(UObject* Object, bool Control);

/** * 删除组件的所有子类 */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static void DestroyComponentAllChild(const USceneComponent* SceneComponent);

/** * 字符串转换Vector */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static FVector StringToVector(const FString& SourceString);

/** * 字符串转换Vector2D */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static FVector2D StringToVector2D(const FString& SourceString);


/** * Vector2DXY交换 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static FVector2D Vector2DSwapXY(const FVector2D& SwapVector2D);

/** * 获取所有组件 */
static TArray<UActorComponent*> GetActorComponents(const AActor* Actor, const TSubclassOf<UActorComponent>& ComponentClass);


/** * 获取该Actor对应的所有组件 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static TArray<UActorComponent*> GetActorAllComponents(const AActor* Actor, const TSubclassOf<UActorComponent>& ComponentClass);

/** * 获取该Actor对应的Tag标签可选数量索引组件 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static TArray<UActorComponent*> GetActorComponentsByTag(const AActor* Actor, const FName& Tag, int Index = -1);

/** * 获取该Actor对应的Tag标签组件 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static UActorComponent* GetActorComponentByTag(const AActor* Actor, const FName& Tag);

/** * 获取该Actor控制器 */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static AController* GetActorController(AActor* Actor);

/** * 获取该Actor玩家控制器 */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static APlayerController* GetActorPlayerController(AActor* Actor);

/** * 获取该Actor玩家控制器是否本地 */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static bool GetActorIsLocalPlayerController(AActor* Actor);


/** * 获取字符串组有效值 */
static FString StringsGet(const TArray<FString>& Strings, int Index = 0);

/** * 获取名字组有效值 */
static FName NamesGet(const TArray<FName>& Names, int Index);

/** * 获取组内部分/全部值 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static TArray<FString> GetStringsScopes(const TArray<FString>& Strings, int Index = 0, int EndIndex = -1);

/** * 字符串组转名字组 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static TArray<FName> StringsToNames(const TArray<FString>& Strings);

/** * 名字组转字符串组 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static TArray<FString> NamesToStrings(const TArray<FName>& Strings);

/** * 获取该Actor玩家控制器是否本地 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static int GetNameStringsIndex(TArray<FNameStrings>& NameStringsArray, const FString& Name);

/** * 设置NameStringsArray Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static int SetNameStringsArray(TArray<FNameStrings>& NameStringsArray, const FString& Name, const FString& InString, const FString& Cmd = "Set");

/** * 获取附近落地位置 */
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static FVector FrontScopeRay(UObject* World, const FVector& Location, const FVector& Forward, const TEnumAsByte<ETraceTypeQuery>& TraceTypeQuerys, const TArray<AActor*>& ActorsToIgnore, float Distance = 100, float DownDistance = 200, float Scope = 80, int Num = 22);

/** * 获取XY限制大小 */
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static FVector2D GetXYClampSize(float X, float Y, float XMax, float YMax);

/** * 屏幕打印字符串 */
static void PrintString(const UObject* Object, const FString& String, float Tim = 2.0f, const FName Key = NAME_None);

/** * 延迟时间,转接对应名字的函数 */
static void CustomDelay(UObject* WorldContextObject, float Duration, const FString& ExecutionFunction);


/** * 生成的演员 */
static AActor* SpawnActor(UObject* World, UClass* Class, const FVector& Location, const FQuat& Rotation = FQuat({ 0.0f, 0.0f, 0.0f }), const FVector& Scale3D = FVector(1.0f, 1.0f, 1.0f), AActor* Owner = nullptr, APawn* Instigator = nullptr);
static AActor* SpawnActor(UObject* World, UClass* Class, const FTransform& Transform, AActor* Owner = nullptr, APawn* Instigator = nullptr);
static AActor* SpawnActor(UObject* World, UClass* Class, const FVector& Location, const FRotator& Rotation = FRotator(0.0f, 0.0f, 0.0f), const FVector& Scale3D = FVector(1.0f, 1.0f, 1.0f), AActor* Owner = nullptr, APawn* Instigator = nullptr);
static AActor* SpawnActor(UObject* World, TSoftClassPtr<AActor> SoftActorClass, const FVector& Location, const FRotator& Rotation, const FVector& Scale3D, AActor* Owner, APawn* Instigator);


/** * 生成贴花并映射位置 */
static UDecalComponent* SpawnDecalAtLocation(AActor* Owner, UMaterialInterface* MaterialInterface, FVector Location, FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f), FVector Scale3D = FVector(1.0f, 1.0f, 1.0f), float LifeSpan = 0, float FadeScreeSize = 0);
static UDecalComponent* SpawnDecalAtLocation(AActor* Owner, UMaterialInterface* MaterialInterface, FVector Location, FVector Rotation = FVector(0.0f, 0.0f, 0.0f), FVector Scale3D = FVector(1.0f, 1.0f, 1.0f), float LifeSpan = 0, float FadeScreeSize = 0);

/** * 生成贴花并绑定物体 */
static UDecalComponent* SpawnDecalAttached(AActor* Owner, UMaterialInterface* MaterialInterface, USceneComponent* AttachComponent, FName AttachPointName, FVector Location, FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f), FVector Scale3D = FVector(1.0f, 1.0f, 1.0f), EAttachLocation::Type LocationType = EAttachLocation::KeepRelativeOffset, float LifeSpan = 0, float FadeScreeSize = 0);
static UDecalComponent* SpawnDecalAttached(AActor* Owner, UMaterialInterface* MaterialInterface, USceneComponent* AttachComponent, FName AttachPointName, FVector Location, FVector Rotation = FVector(0.0f, 0.0f, 0.0f), FVector Scale3D = FVector(1.0f, 1.0f, 1.0f), EAttachLocation::Type LocationType = EAttachLocation::KeepRelativeOffset, float LifeSpan = 0, float FadeScreeSize = 0);



/** * 控件 */

"UniversalWidgetFunctionLibrary.h"

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

~~~