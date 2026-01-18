#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "CombatBalanceDataAsset.h"
#include "CombatRulesGameState.generated.h"

UCLASS()
class YOURGAME_API ACombatRulesGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	// Assign in BP/GameMode
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UCombatBalanceDataAsset> BalanceAsset;

	// Helper
	UFUNCTION(BlueprintCallable)
	const FCombatBalanceScalars& GetScalars(bool bPvP) const
	{
		check(BalanceAsset);
		return bPvP ? BalanceAsset->PvP : BalanceAsset->PvE;
	}
};
