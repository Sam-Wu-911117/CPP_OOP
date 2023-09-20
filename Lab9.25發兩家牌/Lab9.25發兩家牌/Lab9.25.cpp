#include <iostream>
#include<string>
#include"DeckOfCards.h"
#include"Hand.h"
using namespace std;

DeckOfCards myDeck1;
Hand myHand(myDeck1);    //使用myDeck這副牌，發一手牌(五張牌)
Hand comHand(myDeck1);    //使用myDeck這副牌，發一手牌(五張牌)
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
		cout << "是否再玩一局(要輸入1不要輸入0)";
		cin >> plays;
		cardsNumber = cardsNumber - 10;
		if (cardsNumber < 10)
		{
			cout << "沒有牌了" << endl;
		}
	} while (plays == 1 && cardsNumber >= 10);
	system("pause");
}

string winner(Hand player, Hand computer) //用kind,maxFace,suit比大小
{
	if (myHand.getKind() > comHand.getKind()) //比牌型
	{
		return "player";
	}
	else if (myHand.getKind() <  comHand.getKind())
	{
		return "computer";
	}
	else
	{
		if (myHand.getMaxFace() > comHand.getMaxFace()) //比牌的大小
		{
			return "player";
		}
		else if (myHand.getMaxFace() < comHand.getMaxFace())
		{
			return "computer";
		}
		else
		{
			if (myHand.getSuit() > comHand.getSuit()) //比花色
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