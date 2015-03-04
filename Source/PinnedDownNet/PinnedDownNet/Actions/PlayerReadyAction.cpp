#include "PlayerReadyAction.h"

using namespace PinnedDownNet::Events;

const HashedString PlayerReadyAction::PlayerReadyActionType = HashedString("PlayerReady");

void PlayerReadyAction::Serialize(std::ostrstream& out) const
{
	out << this->ready << " ";
}

void PlayerReadyAction::Deserialize(std::istrstream& in)
{
	in >> this->ready;
}