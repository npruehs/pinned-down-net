#include "CardFactory.h"
#include "CardSet.h"

#include "Cards\CardSetPremiere.h"

#include "..\Components\AffiliationComponent.h"
#include "..\Components\CardComponent.h"
#include "..\Components\CardStateComponent.h"
#include "..\Components\FlagshipComponent.h"
#include "..\Components\OwnerComponent.h"
#include "..\Components\PowerComponent.h"
#include "..\Components\StructureComponent.h"
#include "..\Components\ThreatComponent.h"

#include "..\Events\CardStateChangedEvent.h"

#include "EntityInitializedEvent.h"

using namespace PinnedDownCore;
using namespace PinnedDownNet::Components;
using namespace PinnedDownNet::Data::Cards;
using namespace PinnedDownNet::Events;


CardFactory::CardFactory(PinnedDownCore::Game* game)
{
	this->game = game;

	this->cardSets[0] = std::make_shared<CardSetPremiere>(this);
}

Entity CardFactory::PrepareCard(Entity owner, int setIndex, int cardIndex, CardState initialState)
{
	// Get card set.
	auto cardSet = this->cardSets[setIndex];

	// Create card.
	auto cardEntity = cardSet->CreateCard(cardIndex);

	// Set owner.
	auto ownerComponent = std::make_shared<OwnerComponent>();
	ownerComponent->owner = owner;
	this->game->entityManager->AddComponent(cardEntity, ownerComponent);

	// Set initial state.
	auto cardStateComponent = std::make_shared<CardStateComponent>();
	cardStateComponent->cardState = initialState;
	this->game->entityManager->AddComponent(cardEntity, cardStateComponent);

	return cardEntity;
}

Entity CardFactory::CreateCard(Entity owner, int setIndex, int cardIndex, CardState initialState)
{
	auto cardEntity = this->PrepareCard(owner, setIndex, cardIndex, initialState);
	this->FinishCard(cardEntity);
	return cardEntity;
}

Entity CardFactory::CreateDamage(int setIndex, int cardIndex)
{
	Entity entity = this->game->entityManager->CreateEntity();

	auto cardComponent = std::make_shared<CardComponent>();
	cardComponent->setIndex = setIndex;
	cardComponent->cardIndex = cardIndex;
	cardComponent->cardType = CardType::Damage;
	this->game->entityManager->AddComponent(entity, cardComponent);

	auto powerComponent = std::make_shared<PowerComponent>();
	this->game->entityManager->AddComponent(entity, powerComponent);

	auto structureComponent = std::make_shared<StructureComponent>();
	this->game->entityManager->AddComponent(entity, structureComponent);

	return entity;
}

Entity CardFactory::CreateStarship(int setIndex, int cardIndex)
{
	Entity entity = this->game->entityManager->CreateEntity();

	auto cardComponent = std::make_shared<CardComponent>();
	cardComponent->setIndex = setIndex;
	cardComponent->cardIndex = cardIndex;
	cardComponent->cardType = CardType::Starship;
	this->game->entityManager->AddComponent(entity, cardComponent);

	auto affiliationComponent = std::make_shared<AffiliationComponent>();
	this->game->entityManager->AddComponent(entity, affiliationComponent);

	auto powerComponent = std::make_shared<PowerComponent>();
	this->game->entityManager->AddComponent(entity, powerComponent);

	auto threatComponent = std::make_shared<ThreatComponent>();
	this->game->entityManager->AddComponent(entity, threatComponent);

	auto structureComponent = std::make_shared<StructureComponent>();
	structureComponent->structure = 100;
	this->game->entityManager->AddComponent(entity, structureComponent);

	return entity;
}

void CardFactory::SetAffiliation(Entity entity, Affiliation affiliation)
{
	auto affiliationComponent = this->game->entityManager->GetComponent<AffiliationComponent>(entity, AffiliationComponent::AffiliationComponentType);
	affiliationComponent->affiliation = affiliation;
}

void CardFactory::SetFlagship(Entity entity)
{
	auto flagshipComponent = std::make_shared<FlagshipComponent>();
	this->game->entityManager->AddComponent(entity, flagshipComponent);
}

void CardFactory::SetPower(Entity entity, int power)
{
	auto powerComponent = this->game->entityManager->GetComponent<PowerComponent>(entity, PowerComponent::PowerComponentType);
	powerComponent->power = power;
}

void CardFactory::SetStructure(Entity entity, int structure)
{
	auto structureComponent = this->game->entityManager->GetComponent<StructureComponent>(entity, StructureComponent::StructureComponentType);
	structureComponent->structure = structure;
}

void CardFactory::SetThreat(Entity entity, int threat)
{
	auto threatComponent = this->game->entityManager->GetComponent<ThreatComponent>(entity, ThreatComponent::ThreatComponentType);
	threatComponent->threat = threat;
}

void CardFactory::FinishCard(Entity entity)
{
	auto entityInitializedEvent = std::make_shared<EntityInitializedEvent>(entity);
	this->game->eventManager->RaiseEvent(entityInitializedEvent);
}