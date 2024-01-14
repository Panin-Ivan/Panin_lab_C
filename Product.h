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
        id = 0;
    }
    void SetNameProduct(std::string name) {
        name_product = name;
    }
    void SetPrice(int price) {
        this->price = price;
    }
    void SetQuantity(int quantity) {
        this->quantity = quantity;
    }
    std::string GetNameProduct() {
        return name_product;
    }
    int GetPrice() {
        return price;
    }
    int GetQuantity() {
        return quantity;
    }
    int GetId() { return id; }
    friend ostream& operator<<(ostream& out, Product product) {
        return out << "��������:" << product.GetNameProduct() << "  ����:" << product.GetPrice() << "  ���-��:" << product.GetQuantity() << "  �������������:" << product.producer.GetName() << "  ������� ��-��:" << product.producer.GetPhone() << endl;
    }
    void InProduct(Producer* producers);
    void SetProduct(Product product);
    static void SetProducts_cntr(int n) { products_cntr = n; }
    static int GetProducts_cntr() { return products_cntr; }
    Product GetProduct() { return *this; }
    Product operator + (Product product) {
        Product prod; prod.SetProduct(*this);
        prod.SetQuantity((this->GetQuantity() + product.GetQuantity()));
        return prod;
    }
    Product operator ++(int) { return *this; quantity++;}       //�����������
    Product& operator ++() { quantity++; return *this; }        //����������
    virtual void Waste(int quantity) { this->quantity = this->quantity - quantity; }
private:
    Producer producer;
    std::string name_product;     //������������ ������
    int price;              //���� ������
    int quantity;           //���-�� ������ �� ������
    static int products_cntr;
    int id;
};

