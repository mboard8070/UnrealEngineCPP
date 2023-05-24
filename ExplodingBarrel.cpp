#include "ExplodingBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

// Sets default values
AExplodingBarrel::AExplodingBarrel()
{
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = true;

    // Create a default sub object for the barrel mesh
    BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BarrelMesh"));
    RootComponent = BarrelMesh;

    FireParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticleSystemComponent"));
    FireParticleSystemComponent->SetupAttachment(RootComponent);
    FireParticleSystemComponent->bAutoActivate = false; // Don't automatically start the particle system


    
    //BarrelMesh->SetSimulatePhysics(true);
    //BarrelMesh->SetEnableGravity(true);

    // Create a radial force component
    RadialForce = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForce"));

    // Set properties for the radial force
    RadialForce->Radius = ExplosionRadius;
    RadialForce->bImpulseVelChange = true;
    RadialForce->bAutoActivate = false; // Prevent component from ticking, and only use FireImpulse() instead
    RadialForce->bIgnoreOwningActor = true; // Ignore the barrel itself


    OnTakeAnyDamage.AddDynamic(this, &AExplodingBarrel::OnDamageTaken);
    

    HitPoints = 10.0f;
    ExplosionDamage = 30.0f;
    ExplosionRadius = 200.0f;
}

// Called when the game starts or when spawned
void AExplodingBarrel::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AExplodingBarrel::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AExplodingBarrel::OnDamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage > 0.f && HitPoints > 0.f)
    {
        HitPoints -= Damage;
        UE_LOG(LogTemp, Warning, TEXT("Damage taken, HitPoints: %f"), HitPoints); // log the remaining hitpoints

        // Start fire particle system
        if (!FireParticleSystemComponent->IsActive())
        {
            FireParticleSystemComponent->Activate();
        }

        // Start a countdown, if not already started
        if (!GetWorld()->GetTimerManager().IsTimerActive(CountdownTimerHandle))
        {
            UE_LOG(LogTemp, Warning, TEXT("Setting countdown timer")); // log if the timer is being set
            GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle, this, &AExplodingBarrel::Countdown, 1.0f, true);
        }
    }

    // If hitpoints reach 0, the barrel explodes
    if (HitPoints <= 0.f)
    {
        UE_LOG(LogTemp, Warning, TEXT("Barrel exploded"));

        // Stop fire particle system
        if(FireParticleSystemComponent != nullptr)
        {
            FireParticleSystemComponent->Deactivate();
        }

        // Cache location for spawning effects
        FVector BarrelLocation = GetActorLocation();

        // Destroy the barrel
        Destroy();

        // Apply radial damage
        UGameplayStatics::ApplyRadialDamage(this, ExplosionDamage, BarrelLocation, ExplosionRadius, nullptr, TArray<AActor*>(), this);

        if(RadialForce != nullptr)
        {
            // Apply radial force
            RadialForce->FireImpulse();
        }
        
        // Play explosion sound and particle system
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticle, BarrelLocation);
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, BarrelLocation);

    }
}

void AExplodingBarrel::Countdown()
{
    HitPoints--;
    UE_LOG(LogTemp, Warning, TEXT("Countdown called, HitPoints: %f"), HitPoints); // log when the countdown function is called and the remaining hitpoints

    // If hitpoints reach 0, the barrel explodes
    if (HitPoints <= 0.f)
    {
        OnDamageTaken(this, 0.f, nullptr, nullptr, nullptr);
    }
}
