#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Ball/PP_ReloadBallManager.h"
#include "PP_GameMode.generated.h"

UCLASS()
class PINGPONG_API APP_GameMode : public AGameMode
{
	GENERATED_BODY()

public:
	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;
protected:
	virtual void PostLogin(APlayerController* NewPlayer) override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APP_ReloadBallManager> BallSpawnerClass;

private:
	void TryStartGame();

	bool bGameStarted=false;

	TArray<AActor*> UsedPlayerStarts;
};
