#pragma once

#include "IEntityComponent.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Components
	{
		class StructureComponent : public PinnedDownCore::IEntityComponent
		{
		public:
			static const HashedString StructureComponentType;

			const HashedString & GetComponentType() const
			{
				return StructureComponentType;
			}

			int structure;
		};
	}
}