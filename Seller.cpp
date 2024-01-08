#include "Seller.h"
    Seller::Seller() {
        salary = 0;
        seller_id = sellers_cntr;
    }
    Seller::Seller(std::string name) : Human(name) {
        salary = 0;
        seller_id = sellers_cntr;
    }
    Seller::Seller(std::string name, std::string phone) {
        SetName(name);
        SetName(phone);
        salary = 0;
        seller_id = sellers_cntr;
    }
    void Seller::SetSeller(Seller seller) {
        SetName(seller.GetName());
        SetPhone(seller.GetPhone());
        salary = seller.GetSalary();
        seller_id = seller.seller_id;
    }
    void Seller::InSeller(){
        std::string string;
        puts("������� ��� ��������");
        stringin(NAMELEN, &string, "��� ��������");
        SetName(string);

        printf("������� ����� �������� ��������(�� %d ��������): ", PHONELEN - 2);
        int x = 0; 
        do {
            if (x) printf("������� �����: ");
            stringin(PHONELEN, &string, "����� ��������");
            x = 1;
        } while (string.size() != 11);
        SetPhone(string);

        int salary;
        puts("������� �������� ��������");
        intin(&salary, 0, 1000000, "�������� ��������");
        SetSalary(salary);
        sellers_cntr++;
        seller_id = sellers_cntr;
    }
    int Seller::GetSellerId() { return seller_id; }
    int Seller::sellers_cntr = 0;