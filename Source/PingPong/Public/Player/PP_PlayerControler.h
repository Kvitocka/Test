#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "PP_PlayerControler.generated.h"

class UInputMappingContext;
class UInputAction;
class APerson; 
class UEnhancedInputComponent;
class ULocalPlayer;
class UEnhancedInputLocalPlayerSubsystem;


UCLASS()
class PINGPONG_API APP_PlayerControler : public APlayerController
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

    void MovePaddle(const FInputActionValue& Value);

    UFUNCTION(Server, Reliable)
    void Server_MovePaddle(float Value);

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputMappingContext* InputMappingContext;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* MoveAction;
};