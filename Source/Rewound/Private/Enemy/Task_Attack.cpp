// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Task_Attack.h"

EBTNodeResult::Type UTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Attacking Player"));
	

	AFPSCharacter* PlayerCharacter = Cast<AFPSCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName("PlayerTarget")));
	if (!PlayerCharacter)return EBTNodeResult::Failed;

	float DamageAmount = 10.0f;
	AEnemyAIController* AIOwner = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	if (!AIOwner) return EBTNodeResult::Failed;

	PlayerCharacter->TakeDamage(DamageAmount, FDamageEvent(), AIOwner, AIOwner->GetPawn());
	
	return EBTNodeResult::Succeeded;
}
