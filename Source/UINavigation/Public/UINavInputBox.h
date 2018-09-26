// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UINavInputBox.generated.h"

#define DISPLAYERROR(Text) GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("%s"), *(FString(TEXT("Error in ")).Append(GetName()).Append(TEXT(": ")).Append(Text))));

/**
* This class contains the logic for rebinding input keys to their respective actions
*/
UCLASS()
class UINAVIGATION_API UUINavInputBox : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	TArray<FInputActionKeyMapping> Actions;

public:

	virtual void NativeConstruct() override;

	void UpdateActionKey(FInputActionKeyMapping NewAction, int Index);

	void NotifySelected(int Index);
	void NotifyUnbound(int Index);

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UUINavComponent> InputButton_BP;

	TArray<class UUINavComponent*> InputButtons;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UUINavComponent* InputButton1;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UUINavComponent* InputButton2;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UUINavComponent* InputButton3;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* ActionText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UHorizontalBox* HorizontalBox;

	FString ActionName;

	int InputsPerAction = 2;
};
