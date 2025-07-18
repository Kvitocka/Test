#include "PP_HUD.h"
#include "Blueprint/UserWidget.h"
#include "Score/PP_ScoreWidget.h"
#include "GameFramework/PlayerController.h"

void APP_HUD::BeginPlay(){
	Super::BeginPlay();

	if (GetOwningPlayerController() && ScoreWidgetClass)
	{
		ScoreWidget = CreateWidget<UPP_ScoreWidget>(GetWorld(), ScoreWidgetClass);
		if (ScoreWidget) {
			ScoreWidget->AddToViewport();
		}
			
	}
}