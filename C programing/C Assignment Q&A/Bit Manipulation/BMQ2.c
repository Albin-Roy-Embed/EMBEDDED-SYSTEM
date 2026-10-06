#include <stdio.h>

int main() {
    int num, pos, n;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter starting bit position: ");
    scanf("%d", &pos);
    printf("Enter number of bits to extract: ");
    scanf("%d", &n);

    int mask = ((1 << n) - 1) << pos;
    int result = (num & mask) >> pos;

    printf("Extracted bits = %d\n", result);
    return 0;
}

