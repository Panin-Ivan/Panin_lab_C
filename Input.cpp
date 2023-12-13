#include "Input.h"
void stringin(int maxlength, char* string, const char* message) {
    do {				//maxlenght-максимальна€ длина строки, string-входна€ строка, message-сообщение при ошибке
        fgets(string, maxlength, stdin);
        if (strchr(string, '\n')) *strchr(string, '\n') = 0;
        if (strlen(string) <= 0 || strlen(string) > (maxlength - 2))
            printf("ќшибка. ¬ведите %s(до %d символов): ", message, (maxlength - 2));
        rewind(stdin);
    } while (strlen(string) <= 0 || strlen(string) > (maxlength - 2));
}
void intin(int* value, int lower_limit, int upper_limit, const char* message) {
    int i = 0;		//value-входное значение, lower_limit-нижний предел, upper_limit-верхний предел ,message-сообщение об ошибке
    do {
        if (i)printf("ќшибка. ¬ведите %s(от %d до %d): ", message, lower_limit, upper_limit);
        while (scanf("%d", value) != 1) {
            while (getchar() != '\n');
            printf("ќшибка. ¬ведите число: ");
        }
        i = 1;
        rewind(stdin);
    } while (*value<lower_limit || *value>upper_limit);
}