#include <stdlib.h>
#include <string.h>
#include "terminal.h"

int is_card_expired(const char *expDate, const char *transDate) {
    char exp[6], trans[11];
    strcpy(exp, expDate);
    strcpy(trans, transDate);

    int expMonth = atoi(strtok(exp, "/"));
    int expYear = atoi(strtok(NULL, "/")) + 2000;

    int transDay = atoi(strtok(trans, "/"));
    int transMonth = atoi(strtok(NULL, "/"));
    int transYear = atoi(strtok(NULL, "/"));

    if (transYear > expYear || (transYear == expYear && transMonth > expMonth))
        return 1;
    return 0;
}
