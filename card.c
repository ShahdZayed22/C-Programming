#include <stdio.h>
#include <string.h>
#include "card.h"

void getCardHolderName(CardData* card) {
    printf("Enter card holder name: ");
    fgets(card->cardHolderName, sizeof(card->cardHolderName), stdin);
    card->cardHolderName[strcspn(card->cardHolderName, "\n")] = '\0';
}

void getCardExpiryDate(CardData* card) {
    printf("Enter card expiry date (MM/YY): ");
    fgets(card->cardExpirationDate, sizeof(card->cardExpirationDate), stdin);
    card->cardExpirationDate[strcspn(card->cardExpirationDate, "\n")] = '\0';
}

void getCardPAN(CardData* card) {
    do {
        printf("Enter card PAN: ");
        fgets(card->primaryAccountNumber, sizeof(card->primaryAccountNumber), stdin);
        card->primaryAccountNumber[strcspn(card->primaryAccountNumber, "\n")] = '\0';
    } while (strlen(card->primaryAccountNumber) == 0);
}
