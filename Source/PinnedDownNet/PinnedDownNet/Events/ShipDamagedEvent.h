#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct ShipDamagedEvent : public PinnedDownCore::Event
		{
			static const HashedString ShipDamagedEventType;

			const HashedString & GetEventType() const
			{
				return ShipDamagedEventType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Client;
			}

			Entity damagedShip;
			Entity damageCard;

			explicit ShipDamagedEvent() : ShipDamagedEvent(INVALID_ENTITY_ID, INVALID_ENTITY_ID)
			{
			}

			explicit ShipDamagedEvent(Entity damagedShip, Entity damageCard)
			{
				this->damagedShip = damagedShip;
				this->damageCard = damageCard;
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);

			std::wstring ToString()
			{
				return std::wstring(L"Ship " + std::to_wstring(this->damagedShip) + L" damaged: " + std::to_wstring(this->damageCard));
			}
		};
	}
}