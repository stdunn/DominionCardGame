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
    
}