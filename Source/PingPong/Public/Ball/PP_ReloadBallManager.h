// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PP_Ball.h"
#include "PP_ReloadBallManager.generated.h"

UCLASS()
class PINGPONG_API APP_ReloadBallManager : public AActor
{
    GENERATED_BODY()

public:
    APP_ReloadBallManager();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere)
    FVector StartBallPos;

    UPROPERTY(Replicated)
    APP_Ball* Ball;

    UPROPERTY(EditAnywhere)
    TSubclassOf<APP_Ball> BallClass;

    UFUNCTION()
    void SetBallInStartPos(bool isRed);
};