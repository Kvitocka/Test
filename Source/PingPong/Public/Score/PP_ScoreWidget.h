#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include "PP_ScoreWidget.generated.h"


UCLASS()
class PINGPONG_API UPP_ScoreWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void UpdateScore(int Red, int Blue);

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* RedScoreText;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* BlueScoreText;
};