#pragma once

namespace PinnedDownNet
{
	namespace Data
	{
		enum CardType
		{
			InvalidCard,
			Starship
		};

		inline std::string CardTypeToString(CardType cardType)
		{
			switch (cardType)
			{
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