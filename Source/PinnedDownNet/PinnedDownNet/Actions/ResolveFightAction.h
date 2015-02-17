#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct ResolveFightAction : public PinnedDownCore::Event
		{
			static const HashedString ResolveFightActionType;

			const HashedString & GetEventType() const
			{
				return ResolveFightActionType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Server;
			}

			Entity assignedCard;

			explicit ResolveFightAction() : ResolveFightAction(INVALID_ENTITY_ID)
			{
			}

			explicit ResolveFightAction(Entity assignedCard)
			{
				this->assignedCard = assignedCard;
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::string ToString() const
			{
				return std::string("Resolve fight " + std::to_string(this->assignedCard));
			}
		};
	}
}