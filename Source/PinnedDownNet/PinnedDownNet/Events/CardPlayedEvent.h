#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct CardPlayedEvent : public Event
		{
			static const HashedString CardPlayedEventType;

			const HashedString & GetEventType() const
			{
				return CardPlayedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			Entity serverEntity;

			explicit CardPlayedEvent() : CardPlayedEvent(INVALID_ENTITY_ID)
			{
			}

			explicit CardPlayedEvent(Entity serverEntity)
			{
				this->serverEntity = serverEntity;
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);

			std::wstring ToString()
			{
				return std::wstring(L"Card played: " + std::to_wstring(this->serverEntity));
			}
		};
	}
}