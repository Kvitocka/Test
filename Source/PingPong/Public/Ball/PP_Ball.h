#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PP_BallIdentifiable.h"
#include "PP_Ball.generated.h"

class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class PINGPONG_API APP_Ball : public APawn, public IPP_BallIdentifiable
{
    GENERATED_BODY()

public:
    APP_Ball();

    void LaunchInRandomDirection();
protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* BallMesh;

    UPROPERTY(VisibleAnywhere)
    UProjectileMovementComponent* ProjectileMovement;
};
