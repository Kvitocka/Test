#include "Score/PP_GameState.h"
#include "PP_Gate.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

APP_GameState::APP_GameState(){
	bReplicates = true;
}

void APP_GameState::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority()){
		TArray<AActor*> FoundGates;
		UGameplayStatics::GetAllActorsOfClass(this, APP_Gate::StaticClass(), FoundGates);

		for (AActor* Actor : FoundGates)
			if (APP_Gate* Gate = Cast<APP_Gate>(Actor))
				Gate->OnGoalScored.AddDynamic(this, &APP_GameState::HandleGoalScored);

	}
}

void APP_GameState::HandleGoalScored(bool bIsRedGoal)
{
	if (bIsRedGoal){
		++BlueScore;
	}else{
		++RedScore;
	}

	OnRep_ScoreChanged();
}

void APP_GameState::OnRep_ScoreChanged(){
	OnScoreUpdated.Broadcast(RedScore, BlueScore);
}

void APP_GameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APP_GameState, RedScore);
	DOREPLIFETIME(APP_GameState, BlueScore);
}
