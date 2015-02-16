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
			Entity targetCard;

			explicit PlayCardAction() : PlayCardAction(INVALID_ENTITY_ID, INVALID_ENTITY_ID)
			{
			}

			explicit PlayCardAction(Entity cardToPlay, Entity targetCard)
			{
				this->cardToPlay = cardToPlay;
				this->targetCard = targetCard;
			}

			void Serialize(std::ostrstream& out) const;
			void Deserialize(std::istrstream& in);

			std::wstring ToString() const
			{
				return std::wstring(L"Play card " + std::to_wstring(this->cardToPlay) + L" with target " + std::to_wstring(this->targetCard));
			}
		};
	}
}