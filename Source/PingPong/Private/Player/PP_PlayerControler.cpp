#include "Player/PP_PlayerControler.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Player/PP_Player.h"
#include "GameFramework/Pawn.h"

void APP_PlayerControler::BeginPlay()
{
    Super::BeginPlay();

    if (IsLocalController())
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
            Subsystem->AddMappingContext(InputMappingContext, 0);
}


void APP_PlayerControler::SetupInputComponent(){
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
        EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APP_PlayerControler::MovePaddle);
}

void APP_PlayerControler::MovePaddle(const FInputActionValue& Value){
    float Axis = Value.Get<float>();

    if (APP_Player* Person = Cast<APP_Player>(GetPawn()))
        Person->MoveY(Axis);
}

void APP_PlayerControler::Server_MovePaddle_Implementation(float Value) {
    if (APP_Player* Person = Cast<APP_Player>(GetPawn()))
        Person->MoveY(Value);
}