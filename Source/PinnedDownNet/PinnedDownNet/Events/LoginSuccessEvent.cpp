#include "LoginSuccessEvent.h"

using namespace PinnedDownNet::Events;

const HashedString LoginSuccessEvent::LoginSuccessEventType = HashedString("LoginSuccess");

void LoginSuccessEvent::Serialize(std::ostrstream& out) const
{
	out << this->clientId << " ";
}

void LoginSuccessEvent::Deserialize(std::istrstream& in)
{
	in >> this->clientId;
}