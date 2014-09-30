#include "ActionCard_ThroneRoom.h"

ActionCard_ThroneRoom::ActionCard_ThroneRoom(std::string cardName)
    : Card(cardName)
{
    cost = 4;
    type = CardType::Action;
}

/* Description:
* Choose an Action card in your hand. Play it twice.
*/

void ActionCard_ThroneRoom::play()
{
    Player* currentPlayer = GameState::currentPlayer();
    
    // Select card in hand to upgrade (CHOSEN_CARD)
    CHOSEN_CARD.play();
    CHOSEN_CARD.play();
    
}
