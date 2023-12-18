#include "Buyer.h"

void Buyer::InBuyer() {
    std::string string;
    puts("Введите имя покупателя");
    stringin(NAMELEN, &string, "имя покупателя");
    SetName(string);

    printf("Введите номер телефона покупателя(до %d символов): ", PHONELEN - 2);
    int x = 0; std::string num;
    do {
        if (x) printf("Введите номер: ");
        stringin(PHONELEN, &string, "номер телефона");
        x = 1;
    } while (string.size() != 11);
    SetPhone(string);
    buyers_cntr++;
}
int Buyer::buyers_cntr = 0;