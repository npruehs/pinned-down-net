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

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);
		};
	}
}