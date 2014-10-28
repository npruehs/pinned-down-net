#pragma once

#include "IEntityComponent.h"
#include "..\Data\CardState.h"

using namespace PinnedDownCore;
using namespace PinnedDownNet::Data;

namespace PinnedDownNet
{
	namespace Components
	{
		class CardStateComponent : public PinnedDownCore::IEntityComponent
		{
		public:
			static const HashedString CardStateComponentType;

			const HashedString & GetComponentType() const
			{
				return CardStateComponentType;
			}

			CardState cardState = CardState::InvalidState;
		};
	}
}