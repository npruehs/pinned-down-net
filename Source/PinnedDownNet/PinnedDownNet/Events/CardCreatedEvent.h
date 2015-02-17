#pragma once

#include "EntityManager.h"
#include "Event.h"

#include "..\Data\CardState.h"

using namespace PinnedDownCore;
using namespace PinnedDownNet::Data;

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
			Entity owner;
			int setIndex;
			int cardIndex;
			CardState initialState;

			explicit CardCreatedEvent() : CardCreatedEvent(INVALID_ENTITY_ID, INVALID_ENTITY_ID, 0, 0, CardState::InvalidState)
			{
			}

			explicit CardCreatedEvent(Entity serverEntity, Entity owner, int setIndex, int cardIndex, CardState initialState)
			{
				this->serverEntity = serverEntity;
				this->owner = owner;
				this->setIndex = setIndex;
				this->cardIndex = cardIndex;
				this->initialState = initialState;
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::string ToString() const
			{
				std::string initialStateString = CardStateToString(this->initialState);

				return std::string("Card " + std::to_string(this->setIndex)
					+ "-" + std::to_string(this->cardIndex)
					+ " (server id " + std::to_string(this->serverEntity)
					+ ") created for " + std::to_string(this->owner)
					+ " as " + initialStateString);
			}
		};
	}
}