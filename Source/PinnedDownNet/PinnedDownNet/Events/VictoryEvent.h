#pragma once

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct VictoryEvent : public Event
		{
			static const HashedString VictoryEventType;

			const HashedString & GetEventType() const
			{
				return VictoryEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}
		};
	}
}