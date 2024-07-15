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

#include "Config/UniversalStruct.h"

int FNameStrings::GetArrayNameIndex(const TArray<FNameStrings>& NameStringsArray, const FString& InName)
{
	for (size_t i = 0; i < NameStringsArray.Num(); i++)
	{
		if (NameStringsArray[i].Name == InName)
		{
			return i;
		}
	}
	return -1;
}

FString FNameStrings::GetArrayNameIndexData(const TArray<FNameStrings>& NameStringsArray, const FString& InName)
{
	for (size_t i = 0; i < NameStringsArray.Num(); i++)
	{
		if (NameStringsArray[i].Name == InName && NameStringsArray[i].Strings.IsValidIndex(0))
		{
			return NameStringsArray[i].Strings[0];
		}
	}
	return FString(); //UE 有没有FString的默认值
}

int FNameStrings::SetArrayNameData(TArray<FNameStrings>& NameStringsArray, const FString& InName, const FString& InString, ESetCmd SetCmd)
{
	if (InName.IsEmpty())
	{
		return -1;
	}
	int Index = GetArrayNameIndex(NameStringsArray, InName);
	if (Index != -1)
	{
		switch (SetCmd)
		{
		case ESetCmd::Set:
			if (InString.Len())
			{
				if (NameStringsArray[Index].Strings.Num())
				{
					NameStringsArray[Index].Strings[0] = InString;
					return Index;
				}
				NameStringsArray[Index].Strings.Add(InString);
				return Index;
			}
			NameStringsArray.RemoveAt(Index);
			return -1;
			break;
		case ESetCmd::Add:
			NameStringsArray[Index].Strings.Add(InString);
			return Index;
			break;
		case ESetCmd::SetAll:
			if (InString.Len())
			{
				InString.ParseIntoArray(NameStringsArray[Index].Strings, *FString(TEXT(";")));
				return Index;
			}
			NameStringsArray.RemoveAt(Index);
			return -1;
			break;
		case ESetCmd::AddUnique:
			NameStringsArray[Index].Strings.AddUnique(InString);
			return Index;
			break;
		case ESetCmd::Remove:
			NameStringsArray[Index].Strings.Remove(InString);
			if (NameStringsArray[Index].Strings.Num())
			{
				return Index;
			}
			NameStringsArray.RemoveAt(Index);
			return -1;
			break;
		case ESetCmd::RemoveAll:

			NameStringsArray.RemoveAt(Index);
			return -1;
			break;
		}
	}
	if (SetCmd != ESetCmd::Remove && SetCmd != ESetCmd::RemoveAll)
	{
		FNameStrings NameStrings;
		NameStrings.Name = InName;
		NameStrings.Strings.Add(InString);
		return NameStringsArray.Add(NameStrings);
	}
	return -1;
}





int FStringColor::GetArrayNameIndex(const TArray<FStringColor>& InStringColorArray, const FName& InName)
{
	for (size_t i = 0; i < InStringColorArray.Num(); i++)
	{
		if (InStringColorArray[i].Name == InName)
		{
			return i;
		}
	}
	return -1;
}

FStringColor FStringColor::GetArrayNameIndexData(const TArray<FStringColor>& InStringColorArray, const FName& InName)
{
	for (size_t i = 0; i < InStringColorArray.Num(); i++)
	{
		if (InStringColorArray[i].Name == InName)
		{
			return InStringColorArray[i];
		}
	}
	return FStringColor();
}

int FStringColor::SetArrayNameData(TArray<FStringColor>& InStringColorArray, const FStringColor& InStringColor)
{
	if (InStringColor.Name.IsNone())
	{
		return -1;
	}
	int Index = GetArrayNameIndex(InStringColorArray, InStringColor.Name);
	if (Index != -1)
	{
		if (InStringColorArray[Index].String.IsEmpty())
		{
			InStringColorArray.RemoveAt(Index);
			return -1;
		}
		else
		{
			InStringColorArray[Index] = InStringColor;
			return Index;
		}
	}
	if (InStringColor.String.Len())
	{
		return InStringColorArray.Add(InStringColor);
	}
	return -1;
}

int FStringImageData::GetArrayNameIndex(const TArray<FStringImageData>& InStringImageDataArray, const FName& InName)
{
	for (size_t i = 0; i < InStringImageDataArray.Num(); i++)
	{
		if (InStringImageDataArray[i].Name == InName)
		{
			return i;
		}
	}
	return -1;
}

FStringImageData FStringImageData::GetArrayNameIndexData(const TArray<FStringImageData>& InStringImageDataArray, const FName& InName)
{
	for (size_t i = 0; i < InStringImageDataArray.Num(); i++)
	{
		if (InStringImageDataArray[i].Name == InName)
		{
			return InStringImageDataArray[i];
		}
	}
	return FStringImageData();
}

int FStringImageData::SetArrayNameData(TArray<FStringImageData>& InStringImageDataArray, const FStringImageData& InStringImageData)
{
	if (InStringImageData.Name.IsNone())
	{
		return -1;
	}
	int Index = GetArrayNameIndex(InStringImageDataArray, InStringImageData.Name);
	if (Index != -1)
	{
		if (InStringImageDataArray[Index].ImageString.IsEmpty())
		{
			InStringImageDataArray.RemoveAt(Index);
			return -1;
		}
		else
		{
			InStringImageDataArray[Index] = InStringImageData;
			return Index;
		}
	}
	if (InStringImageData.ImageString.Len())
	{
		return InStringImageDataArray.Add(InStringImageData);
	}
	return -1;
}

bool FStringImageData::RemoveArrayNameData(TArray<FStringImageData>& InStringImageDataArray, const FName& InName)
{
	int Index = GetArrayNameIndex(InStringImageDataArray, InName);
	if (Index != -1)
	{
		InStringImageDataArray.RemoveAt(Index);
		return true;
	}
	return false;
}
