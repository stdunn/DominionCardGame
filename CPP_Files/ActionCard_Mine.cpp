#include "ActionCard_Mine.h"


ActionCard_Mine::ActionCard_Mine(std::string cardName)
    :Card(cardName)
{
    cost = 5;
    type = CardType::Action;
}

/* Description:
*   Trash a Treasure card from your hand. 
*   Gain a Treasure card costing up to $3 more; 
*   put it into your hand.
*/

void ActionCard_Festival::play()
{
    Player* currentPlayer = GameState::currentPlayer();
    
    // Select card in hand to upgrade (CHOSEN_CARD)
    cardToUpgrade = CHOSEN_CARD;
    
    if (cardToUpgrade.getName() == "Copper")
    {
        cardToUpgrade = new TreasureCard("Silver");
    }
    else if (cardToUpgrade.getName() == "Silver")
    {
        cardToUpgrade = new TreasureCard("Gold");
    }
    else
    {
        // Cannot upgrade Gold again. Choose another card
        // or this does nothing. 
    }
}
