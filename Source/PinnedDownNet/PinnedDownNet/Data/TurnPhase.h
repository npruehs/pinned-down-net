#pragma once

namespace PinnedDownNet
{
	namespace Data
	{
		enum TurnPhase
		{
			InvalidTurnPhase,
			Main,
			Jump,
			Attack,
			Assignment,
			Fight,
			WrapUp
		};
	}
}