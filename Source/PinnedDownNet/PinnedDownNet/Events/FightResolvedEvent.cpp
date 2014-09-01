#include "FightResolvedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString FightResolvedEvent::FightResolvedEventType = HashedString("FightResolved");

void FightResolvedEvent::Serialize(std::ostrstream& out)
{
	out << this->assignedCard << " ";
}

void FightResolvedEvent::Deserialize(std::istrstream& in)
{
	in >> this->assignedCard;
}