#include <stdio.h>

#define true 1

int main(void) {
    while (true) {
        int n;
        
        printf("Enter a number: ");
        scanf("%d", &n);

        if (n == 0) break;

        printf("Size in bytes: %d\n", (int) sizeof n);
    }

    return 0;
}