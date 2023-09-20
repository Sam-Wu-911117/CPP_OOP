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

	bool pair() const; //kind=1
	bool threeOfAKind() const; //kind=3
	bool fourOfAKind() const; //kind=7
	bool flush() const; //kind=5
	bool twoPair() const; //kind=2
	bool straight() const; //kind=4
	bool straightFlush() const; //kind=8
	bool fullHouse() const; //kind=6

	void setKind();
	void setMaxFace();
	void setSuit();
	int getKind();
	int getMaxFace();
	int getSuit();

private:
	std::vector<Card> hand;
	std::vector<int> faceCount; //紀錄點數出現的次數在這一手牌內

	int kind;
	int maxFace;
	int handSuit;
};

#endif
