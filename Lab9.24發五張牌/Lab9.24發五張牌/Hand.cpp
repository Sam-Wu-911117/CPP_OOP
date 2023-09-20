//Hand.cpp
#include <iostream>
#include "Hand.h"

using namespace std;

Hand::Hand(DeckOfCards& deck)
{
	//發五張牌
	for (unsigned i = 0; i < 5; ++i)
	{
		hand.push_back(deck.dealCard());
	}
	for (unsigned i = 0; i < 13; ++i)
	{
		faceCount.push_back(0);
	}
	for (unsigned i = 0; i < hand.size(); i++)
	{
		faceCount[hand[i].getFace()]++;
	}
}

void Hand::print() const
{
	cout << "這五張牌是: \n";
	for (unsigned i = 0; i < 5; ++i)
	{
		cout << hand[i].toString() << "   ";
	}
	cout << endl;
}

bool Hand::pair() const
{
	for (unsigned i = 0; i < faceCount.size(); ++i)
	{
		if (faceCount[i] == 2)
		{
			return true;
		}
	}
	return false;
}

bool Hand::threeOfAKind() const
{
	for (unsigned i = 0; i < faceCount.size(); ++i)
	{
		if (faceCount[i] == 3)
		{
			return true;
		}
	}
	return false;
}

bool Hand::fourOfAKind() const
{
	for (unsigned i = 0; i < faceCount.size(); ++i)
	{
		if (faceCount[i] == 4)
		{
			return true;
		}
	}
	return false;
}

bool Hand::flush() const //檢查是否同花色
{
	int suit = hand[0].getSuit();
	for (unsigned i = 1; i < faceCount.size(); ++i)
	{
		if (hand[i].getSuit() != suit)
		{
			return false;
		}
	}
	return true;
}

bool Hand::twoPair() const
{
	//檢查faceCount元素是否有兩個2
	int times = 0; //計算出現幾次對子
	for (unsigned i = 0; i < faceCount.size(); ++i)
	{
		if (faceCount[i] == 2)
		{
			times++;
		}
		if (times >= 2)
		{
			return true;
		}
	}
	return false;
}

bool Hand::straight() const
{
	//檢查是不是連號
	//faceCount 5個1連續在一起(有10 J Q K A)
	if (faceCount[0] == 1 && faceCount[faceCount.size() - 4] >= 1 && faceCount[faceCount.size() - 3] >= 1 && faceCount[faceCount.size() - 2] >= 1 && faceCount[faceCount.size() - 1] >= 1) //(10 J Q K A)
	{
		return true;
	}
	for (unsigned i = 0; i < faceCount.size() - 4; ++i) //順子
	{
		if (faceCount[i] == 1 && faceCount[i + 1] == 1 && faceCount[i + 2] == 1 && faceCount[i + 3] == 1 && faceCount[i + 4] == 1)
		{
			return true;
		}
	}
	return false;
}

bool Hand::straightFlush() const	//同花順
{
	if (Hand::flush() && Hand::straight())
		return true;
	else
		return false;
}

bool Hand::fullHouse() const	//葫蘆
{
	if (Hand::pair() && Hand::threeOfAKind())
		return true;
	else
		return false;
}