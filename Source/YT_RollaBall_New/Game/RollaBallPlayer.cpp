// Fill out your copyright notice in the Description page of Project Settings.


#include "RollaBallPlayer.h"
// YT tutorial: include components
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ARollaBallPlayer::ARollaBallPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// Since the YT tutorial does not use Tick(), we can set this to false. Set to true to restore
	PrimaryActorTick.bCanEverTick = false;
	
	// YT tutorial: create components
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	// YT tutorial: set the Mesh as the Root Component.
	// Attach the others in a chain, to use each other's transforms.
	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh); // or SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void ARollaBallPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARollaBallPlayer::MoveRight(float Value)
{
}

void ARollaBallPlayer::MoveForward(float Value)
{
}

void ARollaBallPlayer::Jump()
{
}

// // Called every frame
// void ARollaBallPlayer::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
//
// }

// // Called to bind functionality to input
// void ARollaBallPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
// {
// 	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
// }

