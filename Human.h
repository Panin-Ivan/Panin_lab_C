#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define NAMELEN 30
#define PHONELEN 13

#pragma once
class Human {
public:
    Human() {
        name="name";
        phone="80000000000";
    }
    Human(std::string name) {
        this->name= name;
        phone = "80000000000";
    }
    Human(std::string name, std::string phone) {
        this->name = name;
        this->phone = phone;
    }
    ~Human(){}
    std::string GetName() {
        return name;
    }
    std::string GetPhone() {
        return phone;
    }
    void SetName(std::string new_name) {
        name = new_name;
    }
    void SetPhone(std::string new_phone) {
        phone = new_phone;
    }
private:
    std::string name;       //Имя
    std::string phone;      //Телефон
};