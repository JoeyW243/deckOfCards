#ifndef CARD_H
#define CARD_H

enum suitType { SPADES, HEARTS, CLUBS, DIAMONDS };
enum hands {RF, SF, FoK, FH, F, S, ToK, TP, P, HC}; //Royal Flush, Straight Flush, 4 of a Kind, Full House, Flush, Staight, 3 of a Kind,Two Pair, Pair, High Card.

struct CARD {
	int id = 0;
	int num = 0;
	suitType suit;
};

struct CardNode {
	CARD card;
	CardNode *next;
	CardNode *prev;
};

class Hand
{
public:
	//Constructors
	Hand();
	Hand(CARD firstCard);
	Hand(CardNode firstCard);
	~Hand();

	//Methods

	void sortHand(); //Sorts the hand for reasons
	void addCard(CARD newCard); //Adds a card to the front of the hand
	void removeCard(int index);
	void replaceCard(CARD newCard, int index); //replaces a desired card
	CARD getCard(int index); //Returns a desired card
	hands bestHand(); //Returns the best possible hand
	CARD highCard();
	

private:
	CardNode *first; //First node of a linked list
	int handSize = 0; //Size of the hand ***************

};

#endif // !CARD_H

