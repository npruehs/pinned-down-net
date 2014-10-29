#pragma once

#include "IEntityComponent.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Components
	{
		class ConditionNotDamagedComponent : public PinnedDownCore::IEntityComponent
		{
		public:
			static const HashedString ConditionNotDamagedComponentType;

			const HashedString & GetComponentType() const
			{
				return ConditionNotDamagedComponentType;
			}
		};
	}
}