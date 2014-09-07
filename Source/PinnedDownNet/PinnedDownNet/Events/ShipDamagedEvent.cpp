#include "ShipDamagedEvent.h"

using namespace PinnedDownNet::Events;

const HashedString ShipDamagedEvent::ShipDamagedEventType = HashedString("ShipDamaged");

void ShipDamagedEvent::Serialize(std::ostrstream& out)
{
	out << this->damagedShip << " ";
	out << this->damageCard << " ";
}

void ShipDamagedEvent::Deserialize(std::istrstream& in)
{
	in >> this->damagedShip;
	in >> this->damageCard;
}