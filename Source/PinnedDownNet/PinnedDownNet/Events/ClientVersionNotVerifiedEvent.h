#pragma once

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct ClientVersionNotVerifiedEvent : public PinnedDownCore::Event
		{
			static const HashedString ClientVersionNotVerifiedEventType;

			const HashedString & GetEventType() const
			{
				return ClientVersionNotVerifiedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}
		};
	}
}