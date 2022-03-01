#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class TESTTASK_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
	UFUNCTION(BlueprintCallable, Category="Damage")
	void TakeDamageHP(int Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parameters")
	int DefaultHealth = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parameters")
	int Health = DefaultHealth;

	UPROPERTY(EditAnywhere, Category="Components")
	USphereComponent* Sphere;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UTextRenderComponent* TextRender;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
