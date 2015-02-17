#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct AssignCardAction : public PinnedDownCore::Event
		{
			static const HashedString AssignCardActionType;

			const HashedString & GetEventType() const
			{
				return AssignCardActionType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Server;
			}

			Entity assignedCard;
			Entity targetCard;

			explicit AssignCardAction() : AssignCardAction(INVALID_ENTITY_ID, INVALID_ENTITY_ID)
			{
			}

			explicit AssignCardAction(Entity assignedCard, Entity targetCard)
			{
				this->assignedCard = assignedCard;
				this->targetCard = targetCard;
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::string ToString() const
			{
				return std::string("Assign card " + std::to_string(this->assignedCard) + " to card " + std::to_string(this->targetCard));
			}
		};
	}
}