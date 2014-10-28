#include "CardStateChangedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString CardStateChangedEvent::CardStateChangedEventType = HashedString("CardStateChanged");

void CardStateChangedEvent::Serialize(std::ostrstream& out)
{
	out << this->serverEntity << " ";
	out << this->newState << " ";
}

void CardStateChangedEvent::Deserialize(std::istrstream& in)
{
	in >> this->serverEntity;

	int cardStateValue;
	in >> cardStateValue;
	this->newState = (CardState)cardStateValue;
}