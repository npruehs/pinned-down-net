#include "PlayerAddedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString PlayerAddedEvent::PlayerAddedEventType = HashedString("PlayerAdded");

void PlayerAddedEvent::Serialize(std::ostrstream& out)
{
	out << this->serverEntity << " ";
	out << this->clientId << " ";
	out << this->playerName << " ";
}

void PlayerAddedEvent::Deserialize(std::istrstream& in)
{
	in >> this->serverEntity;
	in >> this->clientId;
	in >> this->playerName;
}