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
		};
	}
}