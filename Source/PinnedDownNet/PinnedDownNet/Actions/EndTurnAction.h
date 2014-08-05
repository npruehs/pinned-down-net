#pragma once

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct EndTurnAction : public PinnedDownCore::Event
		{
			static const HashedString EndTurnActionType;

			const HashedString & GetEventType() const
			{
				return EndTurnActionType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Server;
			}
		};
	}
}