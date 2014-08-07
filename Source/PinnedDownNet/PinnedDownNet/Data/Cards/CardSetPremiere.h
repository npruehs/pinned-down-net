#pragma once

#include "..\CardSet.h"

namespace PinnedDownNet
{
	namespace Data
	{
		namespace Cards
		{
			class CardSetPremiere : public CardSet
			{
			public:
				CardSetPremiere(CardFactory* cardFactory) : CardSet(cardFactory)
				{
				}

				int GetSetIndex();
				Entity CreateCard(int cardIndex);
			};
		}
	}
}