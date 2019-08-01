#include "CARD.h"
#include <ctime>
#include <cstdlib>

using namespace std;


CARD *sortHand(CARD *unsortedHand, int size) {
	CARD hand = *unsortedHand;

}

Hand::Hand()
{
	first.card.id = 0;
	first.next = NULL;
	first.prev = NULL;
}

Hand::Hand(CARD firstCard) {
	first.card = firstCard;
	first.next = NULL;
	first.prev = NULL;
}

Hand::Hand(CardNode firstCard)
{
	first = firstCard;
}
