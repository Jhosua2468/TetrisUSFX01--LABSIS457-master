// Copyright Epic Games, Inc. All Rights Reserved.


#include "TetrisUSFX01GameModeBase.h"

void ATetrisUSFX01GameModeBase::BeginPlay()
{
    Super::BeginPlay();
    // Displays a red message on the screen for 10 seconds
    // Spawn an instance of the AMyFirstActor class at the
    //default location.
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, [&]() {
        if (TiempoTranscurrido >= TiempoMaximo) {
            GetWorldTimerManager().ClearTimer(TimerHandle);
            GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, TEXT("------------------\nSe han generado todos los bloques\n-----------------"));
            //Imprimir el TMap
            for (auto& ObjectData : ObjectsData)
            {
                GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, FString::Printf(TEXT("Objeto: (%s), Posicion: [%s]"), *ObjectData.Key.ToString(), *ObjectData.Value.ToString()));
            }
        }
        else {
            // Generar una ubicación aleatoria dentro de un rango
            //                          X                Y                                   Z
            FVector Location = FVector(0.0f, FMath::RandRange(-10, 10)*10, FMath::RandRange(-5, 5)*10);

            // Spawn un objeto ABlock en la ubicación generada
            ABlock* SpawnedBlock = GetWorld()->SpawnActor<ABlock>(ABlock::StaticClass(), FTransform(Location));

            // Obtener un ID único para el objeto
            FGuid ObjectID = FGuid::NewGuid();

            // Agregar los datos del objeto al TMap
            ObjectsData.Add(ObjectID, Location);

            // Mensaje de depuración para informar que se ha generado un bloque y su posición
            FString BlockMsg = FString::Printf(TEXT("Se ha generado un bloque en la posición: [%f], [%f], [%f]"), Location.X, Location.Y, Location.Z);
            GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, BlockMsg);

            TiempoTranscurrido += 5.0f;
        }
        }, 5.0f, true);
}

void ATetrisUSFX01GameModeBase::DestroyActorFunction()
{
    if (SpawnedActor != nullptr)
    {
        // Displays a red message on the screen for 10 seconds
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Block destruido"));
        SpawnedActor->Destroy();
    }
}