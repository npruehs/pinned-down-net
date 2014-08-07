#pragma once

#include "Game.h"

#include "Affiliation.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Data
	{
		class CardSet;

		class CardFactory
		{
		public:
			CardFactory(PinnedDownCore::Game* game);

			Entity CreateCard(int setIndex, int cardIndex);

			Entity CreateStarship(int setIndex, int cardIndex);

			void SetAffiliation(Entity entity, Affiliation affiliation);
			void SetPower(Entity entity, int power);
			void SetThreat(Entity entity, int threat);

			void FinishCard(Entity card);
		private:
			PinnedDownCore::Game* game;
			std::shared_ptr<CardSet> cardSets[1];
		};
	}
}
