// Fill out your copyright notice in the Description page of Project Settings.


#include "GravitioFunctions.h"

float UGravitioFunctions::CalculateGravityForce(const FVector P1_Pos, const FVector P2_Pos, const float P1_Mass,const float P2_Mass)
{
	const float Distance = (P2_Pos - P1_Pos).Length();
	return G * P1_Mass * P2_Mass / (Distance*Distance);
}

FVector UGravitioFunctions::CalculateGravityVector(const FVector Gobject, const FVector Planet, const float Mass1, const float Mass2)
{
	return FVector(0,0,0);
}
