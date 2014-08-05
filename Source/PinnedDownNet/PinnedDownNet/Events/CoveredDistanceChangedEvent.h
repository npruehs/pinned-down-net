#pragma once

#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct CoveredDistanceChangedEvent : public PinnedDownCore::Event
		{
			static const HashedString CoveredDistanceChangedEventType;

			const HashedString & GetEventType() const
			{
				return CoveredDistanceChangedEventType;
			}
			
			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			int distanceCovered;
			int distanceMaximum;

			explicit CoveredDistanceChangedEvent() : CoveredDistanceChangedEvent(0, 0)
			{
			}

			explicit CoveredDistanceChangedEvent(int distanceCovered, int distanceMaximum)
			{
				this->distanceCovered = distanceCovered;
				this->distanceMaximum = distanceMaximum;
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);
		};
	}
}