// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GravitioFunctions.generated.h"

/**
 * 
 */
UCLASS()
class GRAVITIO_API UGravitioFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	inline static const float G = 6.67 / 1e11; 
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Gravity")
	static float CalculateGravityForce(const FVector Position1,const FVector Position2,const float Mass1,const float Mass2);


	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Gravity")
	static FVector CalculateGravityVector(const FVector Position1, const FVector Position2, const float Mass1, const float Mass2);
	
};
