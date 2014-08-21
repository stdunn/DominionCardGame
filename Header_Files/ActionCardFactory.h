/* This class is a factory for action cards.
* Each card has a unique name, which specifies
* each special effect.
*/

#ifndef ACTIONCARDFACTORY_H
#define ACTIONCARDFACTORY_H

#include "Actioncard.h"

#include <string>

static class ActionCardFactory :
    public ActionCard
{
public:
        
    /* This method returns a pointer to a newly
    * created ActionCard based on the name provided new
    */
    
    static ActionCard* createActionCard(std::string cardName)
    {
        if(cardName == "Cellar")
        {
            return new ActionCard_Cellar(cardName);
        }
        else if(cardName == "Chancellor")
        {
            return new ActionCard_Chancellor(cardName);
        }
        else if(cardName == "Village")
        {
            return new ActionCard_Village(cardName);
        }
        else if(cardName == "Woodcutter")
        {
            return new ActionCard_Woodcutter(cardName);
        }
        else if(cardName == "Smithy")
        {
            return new ActionCard_Smithy(cardName);
        }
        else if(cardName == "Throne Room")
        {
            return new ActionCard_ThroneRoom(cardName);
        }
        else if(cardName == "Council Room")
        {
            return new  ActionCard_CouncilRoom(cardName);
        }
        else if(cardName == "Festival")
        {
            return new  ActionCard_Festival(cardName);
        }
        else if(cardName == "Laboratory")
        {
            return new  ActionCard_Laboratory(cardName);
        }
        else if(cardName == "Market")
        {
            return new  ActionCard_Market(cardName);
        }
        else if(cardName == "Mine")
        {
            return new  ActionCard_Mine(cardName);
        }
        else if(cardName == "Adventurer")
        {
            return new  ActionCard_Adventurer(cardName);
        }   
        else
        {
           std::string errorMessage \
                ("No such action card with name: " + cardName);
           throw noSuchCardException(errorMessage);
        }
    }
};


#endif // ACTIONCARDFACTORY_H