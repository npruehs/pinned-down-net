#pragma once

#include "IEntityComponent.h"
#include "..\Data\Affiliation.h"

using namespace PinnedDownCore;
using namespace PinnedDownNet::Data;

namespace PinnedDownNet
{
	namespace Components
	{
		class AffiliationComponent : public PinnedDownCore::IEntityComponent
		{
		public:
			static const HashedString AffiliationComponentType;

			const HashedString & GetComponentType() const
			{
				return AffiliationComponentType;
			}

			Affiliation affiliation;
		};
	}
}