//card.cpp
#include "card.h"

using namespace std;

const string Card::faceNames[FACES] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
const string Card::suitNames[SUIT] = { "¶Â³³","¬õ¤ß","¤è¶ô","±öªá" };

Card::Card(int cardFace, int cardSuit)
{
	face = (cardFace >= 0 && cardFace < FACES) ? cardFace : 0;
	suit = (cardSuit >= 0 && cardSuit < SUIT) ? cardSuit : 0;
}

std::string Card::toString() const
{
	return suitNames[suit] + "-" + faceNames[face];

}

