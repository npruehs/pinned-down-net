#include "CardCreatedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString CardCreatedEvent::CardCreatedEventType = HashedString("CardCreated");

void CardCreatedEvent::Serialize(std::ostrstream& out) const
{
	out << this->serverEntity << " ";
	out << this->owner << " ";
	out << this->setIndex << " ";
	out << this->cardIndex << " ";
	out << this->initialState << " ";
}

void CardCreatedEvent::Deserialize(std::istrstream& in)
{
	in >> this->serverEntity;
	in >> this->owner;
	in >> this->setIndex;
	in >> this->cardIndex;

	int initialStateValue;
	in >> initialStateValue;
	this->initialState = (CardState)initialStateValue;
}