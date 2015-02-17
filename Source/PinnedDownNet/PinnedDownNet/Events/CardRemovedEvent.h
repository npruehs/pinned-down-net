#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct CardRemovedEvent : public Event
		{
			static const HashedString CardRemovedEventType;

			const HashedString & GetEventType() const
			{
				return CardRemovedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			Entity serverEntity;
			
			explicit CardRemovedEvent() : CardRemovedEvent(INVALID_ENTITY_ID)
			{
			}

			explicit CardRemovedEvent(Entity serverEntity)
			{
				this->serverEntity = serverEntity;
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::string ToString() const
			{
				return std::string("Card removed: " + std::to_string(this->serverEntity));
			}
		};
	}
}