#include "CARD.h"
#include <ctime>
#include <cstdlib>

using namespace std;


Hand::Hand()
{
	first->card.id = 0;
	first->next = NULL;
	first->prev = NULL;
}

Hand::Hand(CARD firstCard) {
	first->card = firstCard;
	first->next = NULL;
	first->prev = NULL;
}

Hand::Hand(CardNode firstCard)
{
	*first = firstCard;
}

Hand::~Hand() //Delete the linked list
{

}

void Hand::sortHand()
{

}

void Hand::addCard(CARD newCard)
{
	CardNode *newCardNode = new CardNode;
	newCardNode->card = newCard;
	newCardNode->prev = NULL;
	newCardNode->next = first;

	first->prev = newCardNode;

}
