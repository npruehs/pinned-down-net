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

		inline std::string TurnPhaseToString(TurnPhase turnPhase)
		{
			switch (turnPhase)
			{
			case TurnPhase::Assignment:
				return "Assignment";
				break;

			case TurnPhase::Attack:
				return "Attack";
				break;

			case TurnPhase::Fight:
				return "Fight";
				break;

			case TurnPhase::Jump:
				return "Jump";
				break;

			case TurnPhase::Main:
				return "Main";
				break;

			case TurnPhase::WrapUp:
				return "Wrap Up";
				break;

			default:
				return "Invalid";
				break;
			}
		}
	}
}