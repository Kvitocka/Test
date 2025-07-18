#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PP_Player.generated.h"

class UStaticMeshComponent;
class UFloatingPawnMovement;

UCLASS()
class PINGPONG_API APP_Player : public APawn
{
    GENERATED_BODY()

public:
    APP_Player();

    UFUNCTION(Server, Reliable)
    void MoveY(float Value);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* Mesh;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float Speed;

    UPROPERTY(VisibleAnywhere)
    class UFloatingPawnMovement* MovementComponent;
};
