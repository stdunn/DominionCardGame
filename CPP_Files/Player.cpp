// import java.util.ArrayList;
// import java.util.Random;
// import java.util.Stack;
#include "Player.h"

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
	
void Player::addCards(int cardsToAdd)
{
	for(int i = 0; i < cardsToAdd; i++)
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
	
void Player::play(ActionCard c, GameState state)
{
	
	for(int i = 0; i < hand.size(); i++)
	{
		if(hand.get(i).getName().equals(c.getName()))
		{
			cardsInPlay.add(hand.remove(i));
			c.play(state);
		}
	}
}
	
void Player::discardCard(Card c)
{
	for(int i = 0; i < hand.size(); i++)
	{
		if(hand.get(i).getName().equals(c.getName()))
		{
			discard.add(hand.remove(i));
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
	
Card Player::topOfDeck()
{
	if(deck.empty())
	{
		reshuffleDeck();
		discard.clear();
	}
	return deck.peek();
}
	
void Player::addToTopOfDeck(Card c)
{
	deck.push(c);
}
	
void Player::discardToTopOfDeck(Card c)
{
	for(int i = 0; i < hand.size(); i++)
	{
		if(hand.get(i).getName().equals(c.getName()))
		{
			hand.remove(i);
			deck.push(c);
			return;
		}
	}
		
}
	
void Player::discardTop()
{
	if(deck.isEmpty())
	{
		deck.reshuffle(discard);
		discard.clear();
	}
	discard.add(deck.pop());	
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
	actions = 1;
	buys = 1;
	buyPower = 0;
		
	for(Card card: cardsInPlay)
	{
		discard.add(card);
	}
	cardsInPlay.clear();
		
	for(Card card: hand)
	{
		discard.add(card);
	}
	hand.clear();
		
	addCards(5);
}
	
int Player::getDeckSize()
{
	return deck.size();
}

std::vector<Card> Player::getHand()
{
	return hand;
}