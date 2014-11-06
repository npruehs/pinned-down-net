#include "CardUnassignedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString CardUnassignedEvent::CardUnassignedEventType = HashedString("CardUnassigned");

void CardUnassignedEvent::Serialize(std::ostrstream& out)
{
	out << this->assignedCard << " ";
}

void CardUnassignedEvent::Deserialize(std::istrstream& in)
{
	in >> this->assignedCard;
}