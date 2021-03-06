// import java.util.ArrayList;
// import java.util.Random;
// import java.util.Stack;
#include "Player.h"

#include <stdexcept>

Player::Player()
{
	actions = 1;
	buys = 1;
	buyPower = 0;

	for(int estates = 3; estates > 0; estates--)
	{
		discard.push_back(new VictoryCard("Estate"));
	}

	for(int coppers = 7; coppers > 0; coppers--)
	{
		discard.push_back(new TreasureCard("Copper"));
	}

	reshuffleDeck();
}

Player::~Player()
{
}
	
// ------------------------------------------------------
// Player state changes 
void Player::addActions(int actionsToAdd)
{
	actions += actionsToAdd;
}
	
void Player::addBuys(int buysToAdd)
{
	buys += buysToAdd;
}
	
void Player::addTreasure(int treasureToAdd)
{
	buyPower += treasureToAdd;
}
	
// Player actions
void Player::drawCards(int numOfCards)
{
    for(int i = 0; i < numOfCards; i++)
    {
        if(deck.empty())
        {
            reshuffleDeck();
            discard.clear();
        }
        hand.push_back(deck.back());
        deck.pop_back();
    }    
}

void Player::play(ActionCard* c)
{
	
	for(int i = 0; i < hand.size(); i++)
	{
		if(*(hand[i]) == *c)
		{
			cardsInPlay.push_back(hand[i]);
			hand.erase(hand.begin() + i);
			c->play(state);
		}
	}
}
	
void Player::buy(Card* c) throws std::runtime_error
{
    if (buys < 1)
    {
        throw new notEnoughBuysException \
            ("Not enough buys to make purchase.");
    }
    else if (buyPower < c->getCost())
    {
        throw new notEnoughBuyPowerException \
            ("Not enough buy power to make purchase.");
    }
    else
    {
        try // try to remove card
        {
            bool buySuccess = GameState::removeCard(c);
        }
        catch (std::out_of_range& oor)
        {
            /* Two possibilities:
            *   1)  the arg 'c' isn't a real card (improbable)
            *   2) 'c' is a victory or treasure card
            *   Only the 2nd is taken care of here. 
            */
            buySuccess = true;
        }
        
        if (buySuccess)
        {
            discard.push_back(c);    
        }
        else
        {
            // Tell the player there is no more of the card
            // available for purchase.
        }
    }
}

void Player::discardCard(Card* c)
{
	for(int i = 0; i < hand.size(); i++)
	{
		if(*(hand[i]) == *c)
		{
			discard.push_back(hand[i]);
			hand.erase(hand.begin() + i);
		}
	}
}

void Player::reshuffleDeck()
{
	int nextCard;

	while(!discard.empty())
	{
		nextCard = rand() % discard.size();
		deck.push_back(discard[nextCard]);
		discard.erase(discard.begin() + nextCard);
	}
}
	
Card* Player::topOfDeck()
{
	if(deck.empty())
	{
		reshuffleDeck();
		discard.clear();
	}
	return deck.back();
}
	
void Player::addToTopOfDeck(Card* c)
{
	deck.push_back(c);
}
	
void Player::discardToTopOfDeck(Card* c)
{
	for(int i = 0; i < hand.size(); i++)
	{
		if(*(hand[i]) == *c)
		{
			hand.erase(i);
			deck.push(c);
			return;
		}
	}
	
	// if card not found in player's hand
	std::string errorMessage ("Runtime error: The following card \
	    could not be found in a player's hand: " + c->getName());
	throw new cardNotFoundException(errorMessage);
		
}
	
void Player::discardTop()
{
	if(deck.empty())
	{
		reshuffleDeck();
		discard.clear();
	}
	discard.push_back(deck.back());
	deck.pop_back();
}
	
int Player::getActions()
{
	return actions;
}
	
int Player::getBuys()
{
	return buys;
}
	
int Player::getBuyPower()
{
	return buyPower;
}
	
void Player::endTurn()
{
    // CHECK IF GAME IS OVER
    /*
    */
    
    // reset attributes for next turn
	actions = 1;
	buys = 1;
	buyPower = 0;
		
	// discard all cards in play	
	for(Card* card: cardsInPlay)
	{
		discard.push_back(card);
	}
	cardsInPlay.clear();
		
	// discard all cards in the hand
	for(Card* card: hand)
	{
		discard.push_back(card);
	}
	hand.clear();
		
	drawCards(5);
}
	
int Player::getDeckSize()
{
	return deck.size();
}
