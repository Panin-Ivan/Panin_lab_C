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
        strcpy(name_product, "product_name");
        price = 0;
        quantity = 0;
    }
    void SetNameProduct(char* name) {
        strcpy(this->name_product, name);
    }
    void SetPrice(int price) {
        this->price = price;
    }
    void SetQuantityProduct(int quantity) {
        this->quantity = quantity;
    }
    char* GetNameProduct() {
        return name_product;
    }
    int GetPrice() {
        return price;
    }
    int GetQuantityProduct() {
        return quantity;
    }
    void OutProduct() {
        printf("%-30s|%-10d|%-13d|%-30s|%-21s\n", this->GetNameProduct(), this->GetPrice(), this->GetQuantityProduct(), this->GetName(), this->GetPhone());
    }
    void InProduct(Producer* producers);
    void SetProduct(Product product);
    static void SetProducts_cntr(int n) { products_cntr = n; }
    static int GetProducts_cntr() { return products_cntr; }
    Product GetProduct() { return *this; }
private:
    char name_product[NAMELEN];     //������������ ������
    int price;              //���� ������
    int quantity;           //���-�� ������ �� ������
    static int products_cntr;
};
