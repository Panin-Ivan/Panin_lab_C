#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include <windows.h>
#define NAMELEN 30
#define PHONELEN 13
#define DATELEN 12
#define MAXCH 200

#include "Seller.h"
#include "Producer.h"
#include "Buyer.h"
#include "Product.h"
#include "Order.h"
#include "Input.h"
#include <string.h>

//ф-я вывода производителя                 
void class_out(Producer* producers) {
    for (int i = 0; i < producers->GetProducer_cntr(); i++) {
        printf("%-2d|", i + 1);
        (producers + i)->OutProducer();
    }
}
//ф-я вывода продавца
void class_out(Seller* sellers, int cntr) {
    for (int i = 0; i < cntr; i++) {
        printf("%-2d|", i + 1);
        (sellers + i)->OutSeller();
    }
}
//ф-я вывода покупателя
void class_out(Buyer* buyers) {
    for (int i = 0; i < buyers->GetBuyer_cntr(); i++) {
        printf("%-2d|", i + 1);
        (buyers + i)->OutBuyer();
    }
}
//ф-я вывода товара
void class_out(Product* products) {
    for (int i = 0; i < products->GetProducts_cntr(); i++) {
        printf("%-2d|", i + 1); 
        (products+i)->OutProduct();
    }
}
//ф-я вывода заказа
void class_out(Order* orders) {
    if (orders->GetOrders_cntr()) {
        puts("Заказы");
        for (int i = 0; i < orders->GetOrders_cntr(); i++) {
            printf("%-2d|", i + 1);
            (orders + i)->OutOrder();
        }

        int select;
        do {
            puts("Вывести дополнительную информацию о заказе?\n1.Да\n2.Нет");
            intin(&select, 1, 2, "номер варианта");
            if (select == 1) {
                puts("Введите номер варианта, для которого небходимо вывести всю информацию");
                int i; intin(&i, 1, orders->GetOrders_cntr(), "номер варианта");
                i = i - 1;

                puts("Товар данного заказа");
                (orders + i)->OutProduct();

                puts("Покупатель данного заказа");
                (orders + i)->OutBuyer();

                puts("Продавец данного заказа");
                (orders + i)->OutSeller();
            }
        } while (select != 2);
    }
    else puts("Заказов нет");
}                                           

void Product::InProduct(Producer* producers) {
    std::string s = "";
    std::string* str = &s ; int num;
    puts("Введите наименование товара");
    stringin(NAMELEN, str, "наименование товара");
    SetNameProduct(*str);

    puts("Введите цену");
    intin(&num, 0, 1000000, "цену");
    SetPrice(num);

    puts("Введите кол-во товара");
    intin(&num, 0, 1000000, "кол-во товара");
    SetQuantity(num);

    int select;
    class_out(producers);
    puts("Введите номер производителя");
    intin(&select, 1, producers->GetProducer_cntr(), "номер производителя");
    this->producer.SetName((producers + select - 1)->GetName());
    this->producer.SetPhone((producers + select - 1)->GetPhone());
    products_cntr++;
}

void Order::InOrder(Order* orders, Product* products, Buyer* buyers, Seller* sellers, int sellers_cntr) {
    std::string s = "";
    std::string* str = &s; int num;

    id = orders_cntr + 1;

    puts("Введите дату заказа");
    int year, month, day;
    printf("Введите год: "); intin(&year, 1900, 3000, "год рождения");
    printf("Введите месяц: "); intin(&month, 1, 12, "месяц рождения");
    printf("Введите день: "); intin(&day, 1, 31, "день рождения");
    *str = std::to_string(day) + "." + to_string(month) +"."+ to_string(year);
    SetDate(*str);

    int select;
    class_out(products);
    puts("Введите номер товара");
    intin(&select, 1, GetProducts_cntr(), "номер товара");
    SetProduct(*(products + select - 1));

    puts("Введите кол-во покумаемого товара товара");
    intin(&num, 1, (products + select - 1)->GetQuantity(), "кол-во товара");
    SetQuantity(num);

    class_out(buyers);
    puts("Введите номер покупателя");
    intin(&select, 1, buyers->GetBuyer_cntr(), "номер покупателя");
    SetBuyer(*(buyers + select - 1));

    class_out(sellers, sellers_cntr);
    puts("Введите номер продавца");
    intin(&select, 1, sellers_cntr, "номер продавца");
    SetSeller(*(sellers + select - 1));

    SetStatus(false);
    orders_cntr++;
}

//ф-я ввода производителя
void producer_add(Producer* producers) {
    if (producers->GetProducer_cntr() >= 10)
        printf("Достигнут лимит производителей\n");
    else {
        Producer producer;
        producer.InProducer();

        (producers + producers->GetProducer_cntr()-1)->SetProducer(producer);
    }
}
//ф-я ввода продавца
void seller_add(Seller* sellers, int* sellers_cntr) {
    if (*sellers_cntr >= 10)
        printf("Достигнут лимит продавцов\n");
    else {
        Seller seller;
        seller.InSeller();
        
        *sellers_cntr = *sellers_cntr + 1;
        (sellers + *(sellers_cntr)-1)->SetSeller(seller);
    }
}
//ф-я ввода покупателя
void buyer_add(Buyer *buyers) {
    if (buyers->GetBuyer_cntr() >= 10)
        printf("Достигнут лимит покупателей\n");
    else {
        Buyer buyer;
        buyer.InBuyer();

        (buyers + buyers->GetBuyer_cntr() - 1)->SetBuyer(buyer);
    }
}
//ф-я ввода товара
int product_add(Product* products, Producer* producers) {
    if (products->GetProducts_cntr() >= 10) {
        printf("Достигнут лимит товаров\n");
        return 1;
    }
    if (producers->GetProducer_cntr() == 0) {
        printf("Нет ни одного производителя\n");
        return 2;
    }
    Product product;
    product.InProduct(producers);

    (products + products->GetProducts_cntr()-1)->SetProduct(product);
    return 0;
}
//ф-я ввода заказа
int order_add(Order* orders, Product* products, Buyer* buyers, Seller* sellers, int sellers_cntr) {
    if (orders->GetOrders_cntr() >= 10) {
        printf("Достигнут лимит заказов\n");
        return 1;
    }
    if (products->GetProducts_cntr() == 0) {
        printf("Нет ни одного товара\n");
        return 2;
    }
    if (buyers->GetBuyer_cntr() == 0) {
        printf("Нет ни одного покупателя\n");
        return 3;
    }
    if (sellers_cntr == 0) {
        printf("Нет ни одного продавца\n");
        return 4;
    }
    Order order;
    order.InOrder(orders, products, buyers, sellers, sellers_cntr);

    (orders + orders->GetOrders_cntr()-1)->SetOrder(order);
    return 0;
}
//выполнение заказа
int order_complete(Order* orders, Product* products, Order **orders_complete, int* orders_complete_cntr) {
    if (orders->GetOrders_cntr() == 0) { puts("Нет заказов"); return 1; }
    bool st = true;
    for (int i = 0; i < orders->GetOrders_cntr(); i++)
        if ((orders + i)->GetStatus() == false)
            st = false;
    if (st) {
        puts("Все заказы выполнены");
        return 2;
    }

    class_out(orders);

    int num = 0;
    do {
        if (num)puts("Заказ уже выполнен");
        puts("Введите номер заказа для выполнения");
        intin(&num, 1, orders->GetOrders_cntr(), "номер заказа");
    } while ((orders + num - 1)->GetStatus() == true);

    if ((orders + num - 1)->GetQuantity() > (orders + num - 1)->Product::GetQuantity()) {
        puts("Недостаточно товара на складе");
    }
    else {
        (orders + num - 1)->SetStatus(true);

        (orders + num - 1)->Product::SetQuantity((orders + num - 1)->Product::GetQuantity() - (orders + num - 1)->GetQuantity());
        for (int i = 0; i < products->GetProducts_cntr(); i++) {
            if ((products + i)->GetNameProduct() == (orders + num - 1)->GetNameProduct())
                (products + i)->SetQuantity((orders + num - 1)->Product::GetQuantity());
        }

        for (int i = 0; i < orders->GetOrders_cntr(); i++) {
            if ((orders + i)->GetNameProduct() == (orders + num - 1)->GetNameProduct())
                (orders + i)->Product::SetQuantity((orders + num - 1)->Product::GetQuantity());
        }
        
        Order* order_old = new Order[*orders_complete_cntr];
        for (int i = 0; i < *orders_complete_cntr; i++)
            (order_old + i)->SetOrder(*(*(orders_complete) + i));

        *orders_complete_cntr = *orders_complete_cntr + 1;
        *orders_complete = new Order[*orders_complete_cntr];
        if (*orders_complete_cntr > 1) {
            **orders_complete = *order_old;
        }

        *(*(orders_complete)+ *(orders_complete_cntr) - 1) = *(orders + num - 1);

        delete[] order_old;
    }
    return 0;
}

void seller_fire(Seller* sellers, int *sellers_cntr, Seller **sellers_dismissed, int* sellers_dismissed_cntr) {
    if (*sellers_cntr) {
        class_out(sellers, *sellers_cntr);
        int num;
        puts("Введите номер продавца");
        intin(&num, 1, *sellers_cntr, "номер продавца");

        Seller *sellers_old = new Seller[*sellers_cntr];
        for(int i = 0; i< *sellers_cntr;i++)
            (sellers_old+i)->SetSeller(*(sellers+i));

        Seller *sellers_dismissed_old = new Seller[*sellers_dismissed_cntr];
        for (int i=0; i<*sellers_dismissed_cntr ;i++)
            (sellers_dismissed_old+i)->SetSeller(*(*(sellers_dismissed) + i));

        *sellers_dismissed_cntr = *sellers_dismissed_cntr + 1;
        *sellers_dismissed = new Seller[*sellers_dismissed_cntr];
        if (*sellers_dismissed_cntr >1) {
            **sellers_dismissed = *sellers_dismissed_old;
        }
        *(*(sellers_dismissed) + *(sellers_dismissed_cntr) - 1) = *(sellers + num - 1);

        for (int i = 0; i < num-1; i++)
            *(sellers + i) = *(sellers_old + i);
        for (int i = num; i < *sellers_cntr; i++)
            *(sellers + i-1) = *(sellers_old + i);

        delete[] sellers_old;
        *sellers_cntr = *sellers_cntr - 1;;
    }
    else puts("Нет продавцов");
}

//основная программа-меню, вызывающая различные функции
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int selection, exit = 1;
    puts("Программа «Заказы»\n");

    Producer producers[10];
    Seller sellers[10]; int sellers_cntr = 0;
    Buyer buyers[2][5];
    Product products[10]; Product prod;
    Order orders[10];
    Order* orders_complete = { new Order }; int orders_complete_cntr = 0;
    Seller* sellers_dismissed = { new Seller }; int sellers_dismissed_cntr = 0;
    

    do {
        puts("1.Добавление\n2.Вывод\n3.Сумма заказа\n4.Выполнить заказ\n5.Уволить продавца\n6.Скидка\n7.Средняя зарплата продавцов\n8.Кол-во товара\n9.Выход");
        printf("Выберете дальнейшее действие: ");
        intin(&selection, 1, 9, "вариант пункта меню");

        int exit1 = 1, salary_avg = 0;
        switch (selection)
        {
        case 1:
            do {
                puts("1.Добавление производителя \n2.Добавление продавца\n3.Добавление покупателя\n4.Добавление товара\n5.Добавление заказа\n6.Выход к прошлому меню");
                printf("Выберете дальнейшее действие: ");
                intin(&selection, 1, 6, "вариант пункта меню");
                switch (selection) {
                case 1: producer_add(producers); break;
                case 2: seller_add(sellers, &sellers_cntr); break;
                case 3: buyer_add(&buyers[0][0]); break;
                case 4: product_add(products, producers); break;
                case 5: order_add(orders, products, &buyers[0][0], sellers, sellers_cntr); break;
                case 6: exit1 = 0; break;
                }
            } while (exit1);
            break;
        case 2:
            do {
                puts("1.Вывод производителя \n2.Вывод продавца\n3.Вывод покупателя\n4.Вывод товара\n5.Вывод заказа\n6.Вывод выполненных заказов\n7.Вывод уволенных продавцов\n8.Выход к прошлому меню");
                printf("Выберите дальнейшее действие: ");
                intin(&selection, 1, 8, "вариант пункта меню");
                switch (selection) {
                case 1: class_out(producers); break;
                case 2: class_out(sellers, sellers_cntr); break;
                case 3: class_out(&buyers[0][0]); break;
                case 4: class_out(products); break;
                case 5: class_out(orders); break;
                case 6: //вывод выполненных заказов
                    if (orders_complete_cntr) {
                        puts("Заказы");
                        for (int i = 0; i < orders_complete_cntr; i++) {
                            printf("%-2d|", i + 1);
                            (orders_complete + i)->OutOrder();
                        }

                        do {
                            puts("Вывести дополнительную информацию о заказе?\n1.Да\n2.Нет");
                            intin(&selection, 1, 2, "номер варианта");
                            if (selection == 1) {
                                puts("Введите номер варианта, для которого небходимо вывести всю информацию");
                                int i; intin(&i, 1, orders_complete_cntr, "номер варианта");
                                i = i - 1;

                                puts("Товар данного заказа");
                                (orders_complete + i)->OutProduct();

                                puts("Покупатель данного заказа");
                                (orders_complete + i)->OutBuyer();

                                puts("Продавец данного заказа");
                                (orders_complete + i)->OutSeller();
                            }
                        } while (selection != 2);
                    }
                    else puts("Заказов нет");
                    break;
                case 7:           //вывод уволенных продавцов          
                    for (int i = 0; i < sellers_dismissed_cntr; i++) {
                        printf("%-2d|", i + 1);
                        (sellers_dismissed + i)->OutSeller();
                    }; break;
                case 8: exit1 = 0; break;
                }
            } while (exit1);
            break;
        case 3: class_out(orders);          //сумма заказа
            int num;
            puts("Введите номер заказа для подсчета суммы");
            intin(&num, 1, orders->GetOrders_cntr(), "номер заказа");

            (orders + num - 1)->Sum(); break;
        case 4: order_complete(orders, products, &orders_complete, &orders_complete_cntr); break;
        case 5: seller_fire(sellers, &sellers_cntr, &sellers_dismissed, &sellers_dismissed_cntr); break;
        case 6: class_out(orders);
            if (orders->GetOrders_cntr()) {
                puts("Введите номер заказа");
                intin(&selection, 1, orders->GetOrders_cntr(), "номер заказа");
                puts("Введите скидку");
                int per;
                intin(&per, 0, 100, "скидку");
                cout << "Цена товара со скидкой " << per << "% :" << Sale(&orders[selection - 1], per) << endl;
            }
            else cout << "Нет заказов" << endl;
            break;
        case 7://средняя зп
            for (int i = 0; i < sellers_cntr; i++) {
                salary_avg = salary_avg + sellers[i].GetSalary();
            }
            try {
                if (!sellers_cntr) throw 1;
                salary_avg = salary_avg / sellers_cntr;
                cout << "Средняя зарплата: " << salary_avg << endl;
            }
            catch (int) { cout << "Нет продавцов" << endl; }
            break;
        case 8:
            for (int i = 0; i < products->GetProducts_cntr(); i++) {
                prod = prod + products[i];
            }
            printf("Кол-во товара:%d\n", prod.GetQuantity());
            break;
        case 9: exit = 0; break;
        }
    } while (exit);
}