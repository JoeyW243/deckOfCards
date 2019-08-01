#ifndef CARD_H
#define CARD_H

enum suitType { SPADES, HEARTS, CLUBS, DIAMONDS };
enum hands {RF, SF, FoK, FH, F, S, ToK, P, HC}; //Royal Flush, Straight Flush, 4 of a Kind, Full House, Flush, Staight, 3 of a Kind, Pair, High Card.

struct CARD {
	int id = 0;
	int num = 0;
	suitType suit;
	hands *plays; //Maybe delete pointer later? I dunno
};

struct CardNode {
	CARD card;
	CardNode *next;
	CardNode *prev;
};

class Hand
{
public:
	Hand();
	Hand(CARD firstCard);
	Hand(CardNode firstCard);

private:
	CardNode first;

};

CARD *sortHand(CARD *unsortedHand, int size);

/* * /
hands bestHand(CARD hand[], int size) {
	CARD currentCard;
	bool flag = true;
	for (int i = 0; i < size - 1; i++) {
		currentCard = hand[i];
		if (hand[i].suit != hand[i + 1].suit) {
			flag = false;
		}
	}
	if (flag = true) {

	}
}
*/
#endif // !CARD_H