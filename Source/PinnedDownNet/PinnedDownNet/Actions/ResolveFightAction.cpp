#include "ResolveFightAction.h"

using namespace PinnedDownNet::Events;

const HashedString ResolveFightAction::ResolveFightActionType = HashedString("ResolveFight");

void ResolveFightAction::Serialize(std::ostrstream& out) const
{
	out << this->assignedCard << " ";
}

void ResolveFightAction::Deserialize(std::istrstream& in)
{
	in >> this->assignedCard;
}