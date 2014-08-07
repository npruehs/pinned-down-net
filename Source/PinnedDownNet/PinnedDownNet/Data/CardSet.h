#pragma once

#include "CardFactory.h"

namespace PinnedDownNet
{
	namespace Data
	{
		class CardSet
		{
		public:
			CardSet(CardFactory* cardFactory)
			{
				this->cardFactory = cardFactory;
			}

			virtual int GetSetIndex() = 0;
			virtual Entity CreateCard(int cardIndex) = 0;

		protected:
			CardFactory* cardFactory;
		};
	}
}