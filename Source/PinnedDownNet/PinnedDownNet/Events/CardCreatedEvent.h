#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct CardCreatedEvent : public Event
		{
			static const HashedString CardCreatedEventType;

			const HashedString & GetEventType() const
			{
				return CardCreatedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			Entity serverEntity;
			int setIndex;
			int cardIndex;

			explicit CardCreatedEvent() : CardCreatedEvent(INVALID_ENTITY_ID, 0, 0)
			{
			}

			explicit CardCreatedEvent(Entity serverEntity, int setIndex, int cardIndex)
			{
				this->serverEntity = serverEntity;
				this->setIndex = setIndex;
				this->cardIndex = cardIndex;
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);
		};
	}
}