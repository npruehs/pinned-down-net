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
		};
	}
}