#include "ClientVersionVerifiedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString ClientVersionVerifiedEvent::ClientVersionVerifiedEventType = HashedString("ClientVersionVerifiedEvent");

void ClientVersionVerifiedEvent::Serialize(std::ostrstream& out) const
{
	out << this->clientUpToDate << " ";
}

void ClientVersionVerifiedEvent::Deserialize(std::istrstream& in)
{
	in >> this->clientUpToDate;
}