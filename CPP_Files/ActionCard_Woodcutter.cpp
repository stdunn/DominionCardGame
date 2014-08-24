#include "ActionCard_Woodcutter.h"

ActionCard_Woodcutter::ActionCard_Woodcutter(std::string cardName)
    : Card(cardName)
{
    type = CardType::Action;
}

/* Description:
*    +1 Buy
*    + $2 
*/

void ActionCard_Woodcutter::play()
{
    Player* currentPlayer = GameState::currentPlayer();
    
    currentPlayer.addBuys(1);
    currentPlayer.addTreasure(2);
}