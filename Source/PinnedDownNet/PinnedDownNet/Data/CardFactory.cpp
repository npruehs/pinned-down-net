#include "CardFactory.h"
#include "CardSet.h"

#include "Cards\CardSetPremiere.h"

#include "..\Components\AffiliationComponent.h"
#include "..\Components\CardComponent.h"
#include "..\Components\FlagshipComponent.h"
#include "..\Components\PowerComponent.h"
#include "..\Components\ThreatComponent.h"

#include "EntityInitializedEvent.h"

using namespace PinnedDownCore;
using namespace PinnedDownNet::Components;
using namespace PinnedDownNet::Data::Cards;


CardFactory::CardFactory(PinnedDownCore::Game* game)
{
	this->game = game;

	this->cardSets[0] = std::make_shared<CardSetPremiere>(this);
}

Entity CardFactory::CreateCard(int setIndex, int cardIndex)
{
	auto cardSet = this->cardSets[setIndex];
	return cardSet->CreateCard(cardIndex);
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

void CardFactory::SetThreat(Entity entity, int threat)
{
	auto threatComponent = this->game->entityManager->GetComponent<ThreatComponent>(entity, ThreatComponent::ThreatComponentType);
	threatComponent->threat = threat;
}

void CardFactory::FinishCard(Entity entity)
{
	auto entityInitializedEvent = std::make_shared<EntityInitializedEvent>(entity);
	this->game->eventManager->QueueEvent(entityInitializedEvent);
}