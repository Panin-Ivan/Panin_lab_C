#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#pragma once
#include "Input.h"
#include "Producer.h"
class Product
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
        cout << "��������:" << GetNameProduct() << "  ����:" << GetPrice() << "  ���-��:" << GetQuantityProduct() << "  �������������:" << this->producer.GetName() << "  ������� ��-��:" << this->producer.GetPhone() << endl;
    }
    void InProduct(Producer* producers);
    void SetProduct(Product product);
    static void SetProducts_cntr(int n) { products_cntr = n; }
    static int GetProducts_cntr() { return products_cntr; }
    Product GetProduct() { return *this; }
    Product operator + (Product product) {
        Product prod; prod.SetProduct(*this);
        prod.SetQuantityProduct((this->GetQuantityProduct() + product.GetQuantityProduct()));
        return prod;
    }
    Product operator ++(int) { return *this; quantity++;}       //�����������
    Product& operator ++() { quantity++; return *this; }        //����������
private:
    Producer producer;
    std::string name_product;     //������������ ������
    int price;              //���� ������
    int quantity;           //���-�� ������ �� ������
    static int products_cntr;
};

