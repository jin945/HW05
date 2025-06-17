#include "AMyActor.h"
#include "Math/UnrealMathUtility.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = true;
    for (int i = 0; i < 10; ++i)
    {
        X[i] = 0;
        Y[i] = 0;
    }
    CurrentStep = 0;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();
}

void AMyActor::move()
{
    if (CurrentStep < 10)
    {
        int32 dx = step();
        int32 dy = step();

        X[CurrentStep + 1] = X[CurrentStep] + dx;
        Y[CurrentStep + 1] = Y[CurrentStep] + dy;

        UE_LOG(LogTemp, Log, TEXT("Step %d: (%d, %d)"), CurrentStep + 1, X[CurrentStep + 1], Y[CurrentStep + 1]);

        CurrentStep++;
    }
}
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    move();
}

int32 AMyActor::step()
{
    return FMath::RandRange(0, 1);
}

