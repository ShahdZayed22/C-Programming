#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "card.h"
#include "terminal.h"
#include "server.h"

int is_valid_date_format(const char *date) {
    if (strlen(date) < 7 || strlen(date) > 10) return 0;

    int day, month, year;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) return 0;
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 2000 || year > 2100)
        return 0;

    return 1;
}

int is_valid_amount(const char *input, float *amount) {
    char *end;
    *amount = strtof(input, &end);
    return (*end == '\0' || *end == '\n') && *amount > 0;
}

int main() {
    while (1) {
        CardData card;
        TerminalData termData;

        getCardHolderName(&card);
        getCardExpiryDate(&card);
        getCardPAN(&card);

        if (!is_valid_pan(card.primaryAccountNumber)) {
            printf("Invalid\n\n");
            continue;
        }

        printf("Enter transaction date (DD/MM/YYYY): ");
        fgets(termData.transactionDate, sizeof(termData.transactionDate), stdin);
        termData.transactionDate[strcspn(termData.transactionDate, "\n")] = '\0';

        if (!is_valid_date_format(termData.transactionDate)) {
            printf("Invalid\n\n");
            continue;
        }

        char amountInput[20];
        printf("Enter transaction amount: ");
        fgets(amountInput, sizeof(amountInput), stdin);
        amountInput[strcspn(amountInput, "\n")] = '\0';

        if (!is_valid_amount(amountInput, &termData.transAmount)) {
            printf("Invalid\n\n");
            continue;
        }

        if (termData.transAmount > 5000.0f) {
            printf("Declined: Exceeded Max Amount\n");
            break;
        }

        if (is_card_expired(card.cardExpirationDate, termData.transactionDate)) {
            printf("Declined: Expired Card\n");
            break;
        }

        printf("Approved: Transaction Saved\n");
        break;
    }

    return 0;
}
