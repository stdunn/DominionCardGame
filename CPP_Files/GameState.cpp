#include "GameState.h"

#include <iostream>
#include <fstream>

void GameState::initialize(int numOfPlayers)
{
    // if Game State isn't initilized, set default values.
    // Otherwise, do nothing
    if (initialized == false)
    {
        numberOfPlayers = numOfPlayers;
        currentPlayer = 0;
        emptyDecks = 0;
        
        players = new std::vector<Player*>(numberOfPlayers);
        for (int i = 0; i < numberOfPlayers; i++)
        {
            players[i] = new Player();
        }
        
        
        availableCards = new std::vector<ActionCard*>();
        
        /* read from an inputfile, and create new action card
        *   for each line (card name).
        */
        
        std::string actionCardName;
        std::ifstream actionCardList;
        actionCardList.open (INPUT_FILE_AVAILABLE_CARDS);
        
        int filePos = 0;
        while(!actionCardList.eof)
        {
            getline(actionCardList, actionCardName); 
            availableCards.push_back(new std::vector<ActionCard*>(ACTION_CARD_STACK_SIZE));
            for (int i = 0; i < ACTION_CARD_STACK_SIZE; i++)
            {
                availableCards[filePos].push_back(ActionCardFactory.create(actionCardName));
            }
            
            availableCardsMap.push_back(actionCardName, filePos);
            filePos++;
        }
        
        actionCardList.close();
        
        instantiated = true;
    }
}
    
void GameState::end()
{
    for (int i = 0; i < numberOfPlayers; i++)
    {
        delete players[i];
    }
    
    for (Card* c: availableCards)
    {
        delete c;
    }
}

Player* GameState::currentPlayer()
{
    return players[currentPlayer];
}

bool GameState::removeCard(Card* c)
{
    int availableCardsIndex = availableCardsMap.at(c->getName());
    
    if (availableCards[availableCardsIndex].size() == 0)
    {
        return false;
    }
    
    availableCards[availableCardsIndex].pop_back();
    
    if (availableCards[availableCardsIndex].size() == 0)
    {
        emptyDecks++;
    }
}    

