#include <stdio.h>

int main() {
    int num;
    char str[50];   // buffer to hold the string

    printf("Enter an integer: ");
    scanf("%d", &num);

    // Convert integer to string using sprintf
    sprintf(str, "%d", num);

    printf("String value: %s\n", str);

    return 0;
}

