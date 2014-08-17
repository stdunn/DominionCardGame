/* The GameState class is a singleton that
 * keeps track of the game state.
 * It knows about the current player and has access
 * to all of the other players.  Any update to the
 * game state will happen through this class.
*/

#include "Player.h"
#include "Card.h"

#include <vector>
class GameState
{
private:
    int numberOfPlayers;
    bool instantiated = false;
    
    GameState();
    ~GameState();
    
public:
    std::vector<Player*> players;
    
    void InstantiateGameState();
    
    Player currentPlayer();
    
    
};

