#pragma once

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct ThreatChangedEvent : public PinnedDownCore::Event
		{
			static const HashedString ThreatChangedEventType;

			const HashedString & GetEventType() const
			{
				return ThreatChangedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			int newThreat;

			explicit ThreatChangedEvent() : ThreatChangedEvent(0)
			{
			}

			explicit ThreatChangedEvent(int newThreat)
			{
				this->newThreat = newThreat;
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);
		};
	}
}