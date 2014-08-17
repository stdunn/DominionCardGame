#include "TreasureCard.h"

TreasureCard::TreasureCard(std::string cardName)
	: Card(cardName)
{
	if (cardName == "Copper")
	{
		buyPower = 1;
		cost = 0;
	}
	else if (cardName == "Silver")
	{
		buyPower = 2;
		cost = 3;
	}
	else //	cardName must be "Gold":
	{
		buyPower = 3;
		cost = 6;
	}
}

TreasureCard::~TreasureCard(void)
{
}
