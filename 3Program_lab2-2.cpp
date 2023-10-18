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
    Producer() {
        
    }
    void Out() {
        printf("%-30s|%s\n", this->GetName(), this->GetPhone());
    }
private:

};

class Seller : public Human {
public:
    Seller(){
        salary = 0;
    }
private:
    int salary;             //Зарплата
};

class Buyer : public Human {
public:
    Buyer() {

    }
private:

};

class Product : public Producer {
public:
    Product() {
        strcpy(name, "product_name");
        price = 0;
        quantity = 0;
    }
private:
    char name[NAMELEN];     //Наименование товара
    int price;              //Цена товара
    int quantity;           //кол-во товара на складе
};

class Order: public Product, Buyer, Seller{
public:
    Order() {
        id = 0;
        strcpy(date, "10.10.2023");
        quantity = 0;
        status = false;
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
void struct_out(Producer* producers, int producer_cntr) {
    printf("%-2s|%-30s|%s\n", "№", "Имя производителя", "Номер телефона");

    for (int i = 0; i < producer_cntr; i++) {
        printf("%-2d|", i + 1);
        (producers + i)->Out();
    }
}
/*
//ф-я вывода продавца
void struct_out(Seller* sellers, int sellers_cntr) {
    printf("%-2s|%-30s|%s\n", "№", "Имя продавца", "Номер телефона");

    for (int i = 0; i < sellers_cntr; i++)
        printf("%-2d|%-30s|%s\n", i + 1, (sellers + i)->name, (sellers + i)->phone);
}
//ф-я вывода покупателя
void struct_out(Buyer* buyers, int buyers_cntr) {
    printf("%-2s|%-30s|%s\n", "№", "Имя покупателя", "Номер телефона");

    for (int i = 0; i < buyers_cntr; i++)
        printf("%-2d|%-30s|%s\n", i + 1, (buyers + i)->name, (buyers + i)->phone);
}
//ф-я вывода товара
void struct_out(Product* products, int products_cntr) {
    printf("%-2s|%-30s|%-10s|%-13s|%-30s|%-21s\n", "№", "Название", "Цена", "Кол-во товара", "Имя производителя", "Телефон производителя");

    for (int i = 0; i < products_cntr; i++)
        printf("%-2d|%-30s|%-10d|%-13d|%-30s|%-21s\n", i + 1, (products + i)->name, (products + i)->price, (products + i)->quantity, (products + i)->producer->name, (products + i)->producer->phone);
}
//ф-я вывода заказа
void struct_out(Order* orders, int orders_cntr) {
    puts("Заказы");
    printf("%-2s|%-6s|%-10s|%-13s|%-6s\n", "№", "id", "Дата", "Кол-во товара", "Статус");
    for (int i = 0; i < orders_cntr; i++)
        printf("%-2d|%-6d|%-10s|%-13d|%-d\n", i + 1, (orders + i)->id, (orders + i)->date, (orders + i)->quantity, (orders + i)->status);

    int select;
    do {
        puts("Вывести дополнительную информацию о заказе?\n1.Да\n2.Нет");
        intin(&select, 1, 2, "номер варианта");
        if (select == 1) {
            puts("Введите номер варианта, для которого небходимо вывести всю информацию");
            int i; intin(&i, 1, orders_cntr, "номер варианта");
            i = i - 1;

            puts("Товар данного заказа");
            printf("%-30s|%-7s|%-13s|%-30s|%-21s\n", "Наименование товара", "Цена", "Кол-во товара", "Наименование производителя", "Телефон производителя");
            printf("%-30s|%-7d|%-13d|%-30s|%-21s\n", (orders + i)->product->name, (orders + i)->product->price, (orders + i)->product->quantity, (orders + i)->product->producer->name, (orders + i)->product->producer->phone);

            puts("Покупатель данного заказа");
            printf("%-30s|%-18s\n", "Имя покупателя", "Телефон покупателя");
            printf("%-30s|%-18s\n", (orders + i)->buyer->name, (orders + i)->buyer->phone);

            puts("Продавец данного заказа");
            printf("%-30s|%-16s\n", "Имя продавца", "Телефон продавца");
            printf("%-30s|%-16s\n", (orders + i)->seller->name, (orders + i)->seller->phone);
        }
    } while (select != 2);
}                                           
*/
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
/*
//ф-я ввода продавца
void seller_add(Seller* sellers, int* sellers_cntr) {
    if (*sellers_cntr >= 10)
        printf("Достигнут лимит продавцов\n");
    else {
        Seller seller;
        puts("Введите имя продавца");
        stringin(NAMELEN, seller.name, "имя продавца");

        printf("Введите номер телефона продавца(до %d символов): ", PHONELEN - 2);
        int x = 0; char num[PHONELEN];
        do {
            if (x) printf("Введите номер: ");
            stringin(PHONELEN, seller.phone, "номер телефона");
            sprintf(num, "%lld", atoll(seller.phone));
            x = 1;
        } while (strlen(num) != 11);

        *sellers_cntr = (*sellers_cntr) + 1;
        *(sellers + (*sellers_cntr) - 1) = seller;
    }
}
//ф-я ввода покупателя
void buyer_add(Buyer* buyers, int* buyers_cntr) {
    if (*buyers_cntr >= 10)
        printf("Достигнут лимит покупателей\n");
    else {
        Buyer buyer;
        puts("Введите имя покупателя");
        stringin(NAMELEN, buyer.name, "имя покупателя");

        printf("Введите номер телефона покупателя(до %d символов): ", PHONELEN - 2);
        int x = 0; char num[PHONELEN];
        do {
            if (x) printf("Введите номер: ");
            stringin(PHONELEN, buyer.phone, "номер телефона");
            sprintf(num, "%lld", atoll(buyer.phone));
            x = 1;
        } while (strlen(num) != 11);

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
    Product struc;
    puts("Введите наименование товара");
    stringin(NAMELEN, struc.name, "наименование товара");
    puts("Введите цену");
    intin(&struc.price, 0, 1000000, "цену");
    puts("Введите кол-во товара");
    intin(&struc.quantity, 0, 1000000, "кол-во товара");

    int select;
    struct_out(producers, producers_cntr);
    puts("Введите номер производителя");
    intin(&select, 1, producers_cntr, "номер производителя");
    struc.producer = (producers + select - 1);

    *products_cntr = *products_cntr + 1;
    *(products + *(products_cntr)-1) = struc;
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
    Order struc;
    puts("Введите id заказа");
    if (*order_cntr > 0) {
        int tr = 1;
        do {
            intin(&struc.id, 0, 999999, "id заказа");
            for (int i = 0; i < *(order_cntr)-1; i++) {
                if ((orders + i)->id == struc.id)
                    tr = 0;
            }
            if (tr) puts("Такой id уже существует, ввведите другой");
        } while (tr);
    }
    else intin(&struc.id, 0, 999999, "id заказа");

    puts("Введите дату заказа");
    int year, month, day;
    printf("Введите год: "); intin(&year, 1900, 3000, "год рождения");
    printf("Введите месяц: "); intin(&month, 1, 12, "месяц рождения");
    printf("Введите день: "); intin(&day, 1, 31, "день рождения");
    sprintf(struc.date, "%d.%d.%d", day, month, year);

    int select;
    struct_out(products, products_cntr);
    puts("Введите номер товара");
    intin(&select, 1, products_cntr, "номер товара");
    struc.product = (products + select - 1);

    puts("Введите кол-во покумаемого товара товара");
    intin(&struc.quantity, 1, (products + select - 1)->quantity, "кол-во товара");

    struct_out(buyers, buyers_cntr);
    puts("Введите номер покупателя");
    intin(&select, 1, buyers_cntr, "номер покупателя");
    struc.buyer = (buyers + select - 1);

    struct_out(sellers, sellers_cntr);
    puts("Введите номер продавца");
    intin(&select, 1, sellers_cntr, "номер продавца");
    struc.seller = (sellers + select - 1);

    struc.status = false;
    *order_cntr = *order_cntr + 1;
    *(orders + *(order_cntr)-1) = struc;
    return 0;
}

void order_sum(Order* orders, int orders_cntr) {
    struct_out(orders, orders_cntr);

    int sum, num;
    puts("Введите номер заказа для подсчета суммы");
    intin(&num, 1, orders_cntr, "номер заказа");

    sum = (orders + num - 1)->quantity * (orders + num - 1)->product->price;
    printf("Сумма заказа id%d: %d\n", (orders + num - 1)->id, sum);
}

int order_complete(Order* orders, int orders_cntr) {
    if (orders_cntr == 0) { puts("Нет заказов"); return 1; }
    bool st = true;
    for (int i = 0; i < orders_cntr; i++)
        if ((orders + i)->status == false)
            st = false;
    if (st) {
        puts("Все заказы выполнены");
        return 2;
    }

    struct_out(orders, orders_cntr);

    int num = 0;
    do {
        if (num)puts("Заказ уже выполнен");
        puts("Введите номер заказа для выполнения");
        intin(&num, 1, orders_cntr, "номер заказа");
    } while ((orders + num - 1)->status == true);
    (orders + num - 1)->status = true;

    (orders + num - 1)->product->quantity = (orders + num - 1)->product->quantity - (orders + num - 1)->quantity;
    return 0;
}
*/
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

    do {
        puts("1.Добавление\n2.Вывод\n3.Сумма заказа\n4.Выполнить заказ\n5.Выход");
        printf("Выберете дальнейшее действие: ");
        intin(&selection, 1, 5, "вариант пункта меню");

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
                case 2: break;
                case 3: break;
                case 4: break;
                case 5: break;
                case 6: exit1 = 0;
                }
            } while (exit1);
            break;
        case 2:
            do {
                puts("1.Вывод производителя \n2.Вывод продавца\n3.Вывод покупателя\n4.Вывод товара\n5.Вывод заказа\n6.Выход к прошлому меню");
                printf("Выберете дальнейшее действие: ");
                intin(&selection, 1, 6, "вариант пункта меню");
                switch (selection) {
                case 1: struct_out(producers, producers_cntr); break;
                case 2: break;
                case 3: break;
                case 4: break;
                case 5: break;
                case 6: exit1 = 0;
                }
            } while (exit1);
            break;
        case 3: break;
        case 4: break;
        case 5: exit = 0; break;
        }
    } while (exit);
}