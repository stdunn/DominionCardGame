#include "ActionCard_Laboratory.h"


ActionCard_Laboratory::ActionCard_Laboratory(std::string cardName)
    : Card(cardName)
{
    cost = 5;
    type = CardType::Action;
}

/* Description:
*   + 2 Cards
*   + 1 Action
*/

void ActionCard_Laboratory::play()
{
    Player* currentPlayer = GameState::currentPlayer();
    
    currentPlayer->drawCards(2);
    currentPlayer->addActions(1);
}
