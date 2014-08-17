// import java.util.ArrayList;
// import java.util.Random;
// import java.util.Stack;

#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <stdlib.h>
#include <vector>

class Deck
{
public:
	Deck();
	
	void reshuffle(std::vector<Card> discard);
};

#endif // DECK_H
