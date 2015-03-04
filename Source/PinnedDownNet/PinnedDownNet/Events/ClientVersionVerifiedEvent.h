#pragma once

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct ClientVersionVerifiedEvent : public PinnedDownCore::Event
		{
			static const HashedString ClientVersionVerifiedEventType;

			const HashedString & GetEventType() const
			{
				return ClientVersionVerifiedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			bool clientUpToDate;

			explicit ClientVersionVerifiedEvent() : ClientVersionVerifiedEvent(false)
			{
			}

			explicit ClientVersionVerifiedEvent(bool clientUpToDate)
				: clientUpToDate(clientUpToDate)
			{
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::string ToString() const
			{
				return std::string("Client up to date: " + std::to_string(this->clientUpToDate));
			}
		};
	}
}