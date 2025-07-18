#include "PP_Gate.h"
#include "Ball/PP_BallIdentifiable.h"
#include "Net/UnrealNetwork.h"

APP_Gate::APP_Gate(){
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;


	GateCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("GateCollision"));
	RootComponent = GateCollision;
	GateCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	GateCollision->SetCollisionObjectType(ECC_WorldStatic);
	GateCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
	GateCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void APP_Gate::BeginPlay(){
	Super::BeginPlay();

	if (GateCollision)
		GateCollision->OnComponentBeginOverlap.AddDynamic(this, &APP_Gate::CollisionBeginOverlap);
}

void APP_Gate::CollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
	if (HasAuthority() && OtherActor && OtherActor->Implements<UPP_BallIdentifiable>())
		OnGoalScored.Broadcast(GateIsRed);
}
