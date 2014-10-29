#pragma once

#include "EntityManager.h"
#include "Event.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Events
	{
		struct PlayCardAction : public PinnedDownCore::Event
		{
			static const HashedString PlayCardActionType;

			const HashedString & GetEventType() const
			{
				return PlayCardActionType;
			}

			const NetRole GetNetRole() const
			{
				return NetRole::Server;
			}

			Entity cardToPlay;

			explicit PlayCardAction() : PlayCardAction(INVALID_ENTITY_ID)
			{
			}

			explicit PlayCardAction(Entity cardToPlay)
			{
				this->cardToPlay = cardToPlay;
			}

			void Serialize(std::ostrstream& out);
			void Deserialize(std::istrstream& in);
		};
	}
}