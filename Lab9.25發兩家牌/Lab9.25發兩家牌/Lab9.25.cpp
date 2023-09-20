#include <iostream>
#include<string>
#include"DeckOfCards.h"
#include"Hand.h"
using namespace std;

DeckOfCards myDeck1;
Hand myHand(myDeck1);    //�ϥ�myDeck�o�ƵP�A�o�@��P(���i�P)
Hand comHand(myDeck1);    //�ϥ�myDeck�o�ƵP�A�o�@��P(���i�P)
string winner(Hand, Hand);

int main(void)
{
	bool plays = 1;
	int cardsNumber = 52;
	DeckOfCards myDeck;
	myDeck.shuffle();
	do {
		Hand myHand1(myDeck);
		myHand = myHand1;
		Hand comHand1(myDeck);
		comHand = comHand1;

		string  gameResult = "";
		myHand.print();
		myHand.setKind();
		myHand.setMaxFace();
		myHand.setSuit();


		cout << "==========computer===========" << endl;

		comHand.print();
		comHand.setKind();
		comHand.setMaxFace();
		comHand.setSuit();

		gameResult = winner(myHand, comHand);
		cout << gameResult << "is the winner." << endl;
		cout << "�O�_�A���@��(�n��J1���n��J0)";
		cin >> plays;
		cardsNumber = cardsNumber - 10;
		if (cardsNumber < 10)
		{
			cout << "�S���P�F" << endl;
		}
	} while (plays == 1 && cardsNumber >= 10);
	system("pause");
}

string winner(Hand player, Hand computer) //��kind,maxFace,suit��j�p
{
	if (myHand.getKind() > comHand.getKind()) //��P��
	{
		return "player";
	}
	else if (myHand.getKind() <  comHand.getKind())
	{
		return "computer";
	}
	else
	{
		if (myHand.getMaxFace() > comHand.getMaxFace()) //��P���j�p
		{
			return "player";
		}
		else if (myHand.getMaxFace() < comHand.getMaxFace())
		{
			return "computer";
		}
		else
		{
			if (myHand.getSuit() > comHand.getSuit()) //����
			{
				return "player";
			}
			else
			{
				return "computer";
			}
		}		
	}
}