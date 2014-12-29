#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct CardAssignedEvent : public PinnedDownCore::Event
		{
			static const HashedString CardAssignedEventType;

			const HashedString & GetEventType() const
			{
				return CardAssignedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			Entity assignedCard;
			Entity targetCard;

			explicit CardAssignedEvent() : CardAssignedEvent(INVALID_ENTITY_ID, INVALID_ENTITY_ID)
			{
			}

			explicit CardAssignedEvent(Entity assignedCard, Entity targetCard)
			{
				this->assignedCard = assignedCard;
				this->targetCard = targetCard;
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);

			std::wstring ToString()
			{
				return std::wstring(L"Card " + std::to_wstring(this->assignedCard) + L" assigned to card " + std::to_wstring(this->targetCard));
			}
		};
	}
}