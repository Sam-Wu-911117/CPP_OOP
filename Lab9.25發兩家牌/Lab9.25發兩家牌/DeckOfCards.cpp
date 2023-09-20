//DeckOfCards.cpp
#include "DeckOfCards.h"
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

DeckOfCards::DeckOfCards()
{
	for (int i = 0; i < Card::SUIT; i++)
	{
		for (int j = 0; j < Card::FACES; j++)
		{
			Card testCard(j, i);

			deck.push_back(testCard);
		}
	}
	currentCard = 0;
}
void DeckOfCards::shuffle()
{
	srand(static_cast<unsigned> (time(0)));
	int Random;
	Card memoryDeck(1, 1);
	for (int i = 0; i < Card::FACES * Card::SUIT; i++)
	{
		unsigned int random = rand() % Card::FACES * Card::SUIT;
		memoryDeck = deck[i];
		deck[i] = deck[random];
		deck[random] = memoryDeck;
	}
}
Card DeckOfCards::dealCard()
{
	return deck[currentCard++];
}
bool DeckOfCards::moreCard()
{
	return currentCard < deck.size();
}

