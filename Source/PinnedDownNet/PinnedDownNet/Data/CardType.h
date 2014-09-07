#pragma once

namespace PinnedDownNet
{
	namespace Data
	{
		enum CardType
		{
			InvalidCard,
			Damage,
			Starship
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

			default:
				return "Invalid";
				break;
			}
		}
	}
}