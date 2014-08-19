/* The GameState class is a static class that
 * keeps track of the game state.
 * It knows about the current player and has access
 * to all of the other players.  Any update to the
 * game state will happen through this class.
*/
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Player.h"
#include "Card.h"

#include <vector>

static class GameState
{
private:
    int numberOfPlayers;
    int currentPlayer;
    bool initialized = false;
    
public:

    /* A vector of pointers to players. 
    *   NOTE: Currently a public attribute
    *   to simplify attack card implementation.
    */
    std::vector<Player*> players;
    
    /* Initialize the game state by providing
    *   a number of players. All other attributes
    *   are set to default values.
    */
    void initialize(int numOfPlayers);
    
    // A destructor for the static class.  Deletes all references.
    void end();
    
    // returns a pointer to the current player.
    Player* currentPlayer();
    
    
};

#endif // GAMESTATE_H


