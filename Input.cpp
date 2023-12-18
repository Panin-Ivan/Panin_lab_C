#include "Input.h"
void stringin(int maxlength, std::string* string, const char* message) {
    do {				//maxlenght-������������ ����� ������, string-������� ������, message-��������� ��� ������
        getline(cin,*string,'\n');
        if (string->size() <= 0 || string->size() > (maxlength - 2))
            printf("������. ������� %s(�� %d ��������): ", message, (maxlength - 2));
        rewind(stdin);
    } while (string->size() <= 0 || string->size() > (maxlength - 2));
}
void intin(int* value, int lower_limit, int upper_limit, const char* message) {
    int i = 0;		//value-������� ��������, lower_limit-������ ������, upper_limit-������� ������ ,message-��������� �� ������
    do {
        string str;
        if (i)printf("������. ������� %s(�� %d �� %d): ", message, lower_limit, upper_limit);
        getline(cin, str);
        *value = stoi(str);
        i = 1;
        rewind(stdin);
    } while (*value<lower_limit || *value>upper_limit);
}