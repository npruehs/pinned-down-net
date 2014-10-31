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

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);
		};
	}
}