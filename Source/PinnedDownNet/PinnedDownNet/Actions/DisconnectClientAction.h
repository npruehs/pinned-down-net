#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct DisconnectClientAction : public PinnedDownCore::Event
		{
			static const HashedString DisconnectClientActionType;

			const HashedString & GetEventType() const
			{
				return DisconnectClientActionType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Server;
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::wstring ToString() const
			{
				return std::wstring(L"Disconnect client");
			}
		};
	}
}