#pragma once

#include "IEntityComponent.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Components
	{
		class FlagshipComponent : public PinnedDownCore::IEntityComponent
		{
		public:
			static const HashedString FlagshipComponentType;

			const HashedString & GetComponentType() const
			{
				return FlagshipComponentType;
			}
		};
	}
}