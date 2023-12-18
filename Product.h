#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#pragma once
#include "Input.h"
#include "Producer.h"
class Product : public Producer
{
public:
    Product() {
        name_product = "product_name";
        price = 0;
        quantity = 0;
    }
    void SetNameProduct(std::string name) {
        name_product = name;
    }
    void SetPrice(int price) {
        this->price = price;
    }
    void SetQuantityProduct(int quantity) {
        this->quantity = quantity;
    }
    std::string GetNameProduct() {
        return name_product;
    }
    int GetPrice() {
        return price;
    }
    int GetQuantityProduct() {
        return quantity;
    }
    void OutProduct() {
        cout << "Название:" << GetNameProduct() << "  Цена:" << GetPrice() << "  Кол-во:" << GetQuantityProduct() << "  Производитель:" << GetName() << "  Телефон пр-ля:" << GetPhone() << endl;
    }
    void InProduct(Producer* producers);
    void SetProduct(Product product);
    static void SetProducts_cntr(int n) { products_cntr = n; }
    static int GetProducts_cntr() { return products_cntr; }
    Product GetProduct() { return *this; }
    Product operator ++(int) { quantity++; return *this; }     //постфиксный
    Product& operator ++() { price++; return *this; }          //префиксный
private:
    std::string name_product;     //Наименование товара
    int price;              //Цена товара
    int quantity;           //кол-во товара на складе
    static int products_cntr;
};

