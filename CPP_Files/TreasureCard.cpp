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
	else if (cardName == "Gold")
	{
		buyPower = 3;
		cost = 6;
	}
	else
	{
	    std::string errorMessage \
	        ("No treasure card exists with name: " + cardName);
	    throw new noSuchCardException(errorMessage);
	}
	    
}

TreasureCard::~TreasureCard(void)
{
}
