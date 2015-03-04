#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct PlayerReadyStateResetEvent : public Event
		{
			static const HashedString PlayerReadyStateResetEventType;

			const HashedString & GetEventType() const
			{
				return PlayerReadyStateResetEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}
		};
	}
}