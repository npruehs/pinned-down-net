#include "PlayerFactory.h"
#include "CardSet.h"

#include "..\Components\PlayerComponent.h"

using namespace PinnedDownCore;
using namespace PinnedDownNet::Components;
using namespace PinnedDownNet::Data;


PlayerFactory::PlayerFactory(PinnedDownCore::Game* game)
{
	this->game = game;
}

Entity PlayerFactory::CreatePlayer(int clientId, std::string playerName)
{
	// Create player entity.
	auto playerEntity = this->game->entityManager->CreateEntity();

	// Store client id and player name.
	auto playerComponent = std::make_shared<PlayerComponent>();
	playerComponent->clientId = clientId;
	playerComponent->playerName = playerName;

	this->game->entityManager->AddComponent(playerEntity, playerComponent);

	return playerEntity;
}

