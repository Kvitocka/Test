#include "Player/PP_Player.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

APP_Player::APP_Player()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;
    SetReplicateMovement(true);

    MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
    Mesh->SetStaticMesh(CubeMesh.Object);
    Mesh->SetWorldScale3D(FVector(0.3f, 1.5f, 0.2f));
    Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void APP_Player::MoveY_Implementation(float Value)
{
    FVector NewLoc = GetActorLocation() + FVector(0.f, Speed * Value, 0.f);
    SetActorLocation(NewLoc, true);
}
