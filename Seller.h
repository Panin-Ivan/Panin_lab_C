#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "Input.h"
#include "Human.h"

class Seller : public Human
{
public:
    Seller();
    Seller(std::string name);
    Seller(std::string name, std::string phone);
    void SetSalary(int salary) {
        this->salary = salary;
    }
    int GetSalary() {
        return salary;
    }
    friend ostream& operator<<(ostream& out, Seller seller) {
        return out << "Имя:" << seller.GetName() << "  Телефон:" << seller.GetPhone() << "  Зарплата:" << seller.GetSalary() << "  id:" << seller.GetSellerId() << endl;
    }
    void SetSeller(Seller seller);
    void InSeller();
    Seller* GetSeller() { return this; }    //возвращение указателя на объект
    int GetSellerId();
private:
    int salary;             //Зарплата
    static int sellers_cntr;
    int seller_id;
};
