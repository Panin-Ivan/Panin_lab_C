#include "Seller.h"
    Seller::Seller() {
        salary = 0;
    }
    Seller::Seller(char* name) {
        this->SetName(name);
        salary = 0;
        sellers_cntr++;
    }
    Seller::Seller(char* name, char* phone) {
        this->SetName(name);
        this->SetName(phone);
        salary = 0;
        sellers_cntr++;
    }
    void Seller::SetSeller(Seller seller) {
        SetName(seller.GetName());
        SetPhone(seller.GetPhone());
        salary = seller.GetSalary();
    }
    void Seller::InSeller(){
        char string[50];
        puts("Введите имя продавца");
        stringin(NAMELEN, string, "имя продавца");
        SetName(string);

        printf("Введите номер телефона продавца(до %d символов): ", PHONELEN - 2);
        int x = 0; char num[PHONELEN];
        do {
            if (x) printf("Введите номер: ");
            stringin(PHONELEN, string, "номер телефона");
            sprintf(num, "%lld", atoll(string));
            x = 1;
        } while (strlen(num) != 11);
        SetPhone(string);

        int salary;
        puts("Введите зарплату продавца");
        intin(&salary, 0, 1000000, "зарплату продавца");
        SetSalary(salary);
        sellers_cntr++;
    }
    int Seller::sellers_cntr = 0;