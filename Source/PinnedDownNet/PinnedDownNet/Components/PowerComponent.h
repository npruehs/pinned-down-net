#pragma once

#include "IEntityComponent.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Components
	{
		class PowerComponent : public PinnedDownCore::IEntityComponent
		{
		public:
			static const HashedString PowerComponentType;

			const HashedString & GetComponentType() const
			{
				return PowerComponentType;
			}

			int power = 0;
			int bonusPowerUntilEndOfTurn = 0;
		};
	}
}