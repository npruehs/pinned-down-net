#pragma once

namespace PinnedDownNet
{
	namespace Data
	{
		enum TurnPhase
		{
			Invalid,
			Main,
			Jump,
			Attack,
			Assignment,
			Fight,
			WrapUp
		};
	}
}