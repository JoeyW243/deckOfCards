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
	const int HANDSIZE = 5; //Get a hand of 10

	DeckType currentDeck;  //Initialize object
	CARD userHand[HANDSIZE];   //Array of cards with a size of the hand
	CARD computerHand[HANDSIZE];   //Opponent's hand
	string temp;	       //Temp string used later for cout-ing the suit as a string

	string discard;

	for (int i = 0; i < HANDSIZE; i++) { //Fill hand with cards
		userHand[i] = currentDeck.drawCard();
		computerHand[i] = currentDeck.drawCard();
	}

	for (int i = 0; i < HANDSIZE; i++) { //Display all cards
		temp = suitToString(userHand[i].suit);
		cout << i + 1 << ":  " << userHand[i].num << " of " << temp << endl;
	}

	cout << "Which cards would you like to discard? \n"; //Examples: 23, 123, (empty), 35, etc.
	cin >> discard;
	
	for (int i = 0; i < HANDSIZE; i++) {
		if (discard.find(to_string(i + 1)) != string::npos) {
			userHand[i] = currentDeck.drawCard();
		}
	}
	cout << endl << endl;

	for (int i = 0; i < HANDSIZE; i++) { //Display all cards
		temp = suitToString(userHand[i].suit);
		cout << i + 1 << ":  " << userHand[i].num << " of " << temp << endl;
	}
	
	cout << endl << "Computer's Hand: \n"; 
	for (int i = 0; i < HANDSIZE; i++) { //Display all cards
		temp = suitToString(computerHand[i].suit);
		cout << i + 1 << ":  " << computerHand[i].num << " of " << temp << endl;
	}
	/*
	cout << "Now shuffling \n...\n...\n...\n"; //Shuffle cards
	currentDeck.shuffle();


	for (int i = 0; i < HANDSIZE; i++) { //Fill hand with cards again
		hand[i] = currentDeck.drawCard();
	}

	for (int i = 0; i < HANDSIZE; i++) { //Display all cards
		temp = suitToString(hand[i].suit);
		cout << "Card number " << i << " is " << hand[i].num << " of " << temp << endl;
	}
	*/

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