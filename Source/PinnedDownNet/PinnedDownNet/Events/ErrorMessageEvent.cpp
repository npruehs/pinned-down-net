#include "ErrorMessageEvent.h"

using namespace PinnedDownNet::Events;

const HashedString ErrorMessageEvent::ErrorMessageEventType = HashedString("ErrorMessage");

void ErrorMessageEvent::Serialize(std::ostrstream& out) const
{
	out << this->errorMessage << " ";
}

void ErrorMessageEvent::Deserialize(std::istrstream& in)
{
	in >> this->errorMessage;
}