#include "Ball/PP_Ball.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

APP_Ball::APP_Ball()
{
    PrimaryActorTick.bCanEverTick = false;

    bReplicates = true;
    SetReplicateMovement(true);

    BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
    RootComponent = BallMesh;
    BallMesh->SetSimulatePhysics(false);
    BallMesh->SetEnableGravity(false);
    BallMesh->SetNotifyRigidBodyCollision(true);
    BallMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    BallMesh->SetCollisionObjectType(ECC_Pawn);

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->InitialSpeed = 800.0f;
    ProjectileMovement->MaxSpeed = 800.0f;
    ProjectileMovement->bShouldBounce = true;
    ProjectileMovement->Bounciness = 1.0f; 
    ProjectileMovement->Friction = 0.0f;
    ProjectileMovement->Velocity = FVector::ZeroVector;
    ProjectileMovement->ProjectileGravityScale = 0.0f;
}

void APP_Ball::BeginPlay()
{
    Super::BeginPlay();

    if (HasAuthority())
        LaunchInRandomDirection();
}

void APP_Ball::LaunchInRandomDirection()
{
    float SignX = FMath::RandBool() ? 1.0f : -1.0f;
    float SignY = FMath::RandBool() ? 1.0f : -1.0f;

    float Radians = FMath::DegreesToRadians(FMath::RandRange(30.0f, 60.0f));
    FVector Dir = FVector(FMath::Cos(Radians) * SignX, FMath::Sin(Radians) * SignY, 0.0f);

    ProjectileMovement->Velocity = Dir.GetSafeNormal() * ProjectileMovement->InitialSpeed;
}
