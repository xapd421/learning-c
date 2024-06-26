#include <stdio.h>

int main(void)
{
    int age = 16;
    printf("How old are you?\n");
    scanf("%d", &age);
    printf("Hello world. I am %d years %.2f old %d\n", age, 99.99f, 10);
    return 0;
}