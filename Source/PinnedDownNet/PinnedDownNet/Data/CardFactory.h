#pragma once

#include "Game.h"

#include "Affiliation.h"

#include "..\Data\CardState.h"

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

			Entity PrepareCard(Entity owner, int setIndex, int cardIndex, CardState initialState);
			Entity CreateCard(Entity owner, int setIndex, int cardIndex, CardState initialState);

			Entity CreateDamage(int setIndex, int cardIndex);
			Entity CreateStarship(int setIndex, int cardIndex);
			Entity CreateEffect(int setIndex, int cardIndex);

			void SetAffiliation(Entity entity, Affiliation affiliation);
			void SetFlagship(Entity entity);
			void AddBonusPower(Entity entity, int power);
			void SetPower(Entity entity, int power);
			void SetStructure(Entity entity, int structure);
			void SetThreat(Entity entity, int threat);
			void AddConditionalPower(Entity entity, int conditionalPower);
			void AddConditionNotDamaged(Entity entity);

			void FinishCard(Entity card);
		private:
			PinnedDownCore::Game* game;
			std::shared_ptr<CardSet> cardSets[1];
		};
	}
}
