/* This class is a factory for action cards.
 * Each card has a unique name, which specifies
 * each special effect.
 */

#include "ActionCard.h"

ActionCard::ActionCard(std::string cardName)
    :Card(cardName)
{
    if(cardName == "Cellar")
    {
        this = ActionCard_Cellar();
    }
    else if(cardName == "Chancellor")
    {
        this = ActionCard_Chancellor();
    }
    else if(cardName == "Village")
    {
        this = ActionCard_Village();
    }
    else if(cardName == "Woodcutter")
    {
        this = ActionCard_Woodcutter();
    }
    else if(cardName == "Smithy")
    {
        this = ActionCard_Smithy();
    }
    else if(cardName == "Throne Room")
    {
        this = ActionCard_ThroneRoom();
    }
    else if(cardName == "Council Room")
    {
        this = ActionCard_CouncilRoom();
    }
    else if(cardName == "Festival")
    {
        this = ActionCard_Festival();
    }
    else if(cardName == "Laboratory")
    {
        this = ActionCard_Laboratory();
    }
    else if(cardName == "Market")
    {
        this = ActionCard_Market();
    }
    else if(cardName == "Mine")
    {
        this = ActionCard_Mine();
    }
    else if(cardName == "Adventurer")
    {
        this = ActionCard_Adventurer();
    }   
    else
    {
       std::string errorMessage = "Could not create action card with name: " + cardName;
       throw noSuchCardException(errorMessage);
    }
}

ActionCard::~ActionCard()    
{
}


