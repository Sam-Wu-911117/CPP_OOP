//Hand.cpp
#include <iostream>
#include "Hand.h"

using namespace std;

Hand::Hand(DeckOfCards& deck)
{
	//�o���i�P
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
	cout << "�o���i�P�O: \n";
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

bool Hand::flush() const //�ˬd�O�_�P���
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
	//�ˬdfaceCount�����O�_�����2
	int times = 0; //�p��X�{�X����l
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
	//�ˬd�O���O�s��
	//faceCount 5��1�s��b�@�_(��10 J Q K A)
	if (faceCount[0] == 1 && faceCount[faceCount.size() - 4] >= 1 && faceCount[faceCount.size() - 3] >= 1 && faceCount[faceCount.size() - 2] >= 1 && faceCount[faceCount.size() - 1] >= 1) //(10 J Q K A)
	{
		return true;
	}
	for (unsigned i = 0; i < faceCount.size() - 4; ++i) //���l
	{
		if (faceCount[i] == 1 && faceCount[i + 1] == 1 && faceCount[i + 2] == 1 && faceCount[i + 3] == 1 && faceCount[i + 4] == 1)
		{
			return true;
		}
	}
	return false;
}

bool Hand::straightFlush() const	//�P�ᶶ
{
	if (Hand::flush() && Hand::straight())
		return true;
	else
		return false;
}

bool Hand::fullHouse() const	//��Ī
{
	if (Hand::pair() && Hand::threeOfAKind())
		return true;
	else
		return false;
}