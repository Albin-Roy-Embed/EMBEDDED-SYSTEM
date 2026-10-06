#include <stdio.h>

int main() {
    int num1, num2, pos, n;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter starting bit position: ");
    scanf("%d", &pos);
    printf("Enter number of bits to swap: ");
    scanf("%d", &n);

    int mask = ((1 << n) - 1) << pos;

    int bits1 = num1 & mask;
    int bits2 = num2 & mask;

    num1 = (num1 & ~mask) | bits2;
    num2 = (num2 & ~mask) | bits1;

    printf("After swap:\n");
    printf("First number = %d\n", num1);
    printf("Second number = %d\n", num2);

    return 0;
}
