#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

class Card 
{
private:
	std::string name;

protected:
	int cost;

public:
	Card(std::string cardName)
	{
		name = cardName;
	}
	
	~Card();
	
	std::string getName()
	{
		return name;
	}
	
	int getCost()
	{
		return cost;
	}
};

#endif // CARD_H

