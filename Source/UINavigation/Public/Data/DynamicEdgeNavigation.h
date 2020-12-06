// Copyright (C) 2019 Gon�alo Marques - All Rights Reserved

#pragma once
#include "Data/NavigationEvent.h"
#include "Data/GridButton.h"
#include "Data/NavigationDirection.h"
#include "DynamicEdgeNavigation.generated.h"

USTRUCT(BlueprintType)
struct FDynamicEdgeNavigation
{
	GENERATED_BODY()

	FDynamicEdgeNavigation() {}

	FDynamicEdgeNavigation(const int InGridIndex, const int InTargetGridIndex, TArray<int> InTargetButtonIndices, ENavigationEvent InEvent, const ENavigationDirection InDirection, const bool InbTwoWayConnection = true)
	{
		GridIndex = InGridIndex;
		TargetGridIndex = InTargetGridIndex;
		TargetButtonIndices = InTargetButtonIndices;
		Event = InEvent;
		Direction = InDirection;
		bTwoWayConnection = InbTwoWayConnection;
	}

	FDynamicEdgeNavigation(const int InGridIndex, TArray<FGridButton> InTargetButtons, ENavigationEvent InEvent, const ENavigationDirection InDirection, const bool InbTwoWayConnection = true)
	{
		GridIndex = InGridIndex;
		Event = InEvent;
		TargetButtons = InTargetButtons;
		Direction = InDirection;
		bTwoWayConnection = InbTwoWayConnection;
	}

	UPROPERTY(BlueprintReadWrite, Category = DynamicEdgeNavigation)
		int GridIndex;

	UPROPERTY(BlueprintReadWrite, Category = DynamicEdgeNavigation)
		int TargetGridIndex = -1;

	UPROPERTY(BlueprintReadWrite, Category = DynamicEdgeNavigation)
		TArray<int> TargetButtonIndices;

	UPROPERTY(BlueprintReadWrite, Category = DynamicEdgeNavigation)
		TArray<FGridButton> TargetButtons;

	UPROPERTY(BlueprintReadWrite, Category = DynamicEdgeNavigation)
		ENavigationEvent Event;

	UPROPERTY(BlueprintReadWrite, Category = DynamicEdgeNavigation)
		ENavigationDirection Direction;
	
	UPROPERTY(BlueprintReadWrite, Category = DynamicEdgeNavigation)
		bool bTwoWayConnection = true;

};