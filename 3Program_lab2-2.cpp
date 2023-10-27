#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale>
#include <windows.h>
#define NAMELEN 30
#define PHONELEN 13
#define DATELEN 12
#define MAXCH 200

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
    char* GetName(){
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

class Producer: public Human {
public:
    Producer() {}
    Producer(char* name) {
        this->SetName(name);
    }
    Producer(char* name, char* phone) {
        this->SetName(name);
        this->SetPhone(phone);
    }
    void OutProducer() {
        printf("%-30s|%s\n", this->GetName(), this->GetPhone());
    }
private:

};

class Seller : public Human {
public:
    Seller(){
        salary = 0;
    }
    Seller(char* name) {
        this->SetName(name);
        salary = 0;
    }
    Seller(char* name, char* phone) {
        this->SetName(name);
        this->SetName(phone);
        salary = 0;
    }
    void SetSalary(int salary) {
        this->salary = salary;
    }
    int GetSalary() {
        return salary;
    }
    void OutSeller() {
        printf("%-30s|%-14s|%-6d\n", this->GetName(), this->GetPhone(), this->GetSalary());
    }
    void SetSeller(Seller seller) {
        this->SetName(seller.GetName());
        this->SetPhone(seller.GetPhone());
        salary = seller.GetSalary();
    }
private:
    int salary;             //Зарплата
};

class Buyer : public Human {
public:
    Buyer() {}
    Buyer(char* name) {
        this->SetName(name);
    }
    Buyer(char* name, char* phone) {
        this->SetName(name);
        this->SetName(phone);
    }
    void SetBuyer(Buyer buyer) {
        this->SetName(buyer.GetName());
        this->SetPhone(buyer.GetPhone());
    }
    void OutBuyer() {
        printf("%-30s|%s\n", this->GetName(), this->GetPhone());
    }
private:

};

class Product : public Producer {
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
    void SetProduct(Product product) {
        this->SetName(product.GetName());
        this->SetPhone(product.GetPhone());
        this->SetNameProduct(product.GetNameProduct());
        this->SetPrice(product.GetPrice());
        this->SetQuantityProduct(product.GetQuantityProduct());
    }
private:
    char name_product[NAMELEN];     //Наименование товара
    int price;              //Цена товара
    int quantity;           //кол-во товара на складе
};

void intin(int* value, int lower_limit, int upper_limit, const char* message);
class Order: public Product, public Buyer, public Seller{
public:
    Order() {
        id = 0;
        strcpy(date, "10.10.2023");
        quantity = 0;
        status = false;
    }
    void SetId(int id) {
        this->id = id;
    }
    void SetDate(char* date) {
        strcpy(this->date, date);
    }
    void SetQuantityOrder(int quantity) {
        this->quantity = quantity;
    }
    void SetStatus(bool status) {
        this->status = status;
    }
    int GetId() {
        return id;
    }
    char* GetDate() {
        return date;
    }
    int GetQuantityOrder() {
        return quantity;
    }
    bool GetStatus() {
        return status;
    }
    void OutOrder() {
        printf("%-6d|%-10s|%-13d|%-d\n", id, date, quantity, status);
    }
    void Sum() {
        int sum;
        sum = quantity * this->GetPrice();
        printf("Сумма заказа id%d: %d\n", id, sum);
    }
private:
    int id;                 //номер заказа
    char date[DATELEN];     //дата заказа
    int quantity;           //кол-во товара
    bool status;            //статус заказа
};

//ф-я ввода строки
void stringin(int maxlength, char* string, const char* message) {
    do {				//maxlenght-максимальная длина строки, string-входная строка, message-сообщение при ошибке
        fgets(string, maxlength, stdin);
        if (strchr(string, '\n')) *strchr(string, '\n') = 0;
        if (strlen(string) <= 0 || strlen(string) > (maxlength - 2))
            printf("Ошибка. Введите %s(до %d символов): ", message, (maxlength - 2));
        rewind(stdin);
    } while (strlen(string) <= 0 || strlen(string) > (maxlength - 2));
}
//ф-я ввода числа
void intin(int* value, int lower_limit, int upper_limit, const char* message) {
    int i = 0;		//value-входное значение, lower_limit-нижний предел, upper_limit-верхний предел ,message-сообщение об ошибке
    do {
        if (i)printf("Ошибка. Введите %s(от %d до %d): ", message, lower_limit, upper_limit);
        while (scanf("%d", value) != 1) {
            while (getchar() != '\n');
            printf("Ошибка. Введите число: ");
        }
        i = 1;
        rewind(stdin);
    } while (*value<lower_limit || *value>upper_limit);
}
//ф-я вывода производителя                 
void class_out(Producer* producers, int producer_cntr) {
    printf("%-2s|%-30s|%s\n", "№", "Имя производителя", "Номер телефона");

    for (int i = 0; i < producer_cntr; i++) {
        printf("%-2d|", i + 1);
        (producers + i)->OutProducer();
    }
}
//ф-я вывода продавца
void class_out(Seller* sellers, int sellers_cntr) {
    printf("%-2s|%-30s|%-14s|%s\n", "№", "Имя продавца", "Номер телефона", "Зарплата");

    for (int i = 0; i < sellers_cntr; i++) {
        printf("%-2d|", i + 1);
        (sellers+i)->OutSeller();
    }
}
//ф-я вывода покупателя
void class_out(Buyer* buyers, int buyers_cntr) {
    printf("%-2s|%-30s|%s\n", "№", "Имя покупателя", "Номер телефона");

    for (int i = 0; i < buyers_cntr; i++) {
        printf("%-2d|", i + 1);
        (buyers + i)->OutBuyer();
    }
}
//ф-я вывода товара
void class_out(Product* products, int products_cntr) {
    printf("%-2s|%-30s|%-10s|%-13s|%-30s|%-21s\n", "№", "Название", "Цена", "Кол-во товара", "Имя производителя", "Телефон производителя");

    for (int i = 0; i < products_cntr; i++) {
        printf("%-2d|", i + 1); 
        (products+i)->OutProduct();
    }
}
//ф-я вывода заказа
void class_out(Order* orders, int orders_cntr) {
    if (orders_cntr) {
        puts("Заказы");
        printf("%-2s|%-6s|%-10s|%-13s|%-6s\n", "№", "id", "Дата", "Кол-во товара", "Статус");
        for (int i = 0; i < orders_cntr; i++) {
            printf("%-2d|", i + 1);
            (orders + i)->OutOrder();
        }

        int select;
        do {
            puts("Вывести дополнительную информацию о заказе?\n1.Да\n2.Нет");
            intin(&select, 1, 2, "номер варианта");
            if (select == 1) {
                puts("Введите номер варианта, для которого небходимо вывести всю информацию");
                int i; intin(&i, 1, orders_cntr, "номер варианта");
                i = i - 1;

                puts("Товар данного заказа");
                printf("%-30s|%-10s|%-13s|%-30s|%-21s\n", "Наименование товара", "Цена", "Кол-во товара", "Наименование производителя", "Телефон производителя");
                (orders + i)->OutProduct();

                puts("Покупатель данного заказа");
                printf("%-30s|%-18s\n", "Имя покупателя", "Телефон покупателя");
                (orders + i)->OutBuyer();

                puts("Продавец данного заказа");
                printf("%-30s|%-14s|%-s\n", "Имя продавца", "Телефон ", "Зарплата");
                (orders + i)->OutSeller();
            }
        } while (select != 2);
    }
    else puts("Заказов нет");
}                                           
//ф-я ввода производителя
void producer_add(Producer* producers, int* producer_cntr) {
    if (*producer_cntr >= 10)
        printf("Достигнут лимит производителей\n");
    else {
        Producer producer; char string[50];
        puts("Введите имя производителя");
        stringin(NAMELEN, string, "имя производителя");
        producer.SetName(string);

        printf("Введите номер телефона производителя(до %d символов): ", PHONELEN - 2);
        int x = 0; char num[PHONELEN];
        do {
            if (x) printf("Введите номер: ");
            stringin(PHONELEN, string, "номер телефона");
            sprintf(num, "%lld", atoll(string));
            x = 1;
        } while (strlen(num) != 11);
        producer.SetPhone(string);

        *producer_cntr = (*producer_cntr) + 1;
        *(producers + (*producer_cntr) - 1) = producer;
    }
}
//ф-я ввода продавца
void seller_add(Seller* sellers, int* sellers_cntr) {
    if (*sellers_cntr >= 10)
        printf("Достигнут лимит продавцов\n");
    else {
        Seller seller; char string[50];
        puts("Введите имя продавца");
        stringin(NAMELEN, string, "имя продавца");
        seller.SetName(string);

        printf("Введите номер телефона продавца(до %d символов): ", PHONELEN - 2);
        int x = 0; char num[PHONELEN];
        do {
            if (x) printf("Введите номер: ");
            stringin(PHONELEN, string, "номер телефона");
            sprintf(num, "%lld", atoll(string));
            x = 1;
        } while (strlen(num) != 11);
        seller.SetPhone(string);

        int salary;
        puts("Введите зарплату продавца");
        intin(&salary, 0, 1000000, "зарплату продавца");
        seller.SetSalary(salary);

        *sellers_cntr = (*sellers_cntr) + 1;
        *(sellers + (*sellers_cntr) - 1) = seller;
    }
}
//ф-я ввода покупателя
void buyer_add(Buyer* buyers, int* buyers_cntr) {
    if (*buyers_cntr >= 10)
        printf("Достигнут лимит покупателей\n");
    else {
        Buyer buyer; char string[50];
        puts("Введите имя покупателя");
        stringin(NAMELEN, string, "имя покупателя");
        buyer.SetName(string);

        printf("Введите номер телефона покупателя(до %d символов): ", PHONELEN - 2);
        int x = 0; char num[PHONELEN];
        do {
            if (x) printf("Введите номер: ");
            stringin(PHONELEN, string, "номер телефона");
            sprintf(num, "%lld", atoll(string));
            x = 1;
        } while (strlen(num) != 11);
        buyer.SetPhone(string);

        *buyers_cntr = *(buyers_cntr)+1;
        *(buyers + *(buyers_cntr)-1) = buyer;
    }
}
//ф-я ввода товара
int product_add(Product* products, int* products_cntr, Producer* producers, int producers_cntr) {
    if (*products_cntr >= 10) {
        printf("Достигнут лимит товаров\n");
        return 1;
    }
    if (producers_cntr == 0) {
        printf("Нет ни одного производителя\n");
        return 2;
    }
    Product product; char string[50]; int num;
    puts("Введите наименование товара");
    stringin(NAMELEN, string, "наименование товара");
    product.SetNameProduct(string);
    puts("Введите цену");
    intin(&num, 0, 1000000, "цену");
    product.SetPrice(num);
    puts("Введите кол-во товара");
    intin(&num, 0, 1000000, "кол-во товара");
    product.SetQuantityProduct(num);

    int select;
    class_out(producers, producers_cntr);
    puts("Введите номер производителя");
    intin(&select, 1, producers_cntr, "номер производителя");
    product.SetName((producers + select - 1)->GetName());
    product.SetPhone((producers + select - 1)->GetPhone());

    *products_cntr = *products_cntr + 1;
    *(products + *(products_cntr)-1) = product;
    return 0;
}
//ф-я ввода заказа
int order_add(Order* orders, int* order_cntr, Product* products, int products_cntr, Buyer* buyers, int buyers_cntr, Seller* sellers, int sellers_cntr) {
    if (*order_cntr >= 10) {
        printf("Достигнут лимит заказов\n");
        return 1;
    }
    if (products_cntr == 0) {
        printf("Нет ни одного товара\n");
        return 2;
    }
    if (buyers_cntr == 0) {
        printf("Нет ни одного покупателя\n");
        return 3;
    }
    if (sellers_cntr == 0) {
        printf("Нет ни одного продавца\n");
        return 4;
    }
    Order order; char string[50]; int num;
    puts("Введите id заказа");
    if (*order_cntr > 0) {
        int tr;
        do {
            tr = 0;
            intin(&num, 0, 999999, "id заказа");
            for (int i = 0; i < *(order_cntr); i++) {
                if ((orders + i)->GetId() == num)
                    tr = 1;
            }
            if (tr) puts("Такой id уже существует, ввведите другой");
        } while (tr);
    }
    else intin(&num, 0, 999999, "id заказа");
    order.SetId(num);

    puts("Введите дату заказа");
    int year, month, day;
    printf("Введите год: "); intin(&year, 1900, 3000, "год рождения");
    printf("Введите месяц: "); intin(&month, 1, 12, "месяц рождения");
    printf("Введите день: "); intin(&day, 1, 31, "день рождения");
    sprintf(string, "%d.%d.%d", day, month, year);
    order.SetDate(string);

    int select;
    class_out(products, products_cntr);
    puts("Введите номер товара");
    intin(&select, 1, products_cntr, "номер товара");
    order.SetProduct(*(products + select - 1));

    puts("Введите кол-во покумаемого товара товара");
    intin(&num, 1, (products + select - 1)->GetQuantityProduct(), "кол-во товара");
    order.SetQuantityOrder(num);

    class_out(buyers, buyers_cntr);
    puts("Введите номер покупателя");
    intin(&select, 1, buyers_cntr, "номер покупателя");
    order.SetBuyer(*(buyers + select - 1));

    class_out(sellers, sellers_cntr);
    puts("Введите номер продавца");
    intin(&select, 1, sellers_cntr, "номер продавца");
    order.SetSeller(*(sellers + select - 1));

    order.SetStatus(false);
    *order_cntr = *order_cntr + 1;
    *(orders + *(order_cntr)-1) = order;
    return 0;
}
//сумма заказа
void order_sum(Order* orders, int orders_cntr) {
    class_out(orders, orders_cntr);

    int num;
    puts("Введите номер заказа для подсчета суммы");
    intin(&num, 1, orders_cntr, "номер заказа");

    (orders + num - 1)->Sum();
}
//выполнение заказа
int order_complete(Order* orders, int orders_cntr, Product* products, int products_cntr, Order **orders_complete, int* orders_complete_cntr) {
    if (orders_cntr == 0) { puts("Нет заказов"); return 1; }
    bool st = true;
    for (int i = 0; i < orders_cntr; i++)
        if ((orders + i)->GetStatus() == false)
            st = false;
    if (st) {
        puts("Все заказы выполнены");
        return 2;
    }

    class_out(orders, orders_cntr);

    int num = 0;
    do {
        if (num)puts("Заказ уже выполнен");
        puts("Введите номер заказа для выполнения");
        intin(&num, 1, orders_cntr, "номер заказа");
    } while ((orders + num - 1)->GetStatus() == true);

    if ((orders + num - 1)->GetQuantityOrder() > (orders + num - 1)->GetQuantityProduct()) {
        puts("Недостаточно товара на складе");
    }
    else {
        (orders + num - 1)->SetStatus(true);

        (orders + num - 1)->SetQuantityProduct((orders + num - 1)->GetQuantityProduct() - (orders + num - 1)->GetQuantityOrder());
        for (int i = 0; i < products_cntr; i++) {
            if (strcmp((products + i)->GetNameProduct(), (orders + num - 1)->GetNameProduct()) == 0)
                (products + i)->SetQuantityProduct((orders + num - 1)->GetQuantityProduct());
        }

        for (int i = 0; i < orders_cntr; i++) {
            if (strcmp((orders + i)->GetNameProduct(), (orders + num - 1)->GetNameProduct()) == 0)
                (orders + i)->SetQuantityProduct((orders + num - 1)->GetQuantityProduct());
        }

        *orders_complete_cntr = *orders_complete_cntr + 1;
        Order* order_old;
        order_old = *orders_complete;

        *orders_complete =(Order*)malloc(*(orders_complete_cntr) * sizeof(Order));
        **orders_complete = *order_old;

        *(*(orders_complete)+*orders_complete_cntr - 1) = *(orders + num - 1);

        free(order_old);
    }
    return 0;
}

void seller_fire(Seller* sellers, int* sellers_cntr, Seller **sellers_dismissed, int* sellers_dismissed_cntr) {
    if (*sellers_cntr) {
        class_out(sellers, *sellers_cntr);
        int num;
        puts("Введите номер продавца");
        intin(&num, 1, *sellers_cntr, "номер продавца");

        Seller *sellers_old = new Seller[*sellers_cntr];
        for(int i = 0; i<*sellers_cntr ;i++)
            (sellers_old+i)->SetSeller(*(sellers+i));

        Seller *sellers_dismissed_old = new Seller[*sellers_dismissed_cntr];
        for (int i=0; i<*sellers_dismissed_cntr ;i++)
            (sellers_dismissed_old+i)->SetSeller(**(sellers_dismissed + i));

        *sellers_dismissed_cntr = *sellers_dismissed_cntr + 1;
        *sellers_dismissed = new Seller[*sellers_dismissed_cntr];
        **sellers_dismissed = *sellers_dismissed_old;
        *(*(sellers_dismissed) + *sellers_dismissed_cntr - 1) = *(sellers + num - 1);

        for (int i = 0; i < num-1; i++)
            *(sellers + i) = *(sellers_old + i);
        for (int i = num; i < *sellers_cntr; i++)
            *(sellers + i-1) = *(sellers_old + i);

        delete[] sellers_old;
        *sellers_cntr = *sellers_cntr - 1;
    }
    else puts("Нет продавцов");
}

//основная программа-меню, вызывающая различные функции
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int selection, exit = 1, stringcntr = 0;
    puts("Программа «Заказы»\n");

    Producer producers[10]; int producers_cntr = 0;
    Seller sellers[10]; int sellers_cntr = 0;
    Buyer buyers[10]; int buyers_cntr = 0;
    Product products[10]; int products_cntr = 0;
    Order orders[10]; int orders_cntr = 0;
    Order* orders_complete = (Order*)malloc(sizeof(Order)); int orders_complete_cntr = 0;
    Seller* sellers_dismissed = {new Seller}; int sellers_dismissed_cntr = 0;


    do {
        puts("1.Добавление\n2.Вывод\n3.Сумма заказа\n4.Выполнить заказ\n5.Уволить продавца\n6.Выход");
        printf("Выберете дальнейшее действие: ");
        intin(&selection, 1, 6, "вариант пункта меню");

        int exit1 = 1;
        switch (selection)
        {
        case 1:
            do {
                puts("1.Добавление производителя \n2.Добавление продавца\n3.Добавление покупателя\n4.Добавление товара\n5.Добавление заказа\n6.Выход к прошлому меню");
                printf("Выберете дальнейшее действие: ");
                intin(&selection, 1, 6, "вариант пункта меню");
                switch (selection) {
                case 1: producer_add(producers, &producers_cntr); break;
                case 2: seller_add(sellers, &sellers_cntr); break;
                case 3: buyer_add(buyers, &buyers_cntr); break;
                case 4: product_add(products, &products_cntr, producers, producers_cntr); break;
                case 5: order_add(orders, &orders_cntr, products, products_cntr, buyers, buyers_cntr, sellers, sellers_cntr); break;
                case 6: exit1 = 0; break;
                }
            } while (exit1);
            break;
        case 2:
            do {
                puts("1.Вывод производителя \n2.Вывод продавца\n3.Вывод покупателя\n4.Вывод товара\n5.Вывод заказа\n6.Вывод выполненных заказов\n7.Вывод уволенных продавцов\n8.Выход к прошлому меню");
                printf("Выберете дальнейшее действие: ");
                intin(&selection, 1, 8, "вариант пункта меню");
                switch (selection) {
                case 1: class_out(producers, producers_cntr); break;
                case 2: class_out(sellers, sellers_cntr); break;
                case 3: class_out(buyers, buyers_cntr); break;
                case 4: class_out(products, products_cntr); break;
                case 5: class_out(orders, orders_cntr); break;
                case 6: class_out(orders_complete, orders_complete_cntr); break;
                case 7: class_out(sellers_dismissed, sellers_dismissed_cntr); break;
                case 8: exit1 = 0; break;
                }
            } while (exit1);
            break;
        case 3: order_sum(orders, orders_cntr); break;
        case 4: order_complete(orders, orders_cntr, products, products_cntr, &orders_complete, &orders_complete_cntr); break;
        case 5: seller_fire(sellers, &sellers_cntr, &sellers_dismissed, &sellers_dismissed_cntr); break;
        case 6: exit = 0; break;
        }
    } while (exit);
}