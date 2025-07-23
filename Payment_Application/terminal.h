#ifndef TERMINAL_H
#define TERMINAL_H

typedef struct {
    float transAmount;
    char transactionDate[11];
} TerminalData;

int is_card_expired(const char *expDate, const char *transDate);

#endif
