#include "AssignCardAction.h"

using namespace PinnedDownNet::Events;

const HashedString AssignCardAction::AssignCardActionType = HashedString("AssignCard");

void AssignCardAction::Serialize(std::ostrstream& out) const
{
	out << this->assignedCard << " ";
	out << this->targetCard << " ";
}

void AssignCardAction::Deserialize(std::istrstream& in)
{
	in >> this->assignedCard;
	in >> this->targetCard;
}