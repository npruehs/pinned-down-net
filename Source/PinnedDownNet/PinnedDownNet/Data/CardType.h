#pragma once

namespace PinnedDownNet
{
	namespace Data
	{
		enum CardType
		{
			InvalidCard,
			Damage,
			Starship,
			Effect
		};

		inline std::string CardTypeToString(CardType cardType)
		{
			switch (cardType)
			{
			case CardType::Damage:
				return "Damage";
				break;

			case CardType::Starship:
				return "Starship";
				break;

			case CardType::Effect:
				return "Effect";
				break;

			default:
				return "Invalid";
				break;
			}
		}
	}
}