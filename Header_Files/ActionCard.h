#ifndef ACTIONCARD_H
#define ACTIONCARD_H

#include "Card.h"
#include "GameState.h"

#include <string>

class ActionCard :
	public Card
{
public:
	~ActionCard(void);
        
    virtual void play(GameState state) = 0;
};

#endif // ACTIONCARD_H



