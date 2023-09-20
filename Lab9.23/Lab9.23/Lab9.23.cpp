#include <iostream>
#include "DeckOfCards.h"
using namespace std;

int main()
{
	DeckOfCards myDeck;
	
	myDeck.shuffle();

	for (int i = 1; myDeck.moreCard(); i++)
	{
		cout << myDeck.dealCard().toString();
	}

	system("pause");
}