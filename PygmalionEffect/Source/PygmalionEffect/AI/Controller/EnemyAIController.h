#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class UBehaviorTree;
class UBlackboardComponent;

UCLASS()
class PYGMALIONEFFECT_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AEnemyAIController();

protected:
	virtual void OnPossess(APawn* InPawn) override;

public:
	void ClearTargetActor();

	void SetTargetActor(AActor* NewTarget);
	AActor* GetTargetActor() const;

	void SetIsInAttackRange(bool bInRange);
	bool GetIsInAttackRange() const;

public:
	// Blackboard Key Names
	static const FName Key_TargetActor;
	static const FName Key_HomeLocation;
	static const FName Key_IsInAttackRange;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	TObjectPtr<UBlackboardComponent> BlackboardComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTreeAsset;
};
