#include "TurnPhaseChangedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString TurnPhaseChangedEvent::TurnPhaseChangedEventType = HashedString("TurnPhaseChanged");

void TurnPhaseChangedEvent::Serialize(std::ostrstream& out) const
{
	out << (int)this->newTurnPhase << " ";
}

void TurnPhaseChangedEvent::Deserialize(std::istrstream& in)
{
	int newTurnPhaseCode;
	in >> newTurnPhaseCode;

	this->newTurnPhase = (TurnPhase)newTurnPhaseCode;
}