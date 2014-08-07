#pragma once

#include "IEntityComponent.h"
#include "..\Data\CardType.h"

using namespace PinnedDownCore;
using namespace PinnedDownNet::Data;

namespace PinnedDownNet
{
	namespace Components
	{
		class CardComponent : public PinnedDownCore::IEntityComponent
		{
		public:
			static const HashedString CardComponentType;

			const HashedString & GetComponentType() const
			{
				return CardComponentType;
			}

			int setIndex = 0;
			int cardIndex = 0;
			CardType cardType = CardType::InvalidCard;
		};
	}
}