#pragma once
#include "Card.h"

#include <string>

class ActionCard :
	public Card
{
public:
	ActionCard(std::string cardName);
	~ActionCard(void);
        
    virtual void play();
};



