#include "GameState.h"



private:
    int numberOfPlayers;
    int currentPlayer;
    bool instantiated = false;
    
GameState::GameState(int numOfPlayers)
: numberOfPlayers = numOfPlayers, players = std::vector<Player*>(numberOfPlayers)
{

}
    
GameState::~GameState();
    


void GameState::instantiateGameState(int numOfPlayers)
{
    if (instantiated == false)
    {
        return GameState(numOfPlayers);
    }
    else
        return this;
}
    
    Player* currentPlayer();
    
