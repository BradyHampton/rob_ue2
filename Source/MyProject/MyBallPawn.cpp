// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBallPawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MyUserWidget.h"

// Sets default values
AMyBallPawn::AMyBallPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyBallPawn::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* playerCtrl = Cast<APlayerController>(GetController())) {
		UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerCtrl->GetLocalPlayer());
		subsystem->ClearAllMappings();
		subsystem->AddMappingContext(MappingContext, 0);
	}

	SphereMesh = FindComponentByClass<UStaticMeshComponent>();
	SphereMesh->OnComponentBeginOverlap.AddDynamic(this, &AMyBallPawn::OnOverlapBegin);
	SphereMesh->SetGenerateOverlapEvents(true);


	if (WidgetClass) {
		HUD = CreateWidget<UMyUserWidget>(GetWorld(), WidgetClass);
		if (HUD) {
			HUD->AddToViewport();
		}
	}
	
}

// Called every frame
void AMyBallPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyBallPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* inputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		inputComp->BindAction(MovementAction, ETriggerEvent::Triggered, this, &AMyBallPawn::OnMovement);
	}

}

void AMyBallPawn::OnMovement(const FInputActionValue& value) {
	FInputActionValue::Axis2D inputValue = value.Get<FInputActionValue::Axis2D>();
	//UE_LOG(LogTemp, Warning, TEXT("INPUT WORKING, %f, %f"), inputValue.X, inputValue.Y);
	SphereMesh->AddForce(FVector(inputValue.X, inputValue.Y, 0) * 20.0f);
}

void  AMyBallPawn::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	UE_LOG(LogTemp, Warning, TEXT("COLLISION DETECTED"));

	HUD->UpdateScore(8);
}

