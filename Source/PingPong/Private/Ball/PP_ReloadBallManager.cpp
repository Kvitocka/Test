#include "Ball/PP_ReloadBallManager.h"
#include <Kismet/GameplayStatics.h>
#include "PP_Gate.h" 
#include "Net/UnrealNetwork.h"

APP_ReloadBallManager::APP_ReloadBallManager()
{
    bReplicates = true;
    SetReplicateMovement(false);
}

void APP_ReloadBallManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(APP_ReloadBallManager, Ball);
}

void APP_ReloadBallManager::BeginPlay()
{
    Super::BeginPlay();

    if (!HasAuthority()) return;

    TArray<AActor*> FoundGates;
    UGameplayStatics::GetAllActorsOfClass(this, APP_Gate::StaticClass(), FoundGates);

    for (AActor* Actor : FoundGates)
    {
        if (APP_Gate* Gate = Cast<APP_Gate>(Actor))
        {
            Gate->OnGoalScored.AddDynamic(this, &APP_ReloadBallManager::SetBallInStartPos);
        }
    }

    if (BallClass)
    {
        Ball = GetWorld()->SpawnActor<APP_Ball>(BallClass, StartBallPos, FRotator::ZeroRotator);
        SetBallInStartPos(false);
    }
}

void APP_ReloadBallManager::SetBallInStartPos(bool isRed)
{
    if (!HasAuthority() || !Ball) return;

    Ball->SetActorLocation(StartBallPos);
    Ball->LaunchInRandomDirection();
}

