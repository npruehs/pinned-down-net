#pragma once

#include "IEntityComponent.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Components
	{
		class PlayerComponent : public PinnedDownCore::IEntityComponent
		{
		public:
			static const HashedString PlayerComponentType;

			const HashedString & GetComponentType() const
			{
				return PlayerComponentType;
			}

			int clientId;
			std::string playerName;
		};
	}
}