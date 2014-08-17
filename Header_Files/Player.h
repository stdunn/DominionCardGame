#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "ActionCard.h"
#include "TreasureCard.h"
#include "VictoryCard.h"
#include "Deck.h"
#include "GameState.h"
#include "SpecialBuy.h"

#include <vector>

class Player
{

private:
	
	std::vector<Card*> hand;
	std::vector<Card*> discard;
	std::vector<Card*> cardsInPlay;
	std::vector<Card*> deck;
	
	std::vector<SpecialBuy*> specialBuys;
	
	int actions;
	int buys;
	int buyPower;

public:
	Player();
	~Player();
	
	void addCards(int cardsToAdd);

	void addActions(int actionsToAdd);

	void addBuys(int buysToAdd);

	void addTreasure(int treasureToAdd);

	void play(ActionCard c, GameState state);

	void discardCard(Card c);

	void reshuffleDeck();

	Card topOfDeck();

	void addToTopOfDeck(Card c);

	void discardToTopOfDeck(Card c);

	void discardTop();

	int getActions();
	
	int getBuys();

	int getBuyPower();

	void endTurn();
	
	int getDeckSize();

	std::vector<Card> getHand();

};

#endif // PLAYER_H

