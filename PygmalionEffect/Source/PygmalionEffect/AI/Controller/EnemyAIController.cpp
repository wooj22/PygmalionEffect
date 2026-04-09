
#include "EnemyAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName AEnemyAIController::Key_TargetActor(TEXT("TargetActor"));
const FName AEnemyAIController::Key_HomeLocation(TEXT("HomeLocation"));
const FName AEnemyAIController::Key_IsInAttackRange(TEXT("IsInAttackRange"));


AEnemyAIController::AEnemyAIController()
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}


void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (!InPawn || !BehaviorTreeAsset)
	{
		return;
	}

	UBlackboardComponent* BB = nullptr;
	UseBlackboard(BehaviorTreeAsset->BlackboardAsset, BB);

	RunBehaviorTree(BehaviorTreeAsset);

	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsVector(Key_HomeLocation, InPawn->GetActorLocation());
		BlackboardComp->SetValueAsBool(Key_IsInAttackRange, false);
	}
}


void AEnemyAIController::ClearTargetActor()
{
	if (!BlackboardComp) return;

	BlackboardComp->ClearValue(Key_TargetActor);
	BlackboardComp->SetValueAsBool(Key_IsInAttackRange, false);
}




// [ Getter/Setter ]

void AEnemyAIController::SetTargetActor(AActor* NewTarget)
{
	if (!BlackboardComp) return;

	BlackboardComp->SetValueAsObject(Key_TargetActor, NewTarget);
}

AActor* AEnemyAIController::GetTargetActor() const
{
	if (!BlackboardComp) return nullptr;

	return Cast<AActor>(BlackboardComp->GetValueAsObject(Key_TargetActor));
}

void AEnemyAIController::SetIsInAttackRange(bool bInRange)
{
	if (!BlackboardComp) return;

	BlackboardComp->SetValueAsBool(Key_IsInAttackRange, bInRange);
}

bool AEnemyAIController::GetIsInAttackRange() const
{
	if (!BlackboardComp) return false;

	return BlackboardComp->GetValueAsBool(Key_IsInAttackRange);
}