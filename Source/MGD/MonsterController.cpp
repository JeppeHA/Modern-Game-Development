// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AMonsterController::AMonsterController()
{
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	//Sight configurations
	//--------------------------------------------------------
	//Sight radius for detection
	SightConfig->SightRadius = 1500.0f;
	//Sight radius where monster loses player
	SightConfig->LoseSightRadius = 1800.0f;
	//Sight cone angles (*2; both left and right)
	SightConfig->PeripheralVisionAngleDegrees = 45.0f;

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

	//assigns the config settings to Perception component on the Actor
	PerceptionComp->SetDominantSense(SightConfig->GetSenseImplementation());
	PerceptionComp->ConfigureSense(*SightConfig);
}

void AMonsterController::BeginPlay()
{
	Super::BeginPlay();

	//Binds the "OnTargetPerceived" event trigger to the perception handler 

	PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &AMonsterController::OnTargetPerceived);
}

void AMonsterController::OnPossess(APawn* InPawn) 
{
	Super::OnPossess(InPawn);

	if (BehaviorTreeAsset)
	{
		RunBehaviorTree(BehaviorTreeAsset);
	}

}

void AMonsterController::OnTargetPerceived(AActor* Actor, FAIStimulus Stimulus)
{
	if (Actor == UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		if (UBlackboardComponent* BBComp = GetBlackboardComponent())
		{
			if (Stimulus.WasSuccessfullySensed())
			{
				BBComp->SetValueAsObject(FName("TargetActor"), Actor);
			}
			else
			{
				BBComp->ClearValue(FName("TargetActor"));
			}
		}

	}
}
