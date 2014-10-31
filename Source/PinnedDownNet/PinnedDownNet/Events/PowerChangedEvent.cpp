#include "PowerChangedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString PowerChangedEvent::PowerChangedEventType = HashedString("PowerChanged");

void PowerChangedEvent::Serialize(std::ostrstream& out)
{
	out << this->entity << " ";
	out << this->newPower << " ";
}

void PowerChangedEvent::Deserialize(std::istrstream& in)
{
	in >> this->entity;
	in >> this->newPower;
}