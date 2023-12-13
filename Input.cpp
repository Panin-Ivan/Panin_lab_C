#include "Input.h"
void stringin(int maxlength, char* string, const char* message) {
    do {				//maxlenght-������������ ����� ������, string-������� ������, message-��������� ��� ������
        fgets(string, maxlength, stdin);
        if (strchr(string, '\n')) *strchr(string, '\n') = 0;
        if (strlen(string) <= 0 || strlen(string) > (maxlength - 2))
            printf("������. ������� %s(�� %d ��������): ", message, (maxlength - 2));
        rewind(stdin);
    } while (strlen(string) <= 0 || strlen(string) > (maxlength - 2));
}
void intin(int* value, int lower_limit, int upper_limit, const char* message) {
    int i = 0;		//value-������� ��������, lower_limit-������ ������, upper_limit-������� ������ ,message-��������� �� ������
    do {
        if (i)printf("������. ������� %s(�� %d �� %d): ", message, lower_limit, upper_limit);
        while (scanf("%d", value) != 1) {
            while (getchar() != '\n');
            printf("������. ������� �����: ");
        }
        i = 1;
        rewind(stdin);
    } while (*value<lower_limit || *value>upper_limit);
}