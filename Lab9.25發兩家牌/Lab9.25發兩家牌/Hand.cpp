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

void Hand::setKind()
{
	if (pair() == true)
	{
		kind = 1;
	}
	else if (twoPair() == true)
	{
		kind = 2;
	}
	else if (threeOfAKind() == true)
	{
		kind = 3;
	}
	else if (straight() == true)
	{
		kind = 4;
	}
	else if (flush() == true)
	{
		kind = 5;
	}
	else if (fullHouse() == true)
	{
		kind = 6;
	}
	else if (fourOfAKind() == true)
	{
		kind = 7;
	}
	else if (straightFlush() == true)
	{
		kind = 8;
	}
	else
	{
		kind = 0;
	}
}

void Hand::setMaxFace()
{
	int times = 0;
	switch (getKind())
	{
	case 0: //散牌

		if (faceCount[0] == 1)
			maxFace = 13;
		else
		{
			for (unsigned i = 0; i < faceCount.size(); i++)
			{
				if (faceCount[i] == 1)
				{
					times++;
					if (times == 5)
						maxFace = i;
				}
			}
		}
	case 1: //對子
		if (faceCount[0] == 2)
			maxFace = 13;
		else
		{
			for (unsigned i = 0; i < faceCount.size(); i++)
			{
				if (faceCount[i] == 2)
				{
						maxFace = i;
				}
			}
		}
	case 2: //三條
		if (faceCount[0] == 3)
			maxFace = 13;
		else
		{
			for (unsigned i = 0; i < faceCount.size(); i++)
			{
				if (faceCount[i] == 3)
				{
					maxFace = i;
				}
			}
		}
	case 3: //兩對
		if (faceCount[0] == 2)
			maxFace = 13;
		else
		{
			for (unsigned i = 0; i < faceCount.size(); i++)
			{
				if (faceCount[i] == 2)
				{
					maxFace = i;
				}
			}
		}
	case 4: //順子
		if (faceCount[0] == 1)
			maxFace = 13;
		else
		{
			for (unsigned i = 0; i < faceCount.size(); i++)
			{
				if (faceCount[i] == 1)
				{
						maxFace = i;
				}
			}
		}
		if (faceCount[0] == 1 && faceCount[1] == 1 && faceCount[2] == 1 && faceCount[3] == 1 && faceCount[4] == 1) //A 2 3 4 5
		{
			maxFace = 4;
		}
	case 5: //同花
		if (faceCount[0] == 1)
			maxFace = 13;
		else
		{
			for (unsigned i = 0; i < faceCount.size(); i++)
			{
				if (faceCount[i] == 1)
				{
					times++;
					if (times == 5)
						maxFace = i;
				}
			}
		}
	case 6: //葫蘆
		if (faceCount[0] == 3)
			maxFace = 13;
		else
		{
			for (unsigned i = 0; i < faceCount.size(); i++)
			{
				if (faceCount[i] == 3)
				{
					maxFace = i;
				}
			}
		}
	case 7: //鐵支
		if (faceCount[0] == 4)
			maxFace = 13;
		else
		{
			for (unsigned i = 0; i < faceCount.size(); i++)
			{
				if (faceCount[i] == 4)
				{
					maxFace = i;
				}
			}
		}
	case 8: //同花順
		if (faceCount[0] == 1)
			maxFace = 13;
		else
		{
			for (unsigned i = 0; i < faceCount.size(); i++)
			{
				if (faceCount[i] == 1)
				{
					maxFace = i;
				}
			}
		}
		if (faceCount[0] == 1 && faceCount[1] == 1 && faceCount[2] == 1 && faceCount[3] == 1 && faceCount[4] == 1) //A 2 3 4 5
		{
			maxFace = 4;
		}
	}
	
}

void Hand::setSuit()
{
	for (unsigned i = 1; i < hand.size(); i++)
		for (unsigned j = i; j < hand.size(); j++)
		{
			if (hand[i - 1].getFace() < hand[j].getFace())
			{
				Card temp = hand[i - 1];
				hand[i - 1] = hand[j];
				hand[j] = temp;
			}
		}
	handSuit = hand[0].getSuit();
}

int Hand::getKind()
{
	return kind;
}

int Hand::getMaxFace()
{
	return maxFace;
}

int Hand::getSuit()
{
	return handSuit;
}
