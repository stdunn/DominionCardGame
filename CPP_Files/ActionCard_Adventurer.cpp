#include "ActionCard_Adventurer.h"

ActionCard_Adventurer::ActionCard_Adventurer(std::string cardName)
: Card(cardName) 
{
    CardType = CardType::Action;
}

/* Description:
*   Reveal cards from your deck until you reveal 2 Treasure cards. 
*   Put those Treasure cards in your hand and discard the other 
*   revealed cards.
*
* Inputs:
*   None
*
* Returns:
*   void
*
* Notes:
*   Display revealedCards to the player
*/ 

void ActionCard_Adventurer::play()
{
    Player* currentPlayer = GameState::currentPlayer();
    
    std::vector<Card*> revealedCards;
    int numberOfTreasureCards = 0;
    
    while (numberOfTreasureCards < 2)
    {
        Card* topCard = currentPlayer.topOfDeck();
        
        revealedCards.push_back(topCard);
        
        if (topCard->getType() == CardType::Treasure)
        {
            numberOfTreasureCards++;
            currentPlayer.drawCards(1);
        }
        else
        {
            currentPlayer.discardTop();
        }
    }
}
