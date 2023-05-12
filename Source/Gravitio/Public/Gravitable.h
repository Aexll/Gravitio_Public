#pragma once

#include "Gravitable.generated.h"

USTRUCT(BlueprintType) struct FGravitable
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gravitable Struct")
	float Mass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gravitable Struct")
	FVector Position;

	FGravitable();
};
