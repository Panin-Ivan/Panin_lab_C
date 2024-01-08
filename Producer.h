#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#pragma once
#include "Input.h"
#include "Human.h"
class Producer : public Human
{
public:
    Producer() {}
    Producer(std::string name) {
        this->SetName(name);
        producer_cntr++;
    }
    Producer(std::string name, std::string phone) {
        this->SetName(name);
        this->SetPhone(phone);
        producer_cntr++;
    }
    void SetProducer(Producer producer) {
        this->SetName(producer.GetName());
        this->SetPhone(producer.GetPhone());
    }
    friend ostream& operator<<(ostream& out, Producer producer) {
        return out << "Имя:" << producer.GetName() << "  Телефон:" << producer.GetPhone() << endl;
    }
    void InProducer();
    static int GetProducer_cntr() { return producer_cntr; }
    static void SetProducer_cntr(int n) { producer_cntr = n; }
private:
    static int producer_cntr;
};

