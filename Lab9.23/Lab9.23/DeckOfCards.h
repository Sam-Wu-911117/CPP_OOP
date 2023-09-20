//DeckOfCard.h

#ifndef DECKOFCARD_H
#define DECKOFCARD_H

#include"Card.h"
#include <vector>

class DeckOfCards
{
public:
	DeckOfCards();
	void shuffle();
	Card dealCard();
	bool moreCard();


private:
	std::vector< Card > deck;
	unsigned int currentCard;
};

#endif //DECKOFCARD_H

