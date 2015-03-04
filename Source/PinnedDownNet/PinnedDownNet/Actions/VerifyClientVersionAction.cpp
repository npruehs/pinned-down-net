#include "VerifyClientVersionAction.h"

using namespace PinnedDownNet::Events;

const HashedString VerifyClientVersionAction::VerifyClientVersionActionType = HashedString("VerifyClientVersion");

void VerifyClientVersionAction::Serialize(std::ostrstream& out) const
{
	out << this->major << " ";
	out << this->minor << " ";
	out << this->build << " ";
	out << this->revision << " ";
}

void VerifyClientVersionAction::Deserialize(std::istrstream& in)
{
	in >> this->major;
	in >> this->minor;
	in >> this->build;
	in >> this->revision;
}