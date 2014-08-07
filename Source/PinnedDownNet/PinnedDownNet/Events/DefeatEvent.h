#pragma once

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct DefeatEvent : public Event
		{
			static const HashedString DefeatEventType;

			const HashedString & GetEventType() const
			{
				return DefeatEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}
		};
	}
}