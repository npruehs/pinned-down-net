#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

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

			explicit FightResolvedEvent() : FightResolvedEvent(INVALID_ENTITY_ID)
			{
			}

			explicit FightResolvedEvent(Entity assignedCard)
			{
				this->assignedCard = assignedCard;
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);

			std::wstring ToString()
			{
				return std::wstring(L"Fight resolved: " + std::to_wstring(this->assignedCard));
			}
		};
	}
}