#include "ActionCard_Market.h"

ActionCard_Market::ActionCard_Market(std::string cardName)
    :Card(cardName)
{
    cost = 5;
    type = CardType::Action;
}

/* Description:
*   + 1 Action
*   + 1 Buy
*   + 1 Card
*   + $1
*/

void ActionCard_Market::play()
{
    Player* currentPlayer = GameState::currentPlayer();
    
    currentPlayer->addActions(1);
    currentPlayer->addBuys(1);
    currentPlayer->drawCards(1);
    currentPlayer->addTreasure(1);
}

