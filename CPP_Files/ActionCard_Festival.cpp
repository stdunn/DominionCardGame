#include "ActionCard_Festival.h

ActionCard_Festival::ActionCard_Festival(std::string cardName)
    : Card(cardName)
{
    cost = 5;
    type = CardType::Action;    
}

/* Description:
*   + 2 Actions 
*   + 1 Buy
*   + $2
*/

void ActionCard_Festival::play()
{
    Player* currentPlayer = GameState::currentPlayer();
    
    currentPlayer->addActions(2);
    currentPlayer->addBuys(1);
    currentPlayer->addTreasure(2);
}