#ifndef ACTIONCARD_CELLAR_H
#define ACTIONCARD_CELLAR_H

#include "ActionCard.h"
#include "GameState.h"

class ActionCard_Cellar : public ActionCard
{
public:
    ActionCard_Cellar(std::string cardName);
    virtual void play();
};

#endif // ACTIONCARD_CELLAR_H