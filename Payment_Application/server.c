#include <string.h>
#include <ctype.h>
#include "server.h"

int is_valid_pan(const char *pan) {
    int len = strlen(pan);
    if (len != 16) return 0;
    for (int i = 0; i < len; i++) {
        if (!isdigit(pan[i])) return 0;
    }
    return 1;
}
