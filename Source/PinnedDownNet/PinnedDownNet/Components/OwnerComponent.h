#pragma once

#include "EntityManager.h"
#include "IEntityComponent.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Components
	{
		class OwnerComponent : public PinnedDownCore::IEntityComponent
		{
		public:
			static const HashedString OwnerComponentType;

			const HashedString & GetComponentType() const
			{
				return OwnerComponentType;
			}

			Entity owner;
		};
	}
}