#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AMyActor.generated.h"

UCLASS()
class HW05_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    int32 X[11];  
    int32 Y[11];  

    int32 step();
    void move();

    int CurrentStep = 0;
};
