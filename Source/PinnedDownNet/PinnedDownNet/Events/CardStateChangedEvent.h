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
		struct CardStateChangedEvent : public Event
		{
			static const HashedString CardStateChangedEventType;

			const HashedString & GetEventType() const
			{
				return CardStateChangedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			Entity serverEntity;
			CardState newState;

			explicit CardStateChangedEvent() : CardStateChangedEvent(INVALID_ENTITY_ID, CardState::InvalidState)
			{
			}

			explicit CardStateChangedEvent(Entity serverEntity, CardState newState)
			{
				this->serverEntity = serverEntity;
				this->newState = newState;
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);
		};
	}
}