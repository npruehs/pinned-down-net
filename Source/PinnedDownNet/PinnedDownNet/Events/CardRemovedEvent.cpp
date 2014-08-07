#include "CardRemovedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString CardRemovedEvent::CardRemovedEventType = HashedString("CardRemoved");

void CardRemovedEvent::Serialize(std::ostrstream& out)
{
	out << this->serverEntity << " ";
}

void CardRemovedEvent::Deserialize(std::istrstream& in)
{
	in >> this->serverEntity;
}