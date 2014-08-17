#pragma once
#ifndef TREASURECARD_H
#define TREASURECARD_H

#include "card.h"

#include <string>

class TreasureCard :
	public Card
{
private:
	int buyPower;

public:
	TreasureCard(std::string typeOfTreasure);

	int getBuyPower()
	{
		return buyPower;
	}
};

#endif TREASURECARD_H

