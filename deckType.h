#ifndef DECKTYPE_H
#define DECKTYPE_H
#include "CARD.h"
class DeckType
{
public:
	DeckType();
	CARD drawCard();// Gets random, unpicked card

	//CARD drawCardTop();// Gets card from top
	//CARD drawCardBottom();
	void shuffle();// Resets the picked cards
	//void placeTop(); //Place a card at the top
	//void placeBottom(); //Place a card at the bottom
	//void placeRandom(); //Place a card randomly
	int cardsTaken = 0; //Number of cards taken

	// **NOTE** All commented methods are methods I would like but seem too complicated to implement now
	// Also they are not neccessary for porker games

private:
	int getNum(); // Gets random, unpicked number from 1-52
	int cards[52] = { 0 }; // Array
	bool inList(int list[52], int num, int taken); // Tests if a number is in a 52 number list
};

#endif // DECKTYPE_H
