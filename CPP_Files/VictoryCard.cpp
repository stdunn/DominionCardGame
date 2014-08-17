#include "VictoryCard.h"

VictoryCard::VictoryCard(std::string cardName)
	: Card(cardName)
{
	if(cardName == "Estate")
	{
		winValue = 1;
		cost = 2;
	}
	else if(cardName == "Duchy")
	{
		winValue = 3;
		cost = 5;
	}
	else // cardName must be "Province"
	{
		winValue = 6;
		cost = 8;
	}
}


VictoryCard::~VictoryCard(void)
{
}
