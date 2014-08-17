#ifndef ACTIONCARD_H
#define ACTIONCARD_H

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

#endif // ACTIONCARD_H



