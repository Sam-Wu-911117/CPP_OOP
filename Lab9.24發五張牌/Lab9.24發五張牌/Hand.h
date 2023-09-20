//Hand.h
#ifndef HAND_H
#define HAND_H

#include <string>
#include <vector>
#include "Card.h"
#include "DeckOfCards.h"

class Hand
{
public:
	Hand(DeckOfCards& deck);
	void print() const;

	bool pair() const;
	bool threeOfAKind() const;
	bool fourOfAKind() const;
	bool flush() const;
	bool twoPair() const;
	bool straight() const;
	bool straightFlush() const;
	bool fullHouse() const;	

private:
	std::vector<Card> hand;
	std::vector<int> faceCount; //紀錄點數出現的次數在這一手牌內
};

#endif