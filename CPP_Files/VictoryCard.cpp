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
	else if(cardName == "Province")
	{
		winValue = 6;
		cost = 8;
	}
	else
    {
        std::string errorMessage \
            ("No victory card exists with name: " + cardName);
        throw new noSuchCardException(errorMessage);
    }
    
    CardType = CardType::Victory;
}


VictoryCard::~VictoryCard(void)
{
}
