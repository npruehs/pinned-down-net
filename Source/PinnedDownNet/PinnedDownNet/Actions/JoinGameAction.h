#pragma once

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct JoinGameAction : public PinnedDownCore::Event
		{
			static const HashedString JoinGameActionType;

			const HashedString & GetEventType() const
			{
				return JoinGameActionType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Server;
			}
		};
	}
}