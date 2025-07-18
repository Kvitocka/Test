#include "Score/PP_ScoreWidget.h"
#include "Components/TextBlock.h"
#include <Score/PP_GameState.h>

void UPP_ScoreWidget::NativeConstruct(){
    Super::NativeConstruct();
    UpdateScore(0, 0);

    if (APP_GameState* GameState = Cast<APP_GameState>(GetWorld()->GetGameState()))
        GameState->OnScoreUpdated.AddDynamic(this, &UPP_ScoreWidget::UpdateScore);
}

void UPP_ScoreWidget::UpdateScore(int Red, int Blue)
{
    if (RedScoreText)
        RedScoreText->SetText(FText::FromString(FString::Printf(TEXT("%d"), Red)));

    if (BlueScoreText)
        BlueScoreText->SetText(FText::FromString(FString::Printf(TEXT("%d"), Blue)));
}