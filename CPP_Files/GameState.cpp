#include "GameState.h"


void GameState::initialize(int numOfPlayers)
{
    // if Game State isn't initilized, set default values.
    // Otherwise, do nothing
    if (initialized == false)
    {
        numberOfPlayers = numOfPlayers;
        currentPlayer = 0;
        players = new std::vector<Player*>(numberOfPlayers);
        instantiated = true;
        
    }
}
    
    
Player* GameState::currentPlayer()
{
    return players[currentPlayer];
}
    
