#include "CardSetPremiere.h"

using namespace PinnedDownNet::Data;
using namespace PinnedDownNet::Data::Cards;


int CardSetPremiere::GetSetIndex()
{
	return 0;
}

Entity CardSetPremiere::CreateCard(int cardIndex)
{
	Entity card;

	switch (cardIndex)
	{
	case 56:
		// Blue Wing - Moscow.
		card = this->cardFactory->CreateStarship(this->GetSetIndex(), 56);
		this->cardFactory->SetAffiliation(card, Affiliation::BlueWing);
		this->cardFactory->SetFlagship(card);
		this->cardFactory->SetPower(card, 8);
		this->cardFactory->SetThreat(card, 4);
		break;

	case 84:
		// Enemy - Swarm Frigate.
		card = this->cardFactory->CreateStarship(this->GetSetIndex(), 84);
		this->cardFactory->SetAffiliation(card, Affiliation::Enemy);
		this->cardFactory->SetPower(card, 6);
		this->cardFactory->SetThreat(card, 1);
		break;
	}

	return card;
}
