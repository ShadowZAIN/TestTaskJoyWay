#include "Target.h"
#include "Engine/RendererSettings.h"

// Sets default values
ATarget::ATarget()
{
	PrimaryActorTick.bCanEverTick = false;

	// Set up collision sphere
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	RootComponent = Sphere;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Sphere);
	
	TextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextRenderer"));
	TextRender->SetText(FText::AsNumber(Health));
	TextRender->SetupAttachment(Sphere);
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
}

float ATarget::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	TakeDamageHP(DamageAmount);
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

void ATarget::TakeDamageHP(int Value)
{
	Health -= Value;
	TextRender->SetText(FText::AsNumber(Health));
	if (Health <= 0)
	{
		Destroy();
	}
	
}

void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
