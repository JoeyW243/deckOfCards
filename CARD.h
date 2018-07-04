#ifndef CARD_H
#define CARD_H

enum suitType { SPADES, HEARTS, CLUBS, DIAMONDS };

struct CARD {
	int num = 0;
	suitType suit;
};

#endif // !CARD_H

