#include "Producer.h"
void Producer::InProducer() {
    std::string string;
    puts("������� ��� �������������");
    stringin(NAMELEN, string, "��� �������������");
    SetName(string);

    printf("������� ����� �������� �������������(�� %d ��������): ", PHONELEN - 2);
    int x = 0; std::string num;
    do {
        if (x) printf("������� �����: ");
        stringin(PHONELEN, string, "����� ��������");
        sprintf(num, "%lld", atoll(string));
        x = 1;
    } while (strlen(num) != 11);
    SetPhone(string);
    producer_cntr++;
}
int Producer::producer_cntr = 0;