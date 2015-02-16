#pragma once

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct LoginSuccessEvent : public Event
		{
			static const HashedString LoginSuccessEventType;

			const HashedString & GetEventType() const
			{
				return LoginSuccessEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			int clientId;

			explicit LoginSuccessEvent() : LoginSuccessEvent(0)
			{
			}

			explicit LoginSuccessEvent(int clientId)
			{
				this->clientId = clientId;
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::wstring ToString() const
			{
				return std::wstring(L"Client logged in: " + std::to_wstring(this->clientId));
			}
		};
	}
}