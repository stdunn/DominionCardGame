#include "ActionCard_Smithy.h"

ActionCard_Smithy::ActionCard_Smithy(std::string cardName)
    : Card(cardName)
{
    cost = 4;
    type = CardType::Action;
}

/* Description:
*   + 3 Cards
*/

void ActionCard_Smithy::play()
{
    Player* currentPlayer = GameState::curentPlayer();
    
    currentPlayer.drawCards(3);
}