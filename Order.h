#define _CRT_SECURE_NO_WARNINGS
#define DATELEN 12
#include <stdio.h>
#include <conio.h>
#include <string.h>
#pragma once
#include "Input.h"
#include "Seller.h"
#include "Buyer.h"
#include "Product.h"

class Order : public Product, protected Buyer, public Seller {
    friend int Sale(Order* order, int percent) {		//Скидка на заказ
        return (int)((double)(order->GetPrice()) * ((100.0 - (double)percent) / 100.0));
    }
public:
    Order() {
        id = 0;
        date = "10.10.2023";
        quantity = 0;
        status = false;
    }
    void SetId(int id) {
        this->id = id;
    }
    void SetDate(std::string date) {
        this->date = date;
    }
    void SetQuantity(int quantity) {
        this->quantity = quantity;
    }
    void SetStatus(bool status) {
        this->status = status;
    }
    int GetId() {
        return id;
    }
    std::string GetDate() {
        return date;
    }
    int GetQuantity() {
        return quantity;
    }
    bool GetStatus() {
        return status;
    }
    void OutOrder() {
        cout << "id:" << id << "  Дата:" << date << "  Кол-во:" << quantity << "  Статус:" << status <<endl;
    }
    void OutBuyer();
    void InOrder(Order* orders, Product* products, Buyer* buyers, Seller* sellers, int sellers_cntr);
    void SetOrder(Order order);
    void Sum() {
        int sum;
        sum = quantity * this->GetPrice();
        printf("Сумма заказа id%d: %d\n", id, sum);
    }
    static int GetOrders_cntr() { return orders_cntr; }
    static void SetOrders_cntr(int n) { orders_cntr = n; }
    Order operator= (Product product) { this->SetProduct(product); return *this; }
    Order operator= (Buyer buyer) { this->SetBuyer(buyer);  return *this; }
    Order operator= (Seller seller) { this->SetSeller(seller);  return *this; }
private:
    int id;                 //номер заказа
    std::string date;     //дата заказа
    int quantity;           //кол-во товара
    bool status;            //статус заказа
    static int orders_cntr;
};