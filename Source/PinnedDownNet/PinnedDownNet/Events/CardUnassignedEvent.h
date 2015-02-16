#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct CardUnassignedEvent : public PinnedDownCore::Event
		{
			static const HashedString CardUnassignedEventType;

			const HashedString & GetEventType() const
			{
				return CardUnassignedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			Entity assignedCard;

			explicit CardUnassignedEvent() : CardUnassignedEvent(INVALID_ENTITY_ID)
			{
			}

			explicit CardUnassignedEvent(Entity assignedCard)
			{
				this->assignedCard = assignedCard;
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::wstring ToString() const
			{
				return std::wstring(L"Card unassigned: " + std::to_wstring(this->assignedCard));
			}
		};
	}
}