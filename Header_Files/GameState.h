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

#include <map>
#include <vector>
#include <string>

static class GameState
{
private:

    const std::string INPUT_FILE_AVAILABLE_CARDS = "ActionCardList";
    const int ACTION_CARD_STACK_SIZE = 10;
    
    int numberOfPlayers;
    int currentPlayer;
    bool initialized = false;
    
    /* A mapping of action card names and indexes for
    * the availableCards vector of action card vectors
    */
    
    std::map<std::string , int> availableCardsMap;
    
public:

    /* A vector of pointers to players. 
    *   NOTE: Currently a public attribute
    *   to simplify attack card implementation.
    */
    std::vector<Player*> players;
    
    /* A vector of vectors of pointers to action cards. 
    *   This represents all action cards available
    *   players for purchase.purchase.
    *
    *   NOTE: The initialize method adds cards
    *   to this vector according to the local input
    *   file "ActionCardList"
    */
    
    std::vector<std::vector<ActionCard*>> availableCards;
    
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


