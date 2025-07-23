#ifndef CARD_H
#define CARD_H

typedef struct {
    char cardHolderName[100];
    char cardExpirationDate[6];
    char primaryAccountNumber[20];
} CardData;

void getCardHolderName(CardData* card);
void getCardExpiryDate(CardData* card);
void getCardPAN(CardData* card);

#endif
