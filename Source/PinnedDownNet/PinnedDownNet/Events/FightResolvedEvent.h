#pragma once

#include "EntityManager.h"
#include "Event.h"

#include "..\Data\FightOutcome.h"

using namespace PinnedDownCore;
using namespace PinnedDownNet::Data;

namespace PinnedDownNet
{
	namespace Events
	{
		struct FightResolvedEvent : public PinnedDownCore::Event
		{
			static const HashedString FightResolvedEventType;

			const HashedString & GetEventType() const
			{
				return FightResolvedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			Entity assignedCard;
			FightOutcome fightOutcome;

			explicit FightResolvedEvent() : FightResolvedEvent(INVALID_ENTITY_ID, FightOutcome::InvalidFightOutcome)
			{
			}

			explicit FightResolvedEvent(Entity assignedCard, FightOutcome fightOutcome)
			{
				this->assignedCard = assignedCard;
				this->fightOutcome = fightOutcome;
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);

			std::wstring ToString()
			{
				std::string outcome = FightOutcomeToString(this->fightOutcome);
				std::wstring outcomeW(outcome.begin(), outcome.end());

				return std::wstring(L"Fight resolved: " + std::to_wstring(this->assignedCard) + L" (" + outcomeW + L")");
			}
		};
	}
}