#pragma once
#ifndef VICTORYCARD_H
#define VICTORYCARD_H

#include "Card.h"

class VictoryCard :
	public Card
{
private:
	int winValue;

public:
	VictoryCard(std::string cardName);
	~VictoryCard();
	
	int getWinValue()
	{
		return winValue;
	}
};

#endif // VICTORYCARD_H

