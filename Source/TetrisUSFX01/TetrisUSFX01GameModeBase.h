#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Block.h"
#include "Piece.h"
#include "TetrisUSFX01GameModeBase.generated.h"

UCLASS()
class TETRISUSFX01_API ATetrisUSFX01GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
private:
	FTimerHandle TimerHandle;
	float TiempoTranscurrido = 0.0f;
	const float TiempoMaximo = 30.0f;
protected:
	virtual void BeginPlay() override;
public:
	UPROPERTY()
		ABlock* SpawnedActor;

	/*UPROPERTY()
		APiece* SpawnedPiece;*/

	UPROPERTY()
		TMap<FGuid, FVector> ObjectsData;

	UFUNCTION()
		void DestroyActorFunction();
	int posicion;
	void GenerarBloque();

};