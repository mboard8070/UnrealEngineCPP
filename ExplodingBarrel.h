#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Sound/SoundCue.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "ExplodingBarrel.generated.h"

UCLASS(Blueprintable)
class GDP2CODETUTORIALS_API AExplodingBarrel : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AExplodingBarrel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BarrelMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Exploding Barrel")
	float HitPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Exploding Barrel")
	float ExplosionDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Exploding Barrel")
	float ExplosionRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Exploding Barrel")
	USoundCue* ExplosionSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Exploding Barrel")
	UParticleSystem* ExplosionParticle;

	UPROPERTY(VisibleAnywhere, Category = "Effects")
	UParticleSystemComponent* FireParticleSystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Exploding Barrel")
	UParticleSystem* FireParticle;

	UPROPERTY(VisibleAnywhere, Category = "Effects")
	URadialForceComponent* RadialForce;


	UFUNCTION()
	void OnDamageTaken(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	FTimerHandle CountdownTimerHandle;

	void Countdown();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
