#pragma once

namespace PinnedDownNet
{
	namespace Data
	{
		enum FightOutcome
		{
			InvalidFightOutcome,
			PlayerVictory,
			EnemyVictory
		};

		inline std::string FightOutcomeToString(FightOutcome fightOutcome)
		{
			switch (fightOutcome)
			{
			case FightOutcome::PlayerVictory:
				return "PlayerVictory";
				break;

			case FightOutcome::EnemyVictory:
				return "EnemyVictory";
				break;

			default:
				return "Invalid";
				break;
			}
		}
	}
}