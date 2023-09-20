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
	case 0: //���P

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
	case 1: //��l
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
	case 2: //�T��
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
	case 3: //���
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
	case 4: //���l
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
	case 5: //�P��
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
	case 6: //��Ī
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
	case 7: //�K��
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
	case 8: //�P�ᶶ
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
