#include "StructureChangedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString StructureChangedEvent::StructureChangedEventType = HashedString("StructureChanged");

void StructureChangedEvent::Serialize(std::ostrstream& out) const
{
	out << this->entity << " ";
	out << this->newStructure << " ";
}

void StructureChangedEvent::Deserialize(std::istrstream& in)
{
	in >> this->entity;
	in >> this->newStructure;
}