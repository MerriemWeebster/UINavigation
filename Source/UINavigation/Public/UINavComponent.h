// Copyright (C) 2018 Gon�alo Marques - All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UINavComponent.generated.h"

/**
 * 
 */
UCLASS()
class UINAVIGATION_API UUINavComponent : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintNativeEvent, Category = "UINavigation")
		void OnNavigatedTo();
	virtual void OnNavigatedTo_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "UINavigation")
		void OnNavigatedFrom();
	virtual void OnNavigatedFrom_Implementation();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UUINavButton* NavButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget, OptionalWidget = true))
		class UTextBlock* NavText;

};
