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
	
	// Card groups
	std::vector<Card*> hand;
	std::vector<Card*> discard;
	std::vector<Card*> cardsInPlay;
	std::vector<Card*> deck;
	
	// Additional buys (given as a result of action cards)
	std::vector<SpecialBuy*> specialBuys;
	
	int actions;
	int buys;
	int buyPower;

public:
	Player();
	~Player();
	
	// Player state changes
	void addActions(int actionsToAdd);
	void addBuys(int buysToAdd);
	void addTreasure(int treasureToAdd);

    // Player actions
    void drawCards(int numOfCards);
	void play(ActionCard* c, GameState& state);
	void buy(Card* c, GameState& state);
	void discardCard(Card* c);

	void reshuffleDeck();

	Card* topOfDeck();

	void addToTopOfDeck(Card* c);

	void discardToTopOfDeck(Card* c);

	void discardTop();

	int getActions();
	
	int getBuys();

	int getBuyPower();

	void endTurn();
	
	int getDeckSize();
};

#endif // PLAYER_H

