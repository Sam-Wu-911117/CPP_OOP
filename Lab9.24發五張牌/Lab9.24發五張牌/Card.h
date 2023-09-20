//card.h
#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
public:
	static const int FACES = 13;
	static const int SUIT = 4;
	Card(int cardFace, int cardSuit);

	std::string toString() const;

	int getFace() const
	{
		return face;
	}

	int getSuit() const
	{
		return suit;
	}




private:
	int face; //A¡B2¡B3...J¡BQ¡BK---->0¡B1¡B2¡B3....10¡B11¡B12(K)
	int suit; //¶Â³³¡B¬õ¤ß¡B¤è¶ô¡B±öªá--->0¡B1¡B2¡B3

	static const std::string faceNames[FACES];
	static const std::string suitNames[SUIT];
};



#endif // !CARD_H
