//Lab9.24.cpp
#include <iostream>
#include"DeckOfCards.h"
#include"Hand.h"
using namespace std;

int main(void)
{
	DeckOfCards myDeck;
	myDeck.shuffle();

	Hand myHand(myDeck);    //�ϥ�myDeck�o�ƵP�A�o�@��P(���i�P)
	myHand.print();
	cout << "pair :" << myHand.pair() << endl;
	cout << "twoPair :" << myHand.twoPair() << endl;
	cout << "threeOfKind :" << myHand.threeOfAKind() << endl;
	cout << "fullHouse" << myHand.fullHouse() << endl;
	cout << "fourOfKind :" << myHand.fourOfAKind() << endl;
	cout << "flush :" << myHand.flush() << endl;
	cout << "straight :" << myHand.straight() << endl;
	cout << "flushStraight :" << myHand.straightFlush() << endl; 
	system("pause");
}
