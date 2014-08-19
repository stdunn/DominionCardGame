#ifndef ACTIONCARD_ADVENTURER_H
#define ACTIONCARD_ADVENTURER_H

#include "ActionCard.h"
#include "GameState.h"

class ActionCard_Adventurer : public ActionCard
{
public:
    ActionCard_Adventurer();
    
    virtual void play(GameState state);
};

#endif // ACTIONCARD_ADVENTURER_H