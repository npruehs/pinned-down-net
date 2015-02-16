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

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::wstring ToString() const
			{
				return std::wstring(L"Covered distance changed: " + std::to_wstring(this->distanceCovered) + L"/" + std::to_wstring(this->distanceMaximum));
			}
		};
	}
}