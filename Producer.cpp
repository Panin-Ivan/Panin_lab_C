#include "Producer.h"
void Producer::InProducer() {
   char string[50];
    puts("Введите имя производителя");
    stringin(NAMELEN, string, "имя производителя");
    SetName(string);

    printf("Введите номер телефона производителя(до %d символов): ", PHONELEN - 2);
    int x = 0; char num[PHONELEN];
    do {
        if (x) printf("Введите номер: ");
        stringin(PHONELEN, string, "номер телефона");
        sprintf(num, "%lld", atoll(string));
        x = 1;
    } while (strlen(num) != 11);
    SetPhone(string);
    producer_cntr++;
}
int Producer::producer_cntr = 0;