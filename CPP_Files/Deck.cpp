// import java.util.ArrayList;
// import java.util.Random;
// import java.util.Stack;
#include "Deck.h"


Deck::Deck()
	: std::vector<Card>
{
}

Deck::reshuffle(std::vector<Card> discard)
{
	int nextCard;
		
	while(!discard.empty())
	{
		nextCard = rand() % discard.size();
		this.push(discard.remove(nextCard));
	}
}

Deck::~Deck(void)
{
}
