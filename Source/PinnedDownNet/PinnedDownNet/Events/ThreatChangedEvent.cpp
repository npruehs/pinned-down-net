#include "ThreatChangedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString ThreatChangedEvent::ThreatChangedEventType = HashedString("ThreatChanged");

void ThreatChangedEvent::Serialize(std::ostrstream& out)
{
	out << this->newThreat << " ";
}

void ThreatChangedEvent::Deserialize(std::istrstream& in)
{
	in >> this->newThreat;
}