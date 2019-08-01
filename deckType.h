#ifndef DECKTYPE_H
#define DECKTYPE_H
#include "CARD.h"
class DeckType
{
public:
	DeckType();
	CARD drawCard();// Gets random, unpicked card
	void shuffle();// Resets the picked cards
	int cardsTaken = 0; //Number of cards taken

private:
	int getNum(); // Gets random, unpicked number from 1-52
	int cards[52] = { 0 }; // Array
	bool inList(int list[52], int num, int taken); // Tests if a number is in a 52 number list
};

#endif // DECKTYPE_H