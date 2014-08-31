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

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);
		};
	}
}