#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "PP_Gate.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGoalScored, bool, bGateIsRed);

UCLASS()
class PINGPONG_API APP_Gate : public AActor
{
	GENERATED_BODY()

public:
	APP_Gate();

	UPROPERTY(BlueprintAssignable, Category = "Goal")
	FOnGoalScored OnGoalScored;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	UBoxComponent* GateCollision;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gate")
	bool GateIsRed = true;

	UFUNCTION()
	void CollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool bFromSweep,const FHitResult& SweepResult);
};
