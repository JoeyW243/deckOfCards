#include "CARD.h"
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;


Hand::Hand()
{
	first = NULL;
	handSize = 0;
}

Hand::Hand(CARD firstCard) {
	first->card = firstCard;
	first->next = NULL;
	first->prev = NULL;
	handSize = 1;
}

Hand::Hand(CardNode firstCard)
{
	*first = firstCard;
	handSize = 0;
	while (first->next != nullptr) {
		handSize++;
	}
}

Hand::~Hand() //Delete the linked list
{
	CardNode *head, *tail;
	tail = first;
	head = tail->next;
	do {
		delete tail;
		tail = head;
		head = tail->next;
	} while (head != NULL);
}

void Hand::sortHand() //Sort hand from lowest to highest
{
	int swapped, i;
	CardNode *ptr1;
	CardNode *lptr = NULL;
	CARD temp;

	if (first == NULL) {
		return;
	}
	do {
		swapped = 0;
		ptr1 = first;

		while (ptr1->next != lptr) {
			if (ptr1->card.id > ptr1->next->card.id) {
				temp = ptr1->card;
				ptr1->card = ptr1->next->card;
				ptr1->next->card = temp;
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}

void Hand::addCard(CARD newCard)
{
	CardNode *newCardNode = new CardNode;
	newCardNode->card = newCard;
	newCardNode->prev = NULL;
	newCardNode->next = first;

	if (first != nullptr) {
		first->prev = newCardNode;
	}
	first = newCardNode;

	handSize++;
}

//Taverse the linked list to remove a node
void Hand::removeCard(int index)
{
	CardNode *current = first;
	//Get to the right node
	for (int i = 0; i < index; i++) {
		if (current->next != nullptr) {
			current = current->next;
		}
		else {
			return;
		}
	}
	//Patch the links then delete the node
	current->prev->next = current->next;
	current->next->prev = current->prev;
	delete current;
}

//Traverse the linked list and replace the desired card/node
void Hand::replaceCard(CARD newCard, int index) 
{
	CardNode *current = first;
	for (int i = 0; i < index; i++) {
		if (current->next != nullptr) {
			current = current->next;
		}
		else {
			addCard(newCard);
			return;
		}
	}
	current->card = newCard;
}

CARD Hand::getCard(int index)
{
	CardNode *current = first;
	CARD returnCard;
	for (int i = 0; i < index; i++) {
		if (current->next != nullptr) {
			current = current->next;
		}
		else {
			returnCard.id = 0;
			return returnCard;
		}
	}
	returnCard = current->card;

	return returnCard;
}

/*
Algorithm to find best hand (Designed by Joey White)
1. Check for Royal Flush, see if there's the same suit and top 5 cards, if yes, return Royal Flush, if there's no flush, go to step 3
2. If there is a flush but not the top 5 cards, see if there's a straight, if yes, then return Straight Flush, else go to next step and save the flush and straight in bools
3. If there's a 4 of a kind, return that
4. If there's a 3 of a kind and a pair, return full house. Else, save whether there's a 3 of a kind
5. If there was a flush, return flush
6. If there's a straight, return straight, but might be able to skip depending on bool
7. If there was a 3 of a kind, return that
8. If there's 2 pairs, return 2 pair, if there's only 1, return pair
9. If nothing has returned yet, then there is only a high card
*/

hands Hand::bestHand()
{
	CardNode *current = first;
	CARD currentCard;

	sortHand(); //Make things like straights easier to find
	vector<CARD> hand;//Vector is quciker to deal with than a linked list and can be dynamic
	

	int top5[] = { 1, 13, 12, 11, 10}; //The top 5 cards of the deck
	bool suited, sequenced, threeKind, twoPair, pair, royal;

	//Populating array with hand
	for (int i = 0; i < handSize; i++) {
		hand.push_back(current->card);
		if (i != handSize) {
			current = current->next;
		}
	}

	//Determine best play from hand

	//Check for Royal Flush and Straight Flush
	suited = true;
	royal = true;
	sequenced = true;
	for (int i = 0; i < handSize; i++) {
		//If a suit doesn't match, there's no flush
		if (i != handSize - 1 && suited) {
			if (hand[i].suit != hand[i + 1].suit) {
				suited = false;
			}
		}
		//Check if royal number
		if (royal) { //If there's already been determined a non-royal number, don't go changing it again
			for (int j = 0; j < 5; j++) {
				if (hand[i].num == top5[j]) {
					royal = true;
					break; //Only breaks the top5 array loop
				}
				royal = false;
			}
		}
		//Check for straight
		if (i != handSize - 1 && sequenced) {
			if (hand[i].id != hand[i + 1].id - 1) {
				sequenced = false;
			}
		}
	}
	if (suited) {
		if (royal) {
			//delete hand;
			return RF;
		}
		if (sequenced) {
			//delete hand;
			return SF;
		}
	}

	//Check for n of a kind
	int ranks = 1; //duplicate numbers, always 1 of itself
	int firstPair = 0;
	threeKind = false;
	twoPair = false;
	pair = false;
	//Check each card to one another, if there's duplicate numbers, increment ranks
	for (int i = 0; i < handSize; i++) {
		for (int j = 0; j < handSize; j++) {
			if (i != j) { // Don't need to check to see if a card is the same as itself
				if (hand[i].num == hand[j].num) {
					ranks++;
				}
			}
		}
		switch (ranks)
		{
		case 4:
			//delete hand;
			return FoK;
			break;
		case 3:
			threeKind = true;
			break;
		case 2:

			if (pair && hand[i].num != firstPair) {
				twoPair = true;
			}
			else {
				pair = true;
				firstPair = hand[i].num;
			}
			break;
		default:
			break;
		}
		ranks = 1;
	}
	//Full House
	if (threeKind && pair) {
		//delete hand;
		return FH;
	}
	//Flush
	if (suited) {
		//delete hand;
		return F;
	}
	//Straight
	if (sequenced) {
		//delete hand;
		return S;
	}
	//Three of a Kind
	if (threeKind) {
		//delete hand;
		return ToK;
	}
	//Two Pair
	if (twoPair) {
		//delete hand;
		return TP;
	}
	//Pair
	if (pair) {
		//delete hand;
		return P;
	}
	//High Card/Junk
	//delete hand;
	return HC;

}

CARD Hand::highCard()
{
	CARD outCard;
	CardNode *current = first;
	outCard = first->card;
	for (int i = 0; i < handSize; i++) {
		if (current->card.num > outCard.num) {
			outCard = current->card;
		}
	}

	return outCard;
}
