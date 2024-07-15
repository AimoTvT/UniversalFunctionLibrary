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

#include "Engine/DataTable.h"
#include "UniversalStruct.generated.h"


/** * 浮点型4 */
USTRUCT(BlueprintType)
struct FFloat4
{
	GENERATED_BODY()

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name")
	float A = 0.0f;
	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "B")
	float B = 0.0f;
	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C")
	float C = 0.0f;
	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "D")
	float D = 0.0f;


};


/** * 设置操作命令,Set,SetAll,Add,AddUnique,Remove,RemoveAll */
UENUM(BlueprintType)
enum class ESetCmd :uint8
{
	/** * 唯一ID //UID */
	Set = 0			UMETA(DisplayName = "Set"),
	SetAll = 1			UMETA(DisplayName = "SetAll"),
	Add = 2			UMETA(DisplayName = "Add"),
	AddUnique = 3			UMETA(DisplayName = "AddUnique"),
	Remove = 4			UMETA(DisplayName = "Remove"),
	RemoveAll = 5			UMETA(DisplayName = "RemoveAll"),
	Swap = 6			UMETA(DisplayName = "Swap"),
	SwapOther = 7			UMETA(DisplayName = "SwapOther")

};


/** * 运算符号枚举 Addition == "+",Subtraction == "-",Multiplication == "*",Division == "/" */
UENUM(BlueprintType)
enum class EArithmeticOperator :uint8
{
	/** * 唯一ID //UID */
	Addition = 0			UMETA(DisplayName = "Addition"),
	Subtraction = 1			UMETA(DisplayName = "Subtraction"),
	Multiplication = 2			UMETA(DisplayName = "Multiplication"),
	Division = 3			UMETA(DisplayName = "Division")

};


/** * 名字字符串组 */
USTRUCT(BlueprintType)
struct FNameStrings : public FTableRowBase
{
	GENERATED_BODY()

	/** * 名字 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name")
	FString Name;

	/** * 字符串组 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Strings")
	TArray<FString> Strings;



	/** * 获取名字字符串组对应名字索引
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* return 返回获取索引
	*/
	static int GetArrayNameIndex(const TArray<FNameStrings>& NameStringsArray, const FString& InName);

	/** * 获取名字字符串组对应名字索引数据
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* return 返回获取索引字符串值
	*/
	static FString GetArrayNameIndexData(const TArray<FNameStrings>& NameStringsArray, const FString& InName);

	/** * 设置NameStringsArray Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* InString 是输入的值
	* Cmd 是操作指令,Set,SetAll,Add,AddUnique,Remove,RemoveAll
	* return 返回获取索引  C++ 结构体里如何添加该结构体Array时的函数
	*/
	static int SetArrayNameData(TArray<FNameStrings>& NameStringsArray, const FString& InName, const FString& InString, ESetCmd SetCmd = ESetCmd::Set);

};




/** * 设置索引值 */
USTRUCT(BlueprintType)
struct FSetIndexInt
{
	GENERATED_BODY()

	/** * 设置操作符 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SetCmd")
	ESetCmd SetCmd;

	/** * 索引 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Index")
	int Index;

	/** * 数值 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Num")
	int Num;


	FSetIndexInt(ESetCmd InSetCmd = ESetCmd::Set, int InIndex = -1, int InNum = 0)
		: SetCmd(InSetCmd), Index(InIndex), Num(InNum) {}
};


/** * 设置索引值 */
USTRUCT(BlueprintType)
struct FStringColor
{
	GENERATED_BODY()

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name")
	FName Name;

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "String")
	FString String;

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "String")
	FLinearColor LinearColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);

	FStringColor() = default;

	FStringColor(const FName& InName)
		: Name(InName) {}

	FStringColor(const FName& InName, const FString& InString, const FLinearColor& InLinearColor)
		: Name(InName), String(InString), LinearColor(InLinearColor) {}



	/** * 获取名字字符串组对应名字索引
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* return 返回获取索引
	*/
	static int GetArrayNameIndex(const TArray<FStringColor>& InStringColorArray, const FName& InName);

	/** * 获取名字字符串组对应名字索引数据
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* return 返回获取索引字符串值
	*/
	static FStringColor GetArrayNameIndexData(const TArray<FStringColor>& InStringColorArray, const FName& InName);
	
	/** * 设置NameStringsArray Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* return 返回获取索引  C++ 结构体里如何添加该结构体Array时的函数
	*/
	static int SetArrayNameData(TArray<FStringColor>& InStringColorArray, const FStringColor& InStringColor);

};

/** * 设置索引值 */
USTRUCT(BlueprintType)
struct FStringImageData
{
	GENERATED_BODY()

public:

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mirroring")
	uint8 Mode = 0;

	/** How to draw the image */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DrawAs")
	TEnumAsByte<enum ESlateBrushDrawType::Type > DrawAs = ESlateBrushDrawType::Image;

	/** How to tile the image in Image mode */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiling")
	TEnumAsByte<enum ESlateBrushTileType::Type> Tiling = ESlateBrushTileType::NoTile;

	/** How to mirror the image in Image mode.  This is normally only used for dynamic image brushes where the source texture
		comes from a hardware device such as a web camera. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mirroring")
	TEnumAsByte<enum ESlateBrushMirrorType::Type> Mirroring = ESlateBrushMirrorType::NoMirror;

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "String")
	FString ImageString;

	/** Size of the resource in Slate Units */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ImageSize")
	FVector2D ImageSize{32.0f};

	/** The margin to use in Box and Border modes */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Margin")
	FMargin Margin;

	/** Tinting applied to the image. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TintColor", meta = (DisplayName = "Tint", sRGB = "true"))
	FSlateColor TintColor;

	/** The margin to use in Box and Border modes */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CornerRadii")
	FMargin CornerRadii;


	FStringImageData() = default;

	FStringImageData(const FName& InName)
		: Name(InName) {}



	/** * 获取名字字符串组对应名字索引
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* return 返回获取索引
	*/
	static int GetArrayNameIndex(const TArray<FStringImageData>& InStringImageDataArray, const FName& InName);

	/** * 获取名字字符串组对应名字索引数据
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* return 返回获取索引字符串值
	*/
	static FStringImageData GetArrayNameIndexData(const TArray<FStringImageData>& InStringImageDataArray, const FName& InName);

	/** * 设置NameStringsArray Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* return 返回获取索引  C++ 结构体里如何添加该结构体Array时的函数
	*/
	static int SetArrayNameData(TArray<FStringImageData>& InStringImageDataArray, const FStringImageData& InStringImageData);

	/** * 设置NameStringsArray Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* return 返回获取索引  C++ 结构体里如何添加该结构体Array时的函数
	*/
	static bool RemoveArrayNameData(TArray<FStringImageData>& InStringImageDataArray, const FName& InName);

};


