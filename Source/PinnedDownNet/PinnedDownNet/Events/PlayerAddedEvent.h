#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct PlayerAddedEvent : public Event
		{
			static const HashedString PlayerAddedEventType;

			const HashedString & GetEventType() const
			{
				return PlayerAddedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			Entity serverEntity;
			int clientId;
			std::string playerName;

			explicit PlayerAddedEvent() : PlayerAddedEvent(INVALID_ENTITY_ID, 0, "")
			{
			}

			explicit PlayerAddedEvent(Entity serverEntity, int clientId, std::string playerName)
				: serverEntity(serverEntity),
				clientId(clientId),
				playerName(playerName)
			{
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);

			std::wstring ToString()
			{
				std::wstring playerNameW(playerName.begin(), playerName.end());
				return std::wstring(L"Player entity " + std::to_wstring(this->serverEntity) + L" added for client " + std::to_wstring(this->clientId) + L" with name " + playerNameW);
			}
		};
	}
}