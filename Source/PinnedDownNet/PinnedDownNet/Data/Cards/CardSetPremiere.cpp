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
	case 3:
		// Damage - Direct Hit.
		card = this->cardFactory->CreateDamage(this->GetSetIndex(), 3);
		this->cardFactory->SetPower(card, -1);
		this->cardFactory->SetStructure(card, -35);
		break;

	case 48:
		// Blue Wing - Never Say Die.
		card = this->cardFactory->CreateEffect(this->GetSetIndex(), 48);
		this->cardFactory->SetAffiliation(card, Affiliation::BlueWing);
		this->cardFactory->SetThreat(card, 0);
		this->cardFactory->AddBonusPower(card, 2);
		this->cardFactory->AddConditionalPower(card, 4);
		this->cardFactory->AddConditionNotDamaged(card);
		break;

	case 56:
		// Blue Wing - Moscow.
		card = this->cardFactory->CreateStarship(this->GetSetIndex(), 56);
		this->cardFactory->SetAffiliation(card, Affiliation::BlueWing);
		this->cardFactory->SetFlagship(card);
		this->cardFactory->SetPower(card, 8);
		this->cardFactory->SetThreat(card, 4);
		break;

	case 57:
		// Blue Wing - Paris.
		card = this->cardFactory->CreateStarship(this->GetSetIndex(), 57);
		this->cardFactory->SetAffiliation(card, Affiliation::BlueWing);
		this->cardFactory->SetPower(card, 6);
		this->cardFactory->SetThreat(card, 2);
		break;

	case 73:
		// Enemy - Assault Frigate.
		card = this->cardFactory->CreateStarship(this->GetSetIndex(), 73);
		this->cardFactory->SetAffiliation(card, Affiliation::Enemy);
		this->cardFactory->SetPower(card, 8);
		this->cardFactory->SetThreat(card, 2);
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
