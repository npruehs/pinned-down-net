#pragma once

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct GameStartedEvent : public Event
		{
			static const HashedString GameStartedEventType;

			const HashedString & GetEventType() const
			{
				return GameStartedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}
		};
	}
}