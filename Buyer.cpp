#include "Buyer.h"

void Buyer::InBuyer() {
    char string[50];
    puts("Введите имя покупателя");
    stringin(NAMELEN, string, "имя покупателя");
    SetName(string);

    printf("Введите номер телефона покупателя(до %d символов): ", PHONELEN - 2);
    int x = 0; char num[PHONELEN];
    do {
        if (x) printf("Введите номер: ");
        stringin(PHONELEN, string, "номер телефона");
        sprintf(num, "%lld", atoll(string));
        x = 1;
    } while (strlen(num) != 11);
    SetPhone(string);
    buyers_cntr++;
}
int Buyer::buyers_cntr = 0;