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
	case 0:
		// Damage - Bridge Hit.
		card = this->cardFactory->CreateDamage(this->GetSetIndex(), 0);
		this->cardFactory->SetPower(card, -1);
		this->cardFactory->SetStructure(card, -20);
		break;

	case 1:
		// Damage - Cargo Bay Hit.
		card = this->cardFactory->CreateDamage(this->GetSetIndex(), 1);
		this->cardFactory->SetPower(card, 0);
		this->cardFactory->SetStructure(card, -30);
		break;

	case 3:
		// Damage - Direct Hit.
		card = this->cardFactory->CreateDamage(this->GetSetIndex(), 3);
		this->cardFactory->SetPower(card, -1);
		this->cardFactory->SetStructure(card, -35);
		break;

	case 4:
		// Damage - Engine Room Hit.
		card = this->cardFactory->CreateDamage(this->GetSetIndex(), 4);
		this->cardFactory->SetPower(card, -1);
		this->cardFactory->SetStructure(card, -30);
		break;

	case 5:
		// Damage - Engines Hit.
		card = this->cardFactory->CreateDamage(this->GetSetIndex(), 5);
		this->cardFactory->SetPower(card, -1);
		this->cardFactory->SetStructure(card, -25);
		break;

	case 6:
		// Damage - Sickbay Hit.
		card = this->cardFactory->CreateDamage(this->GetSetIndex(), 6);
		this->cardFactory->SetPower(card, 0);
		this->cardFactory->SetStructure(card, -25);
		break;

	case 7:
		// Damage - Weapon Systems Hit.
		card = this->cardFactory->CreateDamage(this->GetSetIndex(), 7);
		this->cardFactory->SetPower(card, -2);
		this->cardFactory->SetStructure(card, -25);
		break;

	case 45:
		// Blue Wing - Ace In The Hole.
		card = this->cardFactory->CreateEffect(this->GetSetIndex(), 45);
		this->cardFactory->SetAffiliation(card, Affiliation::BlueWing);
		this->cardFactory->SetThreat(card, 0);
		this->cardFactory->AddBonusPower(card, 3);
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

	case 54:
		// Blue Wing - Berlin.
		card = this->cardFactory->CreateStarship(this->GetSetIndex(), 54);
		this->cardFactory->SetAffiliation(card, Affiliation::BlueWing);
		this->cardFactory->SetPower(card, 6);
		this->cardFactory->SetThreat(card, 2);
		break;

	case 55:
		// Blue Wing - London.
		card = this->cardFactory->CreateStarship(this->GetSetIndex(), 55);
		this->cardFactory->SetAffiliation(card, Affiliation::BlueWing);
		this->cardFactory->SetPower(card, 7);
		this->cardFactory->SetThreat(card, 3);
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

	case 58:
		// Blue Wing - Washington.
		card = this->cardFactory->CreateStarship(this->GetSetIndex(), 58);
		this->cardFactory->SetAffiliation(card, Affiliation::BlueWing);
		this->cardFactory->SetPower(card, 8);
		this->cardFactory->SetThreat(card, 4);
		break;

	case 72:
		// Enemy - Assault Cruiser.
		card = this->cardFactory->CreateStarship(this->GetSetIndex(), 72);
		this->cardFactory->SetAffiliation(card, Affiliation::Enemy);
		this->cardFactory->SetPower(card, 10);
		this->cardFactory->SetThreat(card, 3);
		break;

	case 73:
		// Enemy - Assault Frigate.
		card = this->cardFactory->CreateStarship(this->GetSetIndex(), 73);
		this->cardFactory->SetAffiliation(card, Affiliation::Enemy);
		this->cardFactory->SetPower(card, 8);
		this->cardFactory->SetThreat(card, 2);
		break;

	case 75:
		// Enemy - Behemoth.
		card = this->cardFactory->CreateStarship(this->GetSetIndex(), 75);
		this->cardFactory->SetAffiliation(card, Affiliation::Enemy);
		this->cardFactory->SetPower(card, 13);
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
