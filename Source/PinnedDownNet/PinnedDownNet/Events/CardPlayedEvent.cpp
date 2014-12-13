#include "CardPlayedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString CardPlayedEvent::CardPlayedEventType = HashedString("CardPlayed");

void CardPlayedEvent::Serialize(std::ostrstream& out)
{
	out << this->serverEntity << " ";
}

void CardPlayedEvent::Deserialize(std::istrstream& in)
{
	in >> this->serverEntity;
}