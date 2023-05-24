// Fill out your copyright notice in the Description page of Project Settings.


#include "Rifle.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARifle::ARifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RifleMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Rifle Mesh"));
	//RootComponent = RifleMesh;

}

// Called when the game starts or when spawned
void ARifle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ARifle::FireWeapon()
{
	for (int i = 0; i < 3; i++)
	{
		// Get the transform of the "MuzzleSocket" on the RifleMesh
		FTransform SpawnTransform = RifleMesh->GetSocketTransform("MuzzleSocket", RTS_World);
		UE_LOG(LogTemp, Warning, TEXT("Muzzle location: %s"), *SpawnTransform.GetLocation().ToString());

		// Add a debug line
		FVector EndLocation = SpawnTransform.GetLocation() + SpawnTransform.GetRotation().GetForwardVector() * 1000;
		DrawDebugLine(GetWorld(), SpawnTransform.GetLocation(), EndLocation, FColor::Green, false, 2, 0, 5);

		UWorld* World = GetWorld();
		if (World != nullptr)
		{
			AProjectile* Projectile = Cast<AProjectile>(UGameplayStatics::BeginDeferredActorSpawnFromClass(this, BP_Projectile, SpawnTransform));
			if (Projectile != nullptr)
			{
				UGameplayStatics::FinishSpawningActor(Projectile, SpawnTransform);
				// Apply force, velocity or any other logic on the projectile here
			}
			else
			{
				// Add this print statement for debugging:
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Projectile is nullptr. Check the ProjectileBP and ensure it is set to a class derived from AProjectile."));
			}
		}
		else
		{
			// Add this print statement for debugging:
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("World is nullptr. This is unusual and might indicate a deeper problem."));
		}
	}
}


