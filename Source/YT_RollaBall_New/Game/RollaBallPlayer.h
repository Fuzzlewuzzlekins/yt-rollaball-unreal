// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RollaBallPlayer.generated.h"

// YouTube tutorial: forward declarations
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class YT_ROLLABALL_NEW_API ARollaBallPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARollaBallPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// YouTube tutorial: define components
	// (Use UPROPERTY to show these in editor but prevent accidental deletion)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UCameraComponent* Camera;

	// YouTube tutorial: define physics and behavior variables
	// (Use UPROPERTY to expose in editor and allow defaults to be tweaked freely)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveForce = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float JumpImpulse = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxJumpCount = 1;
	
public:	
	// // Called every frame
	// // YouTube tutorial recommends removing this, will restore if needed
	// virtual void Tick(float DeltaTime) override;

	// // Called to bind functionality to input
	// // The YT tutorial keeps this, but I'll comment it out and use a PlayerController instead
	// virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Custom Pawn action functions (movement)
	// The YouTube tutorial makes these private, I'll keep them public for use w/ a PlayerController
	void MoveRight(float Value);
	void MoveForward(float Value);
	void Jump();
	
private:
	// YT tutorial: used to track current jump
	int32 JumpCount = 0;

};
