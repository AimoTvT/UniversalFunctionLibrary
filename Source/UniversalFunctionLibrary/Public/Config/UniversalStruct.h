
#pragma once

#include "Engine/DataTable.h"
#include "UniversalStruct.generated.h"

/** * 名字字符串组 */
USTRUCT(BlueprintType)
struct FNameStrings : public FTableRowBase
{
	GENERATED_BODY()

	/** * 名字 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	/** * 字符串组 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> Strings;
};