#include "Input.h"
void stringin(int maxlength, std::string* string, const char* message) {
    do {				//maxlenght-максимальна€ длина строки, string-входна€ строка, message-сообщение при ошибке
        getline(cin,*string,'\n');
        if (string->size() <= 0 || string->size() > (maxlength - 2))
            printf("ќшибка. ¬ведите %s(до %d символов): ", message, (maxlength - 2));
        rewind(stdin);
    } while (string->size() <= 0 || string->size() > (maxlength - 2));
}
void intin(int* value, int lower_limit, int upper_limit, const char* message) {
    int i = 0;		//value-входное значение, lower_limit-нижний предел, upper_limit-верхний предел ,message-сообщение об ошибке
    do {
        string str;
        if (i)printf("ќшибка. ¬ведите %s(от %d до %d): ", message, lower_limit, upper_limit);
        getline(cin, str);
        *value = stoi(str);
        i = 1;
        rewind(stdin);
    } while (*value<lower_limit || *value>upper_limit);
}