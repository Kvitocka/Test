#include "PP_GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerStart.h"
#include "Player/PP_PlayerControler.h"
#include "Player/PP_Player.h"

void APP_GameMode::PostLogin(APlayerController* NewPlayer){
	Super::PostLogin(NewPlayer);

	if (GEngine){
		FString Msg = FString::Printf(TEXT("Гравець приєднався. Поточна кількість: %d"), GetNumPlayers());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, Msg);
	}

	TryStartGame();
}


void APP_GameMode::TryStartGame()
{
	if (bGameStarted)
		return;

	if (GetNumPlayers() >= 2){
		bGameStarted = true;

		if (BallSpawnerClass){
			GetWorld()->SpawnActor<APP_ReloadBallManager>(BallSpawnerClass, FVector(-40.f, 340.f, 20.f), FRotator::ZeroRotator);

			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Гра почалась!"));
		}
	}
}


AActor* APP_GameMode::ChoosePlayerStart_Implementation(AController* Player)
{
	TArray<AActor*> PlayerStarts;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), PlayerStarts);

	for (AActor* Start : PlayerStarts){
		if (!UsedPlayerStarts.Contains(Start)){
			UsedPlayerStarts.Add(Start);
			return Start;
		}
	}

	return Super::ChoosePlayerStart_Implementation(Player);
}