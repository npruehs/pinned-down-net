#pragma once

#include "IEntityComponent.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Components
	{
		class ThreatComponent : public PinnedDownCore::IEntityComponent
		{
		public:
			static const HashedString ThreatComponentType;

			const HashedString & GetComponentType() const
			{
				return ThreatComponentType;
			}

			int threat;
		};
	}
}