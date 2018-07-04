#include "deckType.h"
#include "CARD.h"
#include <ctime>
#include <cstdlib>

using namespace std;

deckType::deckType()
{
}

CARD deckType::getCard() // Gets random, unpicked card
{
	CARD card;
	int num = getNum();
	if (num < 14) {
		card.suit = SPADES;
		card.num = num;
	}
	else if (num < 27) {
		card.suit = HEARTS;
		card.num = num - 13;
	}
	else if (num < 40) {
		card.suit = CLUBS;
		card.num = num - 26;
	}
	else if (num < 53) {
		card.suit = DIAMONDS;
		card.num = num - 39;
	}
	return card;
}

void deckType::shuffle() // Resets picked cards
{
	for (int i = 0; i < 52; i++) {
		cards[i] = 0;
	}
	cardsTaken = 0;
}

int deckType::getNum()// Gets random, unpicked number from 1-52
{
	srand(time(0));
	int num = rand() % 52 + 1;
	while (inList(cards, num, cardsTaken))
		num = rand() % 52 + 1;
	cards[cardsTaken++] = num;
	return num;
}

bool deckType::inList(int list[52], int num, int taken)  // Tests if a number is in a 52 number list
{
	for (int i = 0; i < taken; i++) {
		if (num == list[i])
			return true;
		if (list[i] == 0)
			return false;
	}
	return false;
}