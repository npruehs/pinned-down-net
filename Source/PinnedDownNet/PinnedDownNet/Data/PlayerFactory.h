#pragma once

#include "Game.h"

using namespace PinnedDownCore;

namespace PinnedDownNet
{
	namespace Data
	{
		class PlayerFactory
		{
		public:
			PlayerFactory(PinnedDownCore::Game* game);

			Entity CreatePlayer(int clientId, std::string playerName);

		private:
			PinnedDownCore::Game* game;
		};
	}
}
