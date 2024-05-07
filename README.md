# UniversalFunctionLibrary

> - Name: UniversalFunctionLibrary
> - description: UniversalFunctionLibrarys.h  header file contains
>> - Paths convert various soft references
>> - Path to load the class or resource
>> - Create a time UID string
>> - Quick function for player ray
>> - A function that limits the value and returns the remainder
>> - Get the controller quickly
>> - String group handler functions, such as converting TArray<FName>
> - description: UniversalWidgetFunctionLibrary.h H header file contains
>> - Get control location, support nesting
>> - Set the Image resource function quickly
>> - Quick access to mouse/viewport functions
> - Note: Some C++ functions, which are not open blueprints used by this plug-in, are not recommended to be called

# 万能函数库

> - 名字: 万能函数库
> - 描述: UniversalFunctionLibrarys.h 头文件 包含
>> - 路径转化各种软引用
>> - 路径加载类或资源
>> - 创建时间UID字符串
>> - 玩家射线的快捷函数
>> - 限制值并返回多余数的函数
>> - 快捷的获取控制器
>> - 字符串组的处理函数,如转化TArray<FName>
> - 描述: UniversalWidgetFunctionLibrary.h 头文件 包含
>> - 获取控件位置,支持嵌套
>> - 快捷设置Image资源函数
>> - 快捷获取鼠标/视口函数
> - 注释: 部分C++函数,本插件自己使用的并不开放蓝图,不建议调用


## Engine version (>= 5.3.0)

> - Copyright: Aimo\_皑墨
> - Open source protocol: MIT License
> - QQ: 2422489737
> - wechat: Aimo_TvT
> - Email: 2422489737@qq.com
> - BiLiBiLi (哔哩哔哩) address: https://space.bilibili.com/146962867
> - Open source address(Git): https://github.com/AimoTvT/UniversalFunctionLibrary
> - We welcome the contributions of powerful movers and movers to join this plugin
> - Build powerful plugins together!!


## 引擎版本( >= 5.3.0 )

> - 版权所有权: Aimo\_皑墨
> - 开源协议: MIT License
> - QQ: 2422489737
> - 微信: Aimo_TvT
> - 邮箱: 2422489737@qq.com
> - BiLiBiLi(哔哩哔哩)地址: https://space.bilibili.com/146962867
> - 开源地址(Git): https://github.com/AimoTvT/UniversalFunctionLibrary
> - 欢迎有实力的大佬/萌新加入本插件的贡献
> - 一起打造强大的插件!!!

## 英文注解
~~~ C++
"UniversalFunctionLibrarys.h"

/** * String conversion SoftObjectPtr
* PathString Class path
* return Soft reference class
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
static TSoftClassPtr<UObject> StringCastTSoftClassPtr(const FString& PathString);

/** * String conversion SoftObjectPtr
* PathString Resource path
* return Soft reference
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
static TSoftObjectPtr<UObject> StringCastTSoftObjectPtr(const FString& PathString);

/** * String conversion FSoftObjectPath
* PathString Resource path
* return Returns the soft reference path
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
static FSoftObjectPath StringCastFSoftObjectPath(const FString& PathString);


/** * string Load Class
* PathString Class path
* return class pointer
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Load")
static UClass* StringLoadClassAsset(const FString& PathString);

/** ** string Load Object
* PathString Resource path
* return Object pointer
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Load")
static UObject* StringLoadObjectAsset(const FString& PathString);


/** * Parse the string */

/** * Gets the character string substring and skips the sensitive substring
* C++ is used, this plug-in is used by itself, it is not recommended to call, so it is no longer explained
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static int FindStringParseIndex(const FString& SourceString, const FString& FindString, const FString& SensitiveString, int Index = -1);

/** * Parsing string, separator support,; "{}
* C++ is used, this plug-in is used by itself, it is not recommended to call, so it is no longer explained
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static TArray<FString> StringParseIntoArray(const FString& SourceString, int MaxIndex = -1);

/** * Parsing string, separator support,; "{}
* C++ is used, this plug-in is used by itself, it is not recommended to call, so it is no longer explained
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static FString GetIndexStringParseIntoArray(const FString& SourceString, int MaxIndex = 1);

/** * Parsing into long strings, delimiter supported; "{}
* C++ is used, this plug-in is used by itself, it is not recommended to call, so it is no longer explained
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static TArray<FString> StringParseIntoArrayLong(const FString& SourceString, int MaxIndex = -1);

/** ** Parse whether the first character is equal, if equal, read whether the last bit ==; ", true returns the index
* C++ is used, this plug-in is used by itself, it is not recommended to call, so it is no longer explained
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static int FindBeginString(const TArray<FString>& Strings, const FString& SourceString);

/** * Parse whether the first character is equal, if equal, read whether the last bit ==; ", true returns the index group
* C++ is used, this plug-in is used by itself, it is not recommended to call, so it is no longer explained
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static TArray<int> FindBeginStrings(const TArray<FString>& Strings, const FString& SourceString);

/** * Appends parsable strings
* C++ is used, this plug-in is used by itself, it is not recommended to call, so it is no longer explained
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static FString AppendParseString(const FString& NameString, const FString& DataString);

/** * Appends parsable string groups
* C++ is used, this plug-in is used by itself, it is not recommended to call, so it is no longer explained
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static FString AppendParseStrings(const FString& NameString, const FString& DataNameString, const FString& DataString, bool ChildAppendParse = true);

/** * Appends parsable string groups
* C++ is used, this plug-in is used by itself, it is not recommended to call, so it is no longer explained
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|StringParse")
static int SetStringsDataString(TArray<FString>& Strings, const FString& DataNameString, const FString& DataString, const FString& Cmd = TEXT("Set"));

/** * Returns a time string, delimiter (,), and optional ending semicolon
* return time character string
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|String")
static FString GetNowTimerToString();

/** * Return time as unique UID, optional complex random ending, optional ending semicolon
* bComplex
* Whether bEndSemicolon is good (;)
* return Specifies the return value encoding string
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|String")
static FString NewUIDToString(bool bComplex = false, bool bEndSemicolon = false);

/** * Player camera X-ray detection
* Owner Target player
* OutHit ray return value
* ActorsToIgnore ignores the cast
* TraceTypeQuery ray type
* Distance Indicates the distance of the ray
* return Indicates whether the return is detected
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Player")
static bool PlayerCameraRay(AActor* Owner, FHitResult& OutHit, TArray<AActor*> ActorsToIgnore, ETraceTypeQuery TraceTypeQuery, float Distance = 500);

/** ** value range and return references to excess number
* Index Indicates the target value
* Min Minimum value
* Max Max
* Indexes Extra indexes
* return Returns the limit value
*/
template< class T >
static T ClampLimitScopes(T Index, T Min, T Max, T& Indexes);

/** * Int in the range of values and returns references to excess numbers
* Index Indicates the target value
* Min Minimum value
* Max Max
* Indexes Extra indexes
* return Returns the limit value
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static int ClampLimitIntScopes(int Index, int Min, int Max, int& Indexes);

/** ** Float within a range of values and returns references to excess numbers
* Index Indicates the target value
* Min Minimum value
* Max Max
* Indexes Extra indexes
* return Returns the limit value
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static float ClampLimitFloatScopes(float Index, float Min, float Max, float& Indexes);

/** * Determines whether the value is in the range
* Index Indicates the target value
* Min Minimum value
* Max Max
* return Whether the return is within the limit
*/
template< class T >
static bool IsClampLimitScopes(T Index, T Min, T Max);

/** * Int Specifies whether the value is in the range
* Index Indicates the target value
* Min Minimum value
* Max Max
* return Whether the return is within the limit
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static bool IsClampLimitIntScopes(int Index, int Min, int Max);

/** * Float determines whether the value is in the range
* Index Indicates the target value
* Min Minimum value
* Max Max
* return Whether the return is within the limit
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static bool IsClampLimitFloatScopes(float Index, float Min, float Max);

/** * Gets the slow value
* Numerical target value
* EndNumerical end value
* SlowNumerical interpolation number
* return Returns the resulting interpolation
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static float GetSlowNumerical(float Numerical, float EndNumerical, float SlowNumerical);

/** * Deletes all subclasses of a component
* SceneComponent target component
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static void DestroyComponentAllChild(const USceneComponent* SceneComponent);

/** * String conversion Vector
* SourceString String to be converted
* return Returns the Vector
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static FVector StringToVector(const FString& SourceString);

/** * Convert the string to Vector2D
* SourceString String to be converted
* return Returns Vector2D
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static FVector2D StringToVector2D(const FString& SourceString);


/** * Vector2DXY exchange
* SwapVector2D Target Vector2D
* return Returns Vector2D after the swap
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static FVector2D Vector2DSwapXY(const FVector2D& SwapVector2D);

/** * Get all components
* Actor Target actor
* ComponentClass Component type
* return Returns the component group
*/
static TArray<UActorComponent*> GetActorComponents(const AActor* Actor, const TSubclassOf<UActorComponent>& ComponentClass);


/** * Gets all components corresponding to the Actor, including bindings
* Actor Target actor
* ComponentClass Component type
* return Returns the component group
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static TArray<UActorComponent*> GetActorAllComponents(const AActor* Actor, const TSubclassOf<UActorComponent>& ComponentClass);

/** * Gets the Tag tag Optional quantity index component for the Actor
* Actor Target actor
* Tag Indicates the corresponding tag
* Index limit on the number of items obtained
* return Returns the component group
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static TArray<UActorComponent*> GetActorComponentsByTag(const AActor* Actor, const FName& Tag, int Index = -1);

/** * Obtains the Tag tag component corresponding to the Actor
* Actor Target actor
* Tag Indicates the corresponding tag
* return Returns the component group
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static UActorComponent* GetActorComponentByTag(const AActor* Actor, const FName& Tag);

/** * Gets the Actor controller
* Actor Target actor
* return Returns the controller
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static AController* GetActorController(AActor* Actor);

/** * Gets the Actor Player controller
* Actor Target actor
* return Returns to get the player controller
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static APlayerController* GetActorPlayerController(AActor* Actor);

/** * Gets whether the Actor player controller is local
* Actor Target actor
* return Whether the return is local
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static bool GetActorIsLocalPlayerController(AActor* Actor);



/** * Gets some/all values within the group
* Index Indicates the start index
* EndIndex Indicates the end index
* return Returns the string group
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static TArray<FString> GetStringsScopes(const TArray<FString>& Strings, int Index = 0, int EndIndex = -1);

/** * The string group is converted to the name group
* TArray<FString> To TArray<FName>
* return Returns the conversion name group
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static TArray<FName> StringsToNames(const TArray<FString>& Strings);

/** * Name group to string group
* TArray<FName> To TArray<FString>
* return Returns the converted string group
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static TArray<FString> NamesToStrings(const TArray<FName>& Strings);

/** * Name group to string group
* TArray<FName> To TArray<FString>
* return Returns the converted string group
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static int GetNameStringsIndex(TArray<FNameStrings>& NameStringsArray, const FString& Name);

/* * * Set NameStringsArray Cmd: Set, SetAll, Add, AddU, Remove, RemoveAll
* The name string group structure is used to modify the parsing
* Name Name of the string group corresponding to the name (NameStrings.Name)
* InString is the input value
* Cmd is the operating instructions, the Set, SetAll, Add, AddUnique, Remove, RemoveAll
* return Returns the index
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static int SetNameStringsArray(TArray<FNameStrings>& NameStringsArray, const FString& Name, const FString& InString, const FString& Cmd = "Set");

/** * Gets the nearby landing position, and the ray gets the position where the player can attach the landing spot
* Location Initial ray location
* Forward Initial ray direction
* TraceTypeQuerys response ray type
* ActorsToIgnore ignored cast members
* Distance Indicates the distance of the ray
* DropDistance The falling distance of the ray
* Scope Ray range
* Num Number of retries
* return Returns the final position
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Miscellaneous")
static FVector FrontScopeRay(UObject* World, const FVector& Location, const FVector& Forward, const TEnumAsByte<ETraceTypeQuery>& TraceTypeQuerys, const TArray<AActor*>& ActorsToIgnore, float Distance = 100, float DropDistance = 200, float Scope = 80, int Num = 22);

/** * Gets the XY limit size
* X,Y is the magnitude
* XMax,YMax, maximum Return value The value does not exceed these values
* Returns the size of the corresponding scale
* return Returns the limit size
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static FVector2D GetXYClampSize(float X, float Y, float XMax, float YMax);


/** * Gets a valid value for the string group
* C++ is used, this plug-in itself is not open blueprint, not recommended to call, so no more explanation
*/
static FString StringsGet(const TArray<FString>& Strings, int Index = 0);

/** * Gets a valid value for the name group
* C++ is used, this plug-in itself is not open blueprint, not recommended to call, so no more explanation
*/
static FName NamesGet(const TArray<FName>& Names, int Index);


/** * Screen print string
* C++ is used, this plug-in itself is not open blueprint, not recommended to call, so no more explanation
*/
static void PrintString(const UObject* Object, const FString& String, float Tim = 2.0f, const FName Key = NAME_None);

/** * Delay time to transfer the function with the corresponding name
* C++ is used, this plug-in itself is not open blueprint, not recommended to call, so no more explanation
*/
static void CustomDelay(UObject* WorldContextObject, float Duration, const FString& ExecutionFunction);


/** * Generated actors
* C++ is used, this plug-in itself is not open blueprint, not recommended to call, so no more explanation
*/
static AActor* SpawnActor(UObject* World, UClass* Class, const FVector& Location, const FQuat& Rotation = FQuat({ 0.0f, 0.0f, 0.0f }), const FVector& Scale3D = FVector(1.0f, 1.0f, 1.0f), AActor* Owner = nullptr, APawn* Instigator = nullptr);
static AActor* SpawnActor(UObject* World, UClass* Class, const FTransform& Transform, AActor* Owner = nullptr, APawn* Instigator = nullptr);
static AActor* SpawnActor(UObject* World, UClass* Class, const FVector& Location, const FRotator& Rotation = FRotator(0.0f, 0.0f, 0.0f), const FVector& Scale3D = FVector(1.0f, 1.0f, 1.0f), AActor* Owner = nullptr, APawn* Instigator = nullptr);
static AActor* SpawnActor(UObject* World, TSoftClassPtr<AActor> SoftActorClass, const FVector& Location, const FRotator& Rotation, const FVector& Scale3D, AActor* Owner, APawn* Instigator);


/** * Generates decals and maps locations
* C++ is used, this plug-in itself is not open blueprint, not recommended to call, so no more explanation
*/
static UDecalComponent* SpawnDecalAtLocation(AActor* Owner, UMaterialInterface* MaterialInterface, FVector Location, FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f), FVector Scale3D = FVector(1.0f, 1.0f, 1.0f), float LifeSpan = 0, float FadeScreeSize = 0);
static UDecalComponent* SpawnDecalAtLocation(AActor* Owner, UMaterialInterface* MaterialInterface, FVector Location, FVector Rotation = FVector(0.0f, 0.0f, 0.0f), FVector Scale3D = FVector(1.0f, 1.0f, 1.0f), float LifeSpan = 0, float FadeScreeSize = 0);

/** * Creates decals and binds objects
* C++ is used, this plug-in itself is not open blueprint, not recommended to call, so no more explanation
*/
static UDecalComponent* SpawnDecalAttached(AActor* Owner, UMaterialInterface* MaterialInterface, USceneComponent* AttachComponent, FName AttachPointName, FVector Location, FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f), FVector Scale3D = FVector(1.0f, 1.0f, 1.0f), EAttachLocation::Type LocationType = EAttachLocation::KeepRelativeOffset, float LifeSpan = 0, float FadeScreeSize = 0);
static UDecalComponent* SpawnDecalAttached(AActor* Owner, UMaterialInterface* MaterialInterface, USceneComponent* AttachComponent, FName AttachPointName, FVector Location, FVector Rotation = FVector(0.0f, 0.0f, 0.0f), FVector Scale3D = FVector(1.0f, 1.0f, 1.0f), EAttachLocation::Type LocationType = EAttachLocation::KeepRelativeOffset, float LifeSpan = 0, float FadeScreeSize = 0);




/** * Widget */

"UniversalWidgetFunctionLibrary.h"

/** * Gets the parent class location
* Widget target control
* return Indicates the return position
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static FVector2D GetParentLocation(UWidget* Widget);

/** * Gets all parent class locations
* Widget target control
* return Indicates the return position
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static FVector2D GetAllParentLocation(UWidget* Widget);

/** * Set the Widget control location
* Widget target control
* Position Target position
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static void SetWidgetPosition(UWidget* Widget, const FVector2D& Position);

/** * Set the Widget control location
/** * Set the Image resource
* Widget target control
* InSize Target size
* SizeBox Whether the size box wraps the * Widget target control
* Position Target position
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static void SetWidgetSize(UWidget* Widget, const FVector2D& InSize, USizeBox* SizeBox = nullptr);

/** * Set the Image resource
* Widget target control
* Resource Target resource
* ParameterName Dynamic material parameter name
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static void SetImageResource(UImage* Image, UObject* Resource, const FString& ParameterName = TEXT("MaterialTexture"));

/** * Get mouse position
* WorldContextObject The target world
* bViewportScale Specifies whether to scale the engine
* return Indicates the return position
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static FVector2D GetMousePositionOnViewport(UObject* WorldContextObject, bool bViewportScale = false);

/** * Get viewport position
* WorldContextObject The target world
* return Indicates the return position
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static FVector2D GetViewportSize(UObject* WorldContextObject);

/** * String conversion SoftWidgetObjectPtr
* PathString Class path
* return control soft reference class
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
static TSoftClassPtr<UWidget> StringCastTSoftWidgetClassPtr(const FString& PathString);

/** * String conversion SoftUserWidgetObjectPtr
* PathString Class path
* return Player control soft reference class
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
static TSoftClassPtr<UUserWidget> StringCastTSoftUserWidgetClassPtr(const FString& PathString);

~~~

## 中文注解
~~~ C++
"UniversalFunctionLibrarys.h"

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

/** * 获取XY限制大小, 返回的也是对应比例的大小
* X,Y 是大小 
* XMax,YMax,最大值返回值值不会超过这些值
* return 返回限制大小
*/
UFUNCTION(BlueprintPure, Category = "Aimo|Static|Miscellaneous")
static FVector2D GetXYClampSize(float X, float Y, float XMax, float YMax);


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




/** * 控件 */

"UniversalWidgetFunctionLibrary.h"

/** * 获取父类位置 
* Widget 目标控件
* return 返回位置
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static FVector2D GetParentLocation(UWidget* Widget);

/** * 获取所有父类位置 
* Widget 目标控件
* return 返回位置
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static FVector2D GetAllParentLocation(UWidget* Widget);

/** * 设置Widget控件位置 
* Widget 目标控件
* Position 目标位置
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static void SetWidgetPosition(UWidget* Widget, const FVector2D& Position);

/** * 设置Image大小 
* Widget 目标控件
* InSize 目标大小
* SizeBox 是否尺寸框包裹
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static void SetWidgetSize(UWidget* Widget, const FVector2D& InSize, USizeBox* SizeBox = nullptr);

/** * 设置Image资源 
* Widget 目标控件
* Resource 目标资源
* ParameterName 动态材质参数名称
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static void SetImageResource(UImage* Image, UObject* Resource, const FString& ParameterName = TEXT("MaterialTexture"));

/** * 获取鼠标位置 
* WorldContextObject 目标世界
* bViewportScale 是否引擎缩放	
* return 返回位置
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static FVector2D GetMousePositionOnViewport(UObject* WorldContextObject, bool bViewportScale = false);

/** * 获取视口位置 
* WorldContextObject 目标世界
* return 返回位置
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Wdiget")
static FVector2D GetViewportSize(UObject* WorldContextObject);

/** * 字符串转换 SoftWidgetObjectPtr 
* PathString 类路径
* return 控件软引用类
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
static TSoftClassPtr<UWidget> StringCastTSoftWidgetClassPtr(const FString& PathString);

/** * 字符串转换 SoftUserWidgetObjectPtr 
* PathString 类路径
* return 玩家控件软引用类
*/
UFUNCTION(BlueprintCallable, Category = "Aimo|Static|Cast")
static TSoftClassPtr<UUserWidget> StringCastTSoftUserWidgetClassPtr(const FString& PathString);

~~~