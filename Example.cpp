// Example program used to show off/test what the class can do
//

#include <iostream>
#include "deckType.h"
#include "CARD.h"
#include <string>

using namespace std;

string suitToString(suitType suit); // Changes the suit type to a string

int main()
{
	const int HANDSIZE = 10; //Get a hand of 10

	deckType currentDeck;  //Initialize object
	CARD hand[HANDSIZE];   //Array of cards with a size of the hand
	string temp;	       //Temp string used later for cout-ing the suit as a string

	for (int i = 0; i < HANDSIZE; i++) { //Fill hand with cards
		hand[i] = currentDeck.getCard();
	}

	for (int i = 0; i < HANDSIZE; i++) { //Display all cards
		temp = suitToString(hand[i].suit);
		cout << "Card number " << i << " is " << hand[i].num << " of " << temp << endl;
	}

	cout << "Now shuffling \n...\n...\n...\n"; //Shuffle cards
	currentDeck.shuffle();


	for (int i = 0; i < HANDSIZE; i++) { //Fill hand with cards again
		hand[i] = currentDeck.getCard();
	}

	for (int i = 0; i < HANDSIZE; i++) { //Display all cards
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
