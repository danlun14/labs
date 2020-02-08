#include <stdio.h>


typedef struct {
    int num;
    char str[4];
} NumberRepr;
void format(NumberRepr* number) {
    sprintf(number->str, "%4d", number->num);
}
int main() {
    NumberRepr number = { .num = 1025 };
    format(&number);
    printf("str: %s\n", number.str);
    printf("num: %d\n", number.num);
    return 0;
}