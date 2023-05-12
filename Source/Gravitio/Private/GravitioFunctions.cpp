// Fill out your copyright notice in the Description page of Project Settings.


#include "GravitioFunctions.h"

float UGravitioFunctions::CalculateGravityForce(const FVector P1_Pos, const FVector P2_Pos, const float P1_Mass,const float P2_Mass)
{
	const float Distance = (P2_Pos - P1_Pos).Length();
	return G * P1_Mass * P2_Mass / (Distance*Distance);
}

FVector UGravitioFunctions::CalculateGravityVector(const FVector Object1, const FVector Object2, const float Mass1, const float Mass2)
{
	float force = CalculateGravityForce(Object1,Object2,Mass1,Mass2);
	FVector directon = (Object1 - Object2).GetSafeNormal();
	return directon * force;
}

FVector UGravitioFunctions::CalculateGravityVectorObjects(const FGravitable Object1, const FGravitable Object2)
{
	return CalculateGravityVector(Object1.Position, Object2.Position, Object1.Mass, Object2.Mass);
}

FVector UGravitioFunctions::CalculateGravityMultiplePoints(const FGravitable Object1, const TArray<FGravitable> ObjectArray)
{
	// if the array is null or empty
	if(ObjectArray.Num() < 1) return FVector(0,0,0);
	
	// in case the array contains only one element
	if(ObjectArray.Num()<=1) return CalculateGravityVectorObjects(Object1,(ObjectArray)[0]);

	// if the array contains multiple elements
	FVector Result = FVector(0,0,0);
	for (int i = 0; i < ObjectArray.Num(); ++i)
	{
		Result += CalculateGravityVectorObjects(Object1, (ObjectArray)[i]);
	}
	
	return Result;
}
