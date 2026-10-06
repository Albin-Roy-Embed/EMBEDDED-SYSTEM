#include <stdio.h>

int main() {
    int num, i;
    int fact = 1;   // start with 1

    printf("Enter a positive number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial not defined for negative numbers\n");
    } else {
        for (i = 1; i <= num; i++) {
            fact = fact * i;   // multiply step by step
        }
        printf("Factorial of %d = %d\n", num, fact);
    }

    return 0;
}

