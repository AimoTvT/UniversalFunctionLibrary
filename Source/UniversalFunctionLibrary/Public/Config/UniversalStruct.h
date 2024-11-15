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
#include "Styling/SlateBrush.h"
#include "Config/UniversalEnum.h"

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


/** * 字符串字符串组,用于名字变化多的值 */
USTRUCT(BlueprintType)
struct FStringStrings : public FTableRowBase
{
	GENERATED_BODY()

	/** * 名字 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name")
	FString Name;

	/** * 字符串组 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Strings")
	TArray<FString> Strings;

	bool Serialize(FArchive& Ar)
	{
		Ar << *this;
		return true;
	}

	friend FArchive& operator<<(FArchive& Ar, FStringStrings& StringStrings)
	{
		// 序列化每个成员变量
		Ar << StringStrings.Name;
		Ar << StringStrings.Strings;
		return Ar;
	}

	/** * 获取名字字符串组对应名字索引
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (StringStrings.Name)
	* return 返回获取索引
	*/
	static int GetArrayNameIndex(const TArray<FStringStrings>& StringStringsArray, const FString& InName);

	/** * 获取名字字符串组对应名字索引数据
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (StringStrings.Name)
	* return 返回获取索引字符串值
	*/
	static FString GetArrayNameIndexData(const TArray<FStringStrings>& StringStringsArray, const FString& InName);

	/** * 设置StringStringsArray Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (StringStrings.Name)
	* InString 是输入的值
	* Cmd 是操作指令,Set,SetAll,Add,AddUnique,Remove,RemoveAll
	* return 返回获取索引  C++ 结构体里如何添加该结构体Array时的函数
	*/
	static int SetArrayNameData(TArray<FStringStrings>& StringStringsArray, const FString& InName, const FString& InString, ESetCmd SetCmd = ESetCmd::Set);

};

/** * 名字字符串组,用于名字变化不多的值 */
USTRUCT(BlueprintType)
struct FNameStrings : public FTableRowBase
{
	GENERATED_BODY()

	/** * 名字 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name")
	FName Name;

	/** * 字符串组 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Strings")
	TArray<FString> Strings;



	/** * 获取名字字符串组对应名字索引
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* return 返回获取索引
	*/
	static int GetArrayNameIndex(const TArray<FNameStrings>& NameStringsArray, const FName& InName);

	/** * 获取名字字符串组对应名字索引数据
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* return 返回获取索引字符串值
	*/
	static FString GetArrayNameIndexData(const TArray<FNameStrings>& NameStringsArray, const FName& InName);

	/** * 设置NameStringsArray Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (NameStrings.Name)
	* InString 是输入的值
	* Cmd 是操作指令,Set,SetAll,Add,AddUnique,Remove,RemoveAll
	* return 返回获取索引  C++ 结构体里如何添加该结构体Array时的函数
	*/
	static int SetArrayNameData(TArray<FNameStrings>& NameStringsArray, const FName& InName, const FString& InString, ESetCmd SetCmd = ESetCmd::Set);

};



/** * 设置索引值 */
USTRUCT(BlueprintType)
struct FSetIndexInt
{
	GENERATED_BODY()

	/** * 设置操作符 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SetCmd")
	ESetCmd SetCmd = ESetCmd::Set;

	/** * 索引 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Index")
	int Index = -1;

	/** * 数值 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Num")
	int Num = 0;

	FSetIndexInt() = default;

	FSetIndexInt(ESetCmd InSetCmd, int InIndex, int InNum) : SetCmd(InSetCmd), Index(InIndex), Num(InNum) {}
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
	* Name 对应名字字符串组的名字 (InStringColorArray.Name)
	* return 返回获取索引
	*/
	static int GetArrayNameIndex(const TArray<FStringColor>& InStringColorArray, const FName& InName);

	/** * 获取名字字符串组对应名字索引数据
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (InStringColorArray.Name)
	* return 返回获取索引字符串值
	*/
	static FStringColor GetArrayNameIndexData(const TArray<FStringColor>& InStringColorArray, const FName& InName);
	
	/** * 设置 Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (InStringColorArray.Name)
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
	* Name 对应名字字符串组的名字 (InStringImageDataArray,Name)
	* return 返回获取索引
	*/
	static int GetArrayNameIndex(const TArray<FStringImageData>& InStringImageDataArray, const FName& InName);

	/** * 获取名字字符串组对应名字索引数据
	* 名字字符串组结构 获取索引数据
	* Name 对应名字字符串组的名字 (InStringImageDataArray.Name)
	* return 返回获取索引字符串值
	*/
	static FStringImageData GetArrayNameIndexData(const TArray<FStringImageData>& InStringImageDataArray, const FName& InName);

	/** * 设置Array Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (InStringImageDataArray.Name)
	* return 返回获取索引  C++ 结构体里如何添加该结构体Array时的函数
	*/
	static int SetArrayNameData(TArray<FStringImageData>& InStringImageDataArray, const FStringImageData& InStringImageData);

	/** * 设置Array Cmd: Set,SetAll,Add,AddU,Remove,RemoveAll
	* 名字字符串组结构 用来修改解析的
	* Name 对应名字字符串组的名字 (InStringImageDataArray.Name)
	* return 返回获取索引  C++ 结构体里如何添加该结构体Array时的函数
	*/
	static bool RemoveArrayNameData(TArray<FStringImageData>& InStringImageDataArray, const FName& InName);

};


/** * Buff结构体 */
USTRUCT(BlueprintType)
struct FBuffStruct
{
	GENERATED_BODY()

	/** * 设置操作符 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buff")
	FName Name;

	/** * 索引 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buff")
	float DestroyTimeMax = 0.0f;

	/** * 数值 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Buff")
	TSoftObjectPtr<UObject> IconImage = TSoftObjectPtr<UObject>(FString(TEXT("/Script/Engine.Texture2D'/ResourcesExpansions/Textures/Touch/NL_Textuer.NL_Textuer'")));

};

/** * 索引浮点 */
USTRUCT(BlueprintType)
struct FIntFloat
{
	GENERATED_BODY()

	/** * 索引 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IntFloat")
	int Index = 0;


	/** * 浮点 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IntFloat")
	float Float = 0.0f;


	FIntFloat() = default;

	FIntFloat(int InIndex, float InFloat)
		: Index(InIndex), Float(InFloat) {}

	FIntFloat& operator+= (const FIntFloat& InIntFloat)
	{
		Float += InIntFloat.Float;
		return *this;
	}
	FIntFloat& operator-= (const FIntFloat& InIntFloat)
	{
		Float -= InIntFloat.Float;
		return *this;
	}
	FIntFloat& operator*= (const FIntFloat& InIntFloat)
	{
		Float *= InIntFloat.Float;
		return *this;
	}
	FIntFloat& operator/= (const FIntFloat& InIntFloat)
	{
		if (FMath::IsNearlyZero(InIntFloat.Float))
		{
			Float = 0;
		}
		else
		{
			Float /= InIntFloat.Float;
		}
		return *this;
	}

	FIntFloat operator+ (const FIntFloat& InIntFloat) const
	{
		return FIntFloat(*this) += InIntFloat;
	}
	FIntFloat operator- (const FIntFloat& InIntFloat) const
	{
		return FIntFloat(*this) -= InIntFloat;
	}
	FIntFloat operator* (const FIntFloat& InIntFloat) const
	{
		return FIntFloat(*this) *= InIntFloat;
	}
	FIntFloat operator/ (const FIntFloat& InIntFloat) const
	{
		return FIntFloat(*this) /= InIntFloat;
	}

	static int GetArrayIndex(TArray<FIntFloat> IntFloats, int InIndex)
	{
		for (size_t i = 0; i < IntFloats.Num(); i++)
		{
			if (IntFloats[i].Index == InIndex)
			{
				return i;
			}
		}
		return -1;
	}

};



/** * 高级浮点型结构 */
USTRUCT(BlueprintType)
struct FAdvancedFloatStruct
{
	GENERATED_BODY()

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AdvancedFloat")
	float DefaultFloat = 0.0f;

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AdvancedFloat")
	float FinalFloat = 0.0f;

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AdvancedFloat")
	float AdditionalFloat = 0.0f;

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AdvancedFloat")
	float AdditionalFloatMultiple = 1.0f;

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AdvancedFloat")
	TArray<FIntFloat> AdditionalIntFloats;

	/** *  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AdvancedFloat")
	TArray<FIntFloat> AdditionalIntFloatMultiples;


	/** * 更新数据 */
	void UpdatingData()
	{
		FinalFloat = (DefaultFloat + AdditionalFloat) * AdditionalFloatMultiple;
	}

	/** * 默认值 */
	void SetDefaultFloat(float InFloat)
	{
		DefaultFloat = InFloat;
		UpdatingData();
	}

	int AddIntFloat(FIntFloat IntFloat, bool Multiple = false, bool Additional = false)
	{
		TArray<FIntFloat>& IntFloatsRef = Multiple ? AdditionalIntFloatMultiples : AdditionalIntFloats;
		float& FloatRef = Multiple ? AdditionalFloatMultiple : AdditionalFloat;
		int Index = FIntFloat::GetArrayIndex(IntFloatsRef, IntFloat.Index);
		if (Index != -1)
		{
			if (Additional)
			{
				IntFloatsRef[Index] += IntFloat;
				FloatRef += IntFloat.Float;
				UpdatingData();
				return Index;
			}
			if (IntFloat.Float != 0.0f)
			{
				FloatRef -= IntFloatsRef[Index].Float;
				IntFloatsRef[Index] = IntFloat;
				FloatRef += IntFloatsRef[Index].Float;
				UpdatingData();
				return Index;
			}
			FloatRef -= IntFloatsRef[Index].Float;
			IntFloatsRef.RemoveAt(Index);
			UpdatingData();
			return -1;
		}
		Index = IntFloatsRef.Add(IntFloat);
		FloatRef += IntFloatsRef[Index].Float;
		UpdatingData();
		return Index;
	}

	bool RemoveIntFloat(int InIndex, bool Multiple = false)
	{
		TArray<FIntFloat>& IntFloatsRef = Multiple ? AdditionalIntFloatMultiples : AdditionalIntFloats;
		float& FloatRef = Multiple ? AdditionalFloatMultiple : AdditionalFloat;
		int Index = FIntFloat::GetArrayIndex(IntFloatsRef, InIndex);
		if (Index != -1)
		{
			FloatRef -= IntFloatsRef[Index].Float;
			IntFloatsRef.RemoveAt(Index);
			UpdatingData();
			return true;
		}
		return false;
	}


};





USTRUCT(BlueprintType)
struct FActorSaveData
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, Category = "SavedData")
	FSoftObjectPath SoftActorClassPath;

	UPROPERTY(VisibleAnywhere, Category = "SavedData")
	FTransform ActorTransform;

	UPROPERTY(VisibleAnywhere, Category = "SavedData")
	TArray<uint8> ActorSerializedData;

	FActorSaveData() = default;

	FActorSaveData(const FSoftObjectPath& InSoftActorClassPath, const FTransform& InActorTransform, const TArray<uint8>& InActorSerializedData)
		: SoftActorClassPath(InSoftActorClassPath), ActorTransform(InActorTransform), ActorSerializedData(InActorSerializedData) {}

};