#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct PowerChangedEvent : public PinnedDownCore::Event
		{
			static const HashedString PowerChangedEventType;

			const HashedString & GetEventType() const
			{
				return PowerChangedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			Entity entity;
			int newPower;

			explicit PowerChangedEvent() : PowerChangedEvent(INVALID_ENTITY_ID, 0)
			{
			}

			explicit PowerChangedEvent(Entity entity, int newPower)
			{
				this->entity = entity;
				this->newPower = newPower;
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);
			
			std::string ToString() const
			{
				return std::string("Power of entity " + std::to_string(this->entity) + " changed to " + std::to_string(this->newPower));
			}
		};
	}
}