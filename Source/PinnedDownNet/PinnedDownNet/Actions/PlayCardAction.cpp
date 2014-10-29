#include "PlayCardAction.h"

using namespace PinnedDownNet::Events;

const HashedString PlayCardAction::PlayCardActionType = HashedString("PlayCard");

void PlayCardAction::Serialize(std::ostrstream& out)
{
	out << this->cardToPlay << " ";
}

void PlayCardAction::Deserialize(std::istrstream& in)
{
	in >> this->cardToPlay;
}