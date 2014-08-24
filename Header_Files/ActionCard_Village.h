#ifndef ACTIONCARD_VILLAGE_H
#define ACTIONCARD_VILLAGE_H

#include "ActionCard.h"
#include "GameState.h"

class ActionCard_Village : public ActionCard
{
public:
    ActionCard_Village();
    virtual void play();
};

#endif // ACTIONCARD_VILLAGE_H