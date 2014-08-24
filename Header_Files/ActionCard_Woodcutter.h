#ifndef ACTIONCARD_WOODCUTTER_H
#define ACTIONCARD_WOODCUTTER_H

#include "ActionCard.h"
#include "GameState.h"

class ActionCard_Woodcutter : public ActionCard
{
public:
    ACTIONCARD_WoodCutter();
    virtual void play();
};

#endif // ACTIONCARD_WOODCUTTER_H