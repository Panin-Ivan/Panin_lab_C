#include "Buyer.h"

void Buyer::InBuyer() {
    std::string string;
    puts("������� ��� ����������");
    stringin(NAMELEN, &string, "��� ����������");
    SetName(string);

    printf("������� ����� �������� ����������(�� %d ��������): ", PHONELEN - 2);
    int x = 0; std::string num;
    do {
        if (x) printf("������� �����: ");
        stringin(PHONELEN, &string, "����� ��������");
        x = 1;
    } while (string.size() != 11);
    SetPhone(string);
    buyers_cntr++;
}
int Buyer::buyers_cntr = 0;