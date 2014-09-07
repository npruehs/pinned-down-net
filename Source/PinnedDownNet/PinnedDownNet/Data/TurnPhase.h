#pragma once

namespace PinnedDownNet
{
	namespace Data
	{
		enum TurnPhase
		{
			InvalidTurnPhase,
			Main,
			Attack,
			Assignment,
			Fight,
			Jump
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

			default:
				return "Invalid";
				break;
			}
		}

		inline std::string GetTurnPhaseHint(TurnPhase turnPhase)
		{
			switch (turnPhase)
			{
			case TurnPhase::Assignment:
				return "Assign your starships to enemy attackers!";
				break;

			case TurnPhase::Attack:
				return "";
				break;

			case TurnPhase::Fight:
				return "Resolve fights in order of your choice!";
				break;

			case TurnPhase::Jump:
				return "";
				break;

			case TurnPhase::Main:
				return "Deploy new starships!";
				break;

			default:
				return "Invalid";
				break;
			}
		}
	}
}