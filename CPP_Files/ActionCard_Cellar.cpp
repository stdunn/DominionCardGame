#include "ActionCard_Cellar.h"

ActionCard_Cellar::ActionCard_Cellar(std::string cardName)
 : Card(cardName)
{
    type = CardType::Action;       
}

/* Description: 
*   +1 Action
*   Discard any number of cards.
*   +1 Card per card discarded.
*
*
*
*
*
*
*
*/

void ActionCard_Cellar::play()
{
    Player* currentPlayer = GameState::currentPlayer();
    int numberOfDiscards;
    
    currentPlayer.addActions(1);
    
    /* IMPLEMENT:
    *   Prompt: discard any number of cards. 
    *   +1 Card per card discarded. 
    *   Button: 'Done discarding'
    *   Button: 'Discard' 
    *   Listener for both buttons. 
    */
    
    /* while (Done Discarding not pressed || !hand.empty() )
    {
        if (discard is pressed)
        {
            currentPlayer.discardCard(c);
            numberOfDiscards++;
        }
    }
    */
    
    for (int i = 0; i < numberOfDiscards; i++)
    {
        currentPlayer.drawCards(numberOfDiscards);
    }
}