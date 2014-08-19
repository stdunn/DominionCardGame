#include "ActionCard_Adventurer.h"

ActionCard_Adventurer::ActionCard_Adventurer(std::string cardName)
: Card(cardName) 
{
    
}

void ActionCard_Adventurer::play(GameState state)
{
    state.currentPlayer()
}
