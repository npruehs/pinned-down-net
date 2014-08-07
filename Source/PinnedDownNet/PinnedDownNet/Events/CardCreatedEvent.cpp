#include "CardCreatedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString CardCreatedEvent::CardCreatedEventType = HashedString("CardCreated");

void CardCreatedEvent::Serialize(std::ostrstream& out)
{
	out << this->serverEntity << " ";
	out << this->setIndex << " ";
	out << this->cardIndex << " ";
}

void CardCreatedEvent::Deserialize(std::istrstream& in)
{
	in >> this->serverEntity;
	in >> this->setIndex;
	in >> this->cardIndex;
}