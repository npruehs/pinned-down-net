#pragma once

#include "IEntityComponent.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Components
	{
		class ConditionalPowerComponent : public PinnedDownCore::IEntityComponent
		{
		public:
			static const HashedString ConditionalPowerComponentType;

			const HashedString & GetComponentType() const
			{
				return ConditionalPowerComponentType;
			}

			int conditionalPower;
		};
	}
}