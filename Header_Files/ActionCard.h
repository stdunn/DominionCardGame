#ifndef ACTIONCARD_H
#define ACTIONCARD_H

#include "Card.h"
#include "GameState.h"

#include <string>

class ActionCard :
	public Card
{
protected:
    Player* currentPlayer;
    
public:
	virtual ~ActionCard();
        
    virtual void play() = 0;
};

#endif // ACTIONCARD_H



