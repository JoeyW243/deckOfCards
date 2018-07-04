// deckOfCardsClass.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "deckType.h"
#include "CARD.h"
#include <string>

using namespace std;

string suitToString(suitType suit); // Changes the suit type to a string

int main()
{
	const int HANDSIZE = 10;

	deckType currentDeck;
	CARD hand[HANDSIZE];
	string temp;

	for (int i = 0; i < HANDSIZE; i++) {
		hand[i] = currentDeck.getCard();
	}

	for (int i = 0; i < HANDSIZE; i++) {
		temp = suitToString(hand[i].suit);
		cout << "Card number " << i << " is " << hand[i].num << " of " << temp << endl;
	}

	cout << "Now shuffling \n...\n...\n...\n";
	currentDeck.shuffle();


	for (int i = 0; i < HANDSIZE; i++) {
		hand[i] = currentDeck.getCard();
	}

	for (int i = 0; i < HANDSIZE; i++) {
		temp = suitToString(hand[i].suit);
		cout << "Card number " << i << " is " << hand[i].num << " of " << temp << endl;
	}

	system("pause");


    return 0;
}

string suitToString(suitType suit) {
	switch (suit)
	{
	case 0:
		return "spades";
		break;
	case 1:
		return "hearts";
		break;
	case 2:
		return "clubs";
		break;
	case 3:
		return "diamonds";
		break;
	default:
		break;
	}
}