#include <stdio.h>

int main() {
    int n, i;
    int a = 0, b = 1, next;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number.\n");
    } else {
        printf("Fibonacci Series: ");
        for (i = 1; i <= n; i++) {
            printf("%d ", a);
            next = a + b;   
            a = b;          
            b = next;
        }
        printf("\n");
    }

    return 0;
}
