#pragma once

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct PlayerReadyAction : public PinnedDownCore::Event
		{
			static const HashedString PlayerReadyActionType;

			const HashedString & GetEventType() const
			{
				return PlayerReadyActionType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Server;
			}

			bool ready;

			explicit PlayerReadyAction() : PlayerReadyAction(false)
			{
			}

			explicit PlayerReadyAction(bool ready)
			{
				this->ready = ready;
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::string ToString() const
			{
				std::string readyString = this->ready ? "" : "not ";
				return std::string("Player " + readyString + "ready");
			}
		};
	}
}