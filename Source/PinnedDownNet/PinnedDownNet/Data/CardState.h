#pragma once

namespace PinnedDownNet
{
	namespace Data
	{
		enum CardState
		{
			InvalidState,
			InPlay,
			Hand
		};

		inline std::string CardStateToString(CardState state)
		{
			switch (state)
			{
			case CardState::Hand:
				return "Hand";
				break;

			case CardState::InPlay:
				return "InPlay";
				break;

			default:
				return "Invalid";
				break;
			}
		}
	}
}