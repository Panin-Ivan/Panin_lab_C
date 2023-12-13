#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define NAMELEN 30
#define PHONELEN 13

#pragma once
class Human {
public:
    Human() {
        strcpy((this)->name, "name");
        strcpy((this)->phone, "80000000000");
    }
    Human(char* name) {
        strcpy((this)->name, name);
        strcpy((this)->phone, "80000000000");
    }
    Human(char* name, char* phone) {
        strcpy((this)->name, name);
        strcpy((this)->phone, phone);
    }
    char* GetName() {
        return this->name;
    }
    char* GetPhone() {
        return this->phone;
    }
    void SetName(char* new_name) {
        strcpy(this->name, new_name);
    }
    void SetPhone(char* new_phone) {
        strcpy(this->phone, new_phone);
    }
private:
    char name[NAMELEN];     //Имя
    char phone[PHONELEN];   //Телефон
};

