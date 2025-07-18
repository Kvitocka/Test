#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PP_HUD.generated.h"


class UPP_ScoreWidget;
class UUserWidget;

UCLASS()
class PINGPONG_API APP_HUD : public AHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UPP_ScoreWidget> ScoreWidgetClass;

private:
	UPROPERTY()
	UPP_ScoreWidget* ScoreWidget;
};
