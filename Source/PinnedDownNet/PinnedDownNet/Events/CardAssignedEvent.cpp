#include "CardAssignedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString CardAssignedEvent::CardAssignedEventType = HashedString("CardAssigned");

void CardAssignedEvent::Serialize(std::ostrstream& out) const
{
	out << this->assignedCard << " ";
	out << this->targetCard << " ";
}

void CardAssignedEvent::Deserialize(std::istrstream& in)
{
	in >> this->assignedCard;
	in >> this->targetCard;
}