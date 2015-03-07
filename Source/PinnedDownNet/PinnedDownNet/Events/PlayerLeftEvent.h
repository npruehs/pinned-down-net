#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct PlayerLeftEvent : public Event
		{
			static const HashedString PlayerLeftEventType;

			const HashedString & GetEventType() const
			{
				return PlayerLeftEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}
		};
	}
}