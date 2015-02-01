#include "DisconnectClientAction.h"

using namespace PinnedDownNet::Events;

const HashedString DisconnectClientAction::DisconnectClientActionType = HashedString("DisconnectClient");

void DisconnectClientAction::Serialize(std::ostrstream& out)
{
}

void DisconnectClientAction::Deserialize(std::istrstream& in)
{
}