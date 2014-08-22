#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>
#include <stdexcept>

enum CardType
{
    Action,
    Treasure,
    Victory
};

class Card 
{
private:
	std::string name;
    CardType type;
    
protected:
	int cost;

public:
	Card(std::string cardName)
	{
		name = cardName;
	}
	
	~Card();
	
	bool operator==(const Card& c) const
	{
	    return this.getName() == c.getName();
	}
	
	bool operator!=(const Card& c) const
	{
	    return this.getName() == c.getName();
	}
	
	bool operator=!(const Card& c) const
	{
	    return this.getName() == c.getName();
	}
	
	std::string getName()
	{
		return name;
	}
	
	int getCost()
	{
		return cost;
	}
	
	CardType getType()
	{
	    return type;
	}
	
};


class noSuchCardException: public std::runtime_error
{
    noSuchCardException(std::string errorMessage) : std::runtime_error(errorMessage)
    {}
};

class cardNotFoundException: public std::runtime_error
{
    cardNotFound(std::string errorMessage) : std::runtime_error(errorMessage)
    {}
};

#endif // CARD_H

