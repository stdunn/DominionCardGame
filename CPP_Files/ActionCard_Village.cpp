#include "ActionCard_Village.h"

ActionCard_Village::ActionCard_Village(std::string cardName)
  : Card(std::string cardName)
{
    cost = 3; 
    type = CardType::Action;
}

/* Description:
*   + 2 Actions
*   + 1 Card 
*/
void ActionCard_Village::play()
{
    Player* currentPlayer = GameState::currentPlayer();
    
    currentPlayer->addActions(2);
    currentPlayer->drawCards(1);
}
