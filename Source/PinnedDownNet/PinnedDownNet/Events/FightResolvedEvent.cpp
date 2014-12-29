#include "FightResolvedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString FightResolvedEvent::FightResolvedEventType = HashedString("FightResolved");

void FightResolvedEvent::Serialize(std::ostrstream& out)
{
	out << this->assignedCard << " ";
	out << (int)this->fightOutcome << " ";
}

void FightResolvedEvent::Deserialize(std::istrstream& in)
{
	in >> this->assignedCard;

	int fightOutcomeCode;
	in >> fightOutcomeCode;

	this->fightOutcome = (FightOutcome)fightOutcomeCode;
}