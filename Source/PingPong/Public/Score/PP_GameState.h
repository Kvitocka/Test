#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PP_GameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGoalDataUpdate, int32, RedScore, int32, BlueScore);

UCLASS()
class PINGPONG_API APP_GameState : public AGameState
{
	GENERATED_BODY()

public:
	APP_GameState();

	UPROPERTY(BlueprintAssignable, Category = "Score")
	FGoalDataUpdate OnScoreUpdated;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(ReplicatedUsing = OnRep_ScoreChanged)
	int32 RedScore=0;

	UPROPERTY(ReplicatedUsing = OnRep_ScoreChanged)
	int32 BlueScore=0;

	UFUNCTION()
	void OnRep_ScoreChanged();

	UFUNCTION()
	void HandleGoalScored(bool bIsRedGoal);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};