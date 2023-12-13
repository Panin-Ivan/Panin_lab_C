#include "Seller.h"
    Seller::Seller() {
        salary = 0;
    }
    Seller::Seller(std::string name) {
        SetName(name);
        salary = 0;
        sellers_cntr++;
    }
    Seller::Seller(std::string name, std::string phone) {
        SetName(name);
        SetName(phone);
        salary = 0;
        sellers_cntr++;
    }
    void Seller::SetSeller(Seller seller) {
        SetName(seller.GetName());
        SetPhone(seller.GetPhone());
        salary = seller.GetSalary();
    }
    void Seller::InSeller(){
        std::string string;
        puts("������� ��� ��������");
        stringin(NAMELEN, string, "��� ��������");
        SetName(string);

        printf("������� ����� �������� ��������(�� %d ��������): ", PHONELEN - 2);
        int x = 0; std::string num;
        do {
            if (x) printf("������� �����: ");
            stringin(PHONELEN, string, "����� ��������");
            sprintf(num, "%lld", atoll(string));
            x = 1;
        } while (strlen(num) != 11);
        SetPhone(string);

        int salary;
        puts("������� �������� ��������");
        intin(&salary, 0, 1000000, "�������� ��������");
        SetSalary(salary);
        sellers_cntr++;
    }
    int Seller::sellers_cntr = 0;