#include "deckType.h"
#include "CARD.h"
#include <ctime>
#include <cstdlib>

using namespace std;

DeckType::DeckType()
{
}

CARD DeckType::drawCard() // Gets random, unpicked card
{
	CARD card;
	int num = getNum(); //Get random unpicked number 1-52
	card.id = num;
	//Give that number personality
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

CARD DeckType::completeCard(int id)
{
	CARD card;
	int num = id;
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

CARD DeckType::completeCard(int num, suitType suit)
{
	CARD card;
	card.num = num;
	card.suit = suit;

	switch (suit)
	{
	case SPADES:
		card.id = num;
		break;
	case HEARTS:
		card.id = num + 13;
		break;
	case CLUBS:
		card.id = num + 26;
		break;
	case DIAMONDS:
		card.id = num + 39;
		break;
	default:
		break;
	}

	return card;
}

void DeckType::shuffle() // Resets picked cards    ||    WARNING: CANNOT SHUFFLE TWICE IN THE SAME INSTANT
{
	for (int i = 0; i < 52; i++) {
		cards[i] = 0;
	}
	cardsTaken = 0;
}

int DeckType::getNum()// Gets random, unpicked number from 1-52
{
	srand(time(0));
	int num = rand() % 52 + 1;
	while (inList(cards, num, cardsTaken))//This will be an infinite loop if all cards are taken, should fix
		num = rand() % 52 + 1;
	cards[cardsTaken++] = num; // Adds the taken card to the taken cards array
	return num;
}

bool DeckType::inList(int list[52], int num, int taken)  // Tests if a number is in a 52 number list
{
	for (int i = 0; i < taken; i++) {
		if (num == list[i])
			return true;
		if (list[i] == 0) //Gone through all cards in list
			return false;
	}
	return false;
}