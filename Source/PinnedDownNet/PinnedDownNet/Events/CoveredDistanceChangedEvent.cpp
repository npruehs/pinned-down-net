#include "CoveredDistanceChangedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString CoveredDistanceChangedEvent::CoveredDistanceChangedEventType = HashedString("CoveredDistanceChanged");

void CoveredDistanceChangedEvent::Serialize(std::ostrstream& out)
{
	out << this->distanceCovered << " ";
	out << this->distanceMaximum << " ";
}

void CoveredDistanceChangedEvent::Deserialize(std::istrstream& in)
{
	in >> this->distanceCovered;
	in >> this->distanceMaximum;
}