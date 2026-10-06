include <stdio.h>

void convert(int num, int base) {
    char digits[] = "0123456789ABCDEF";
    char result[50];
    int i = 0;

    if (num == 0) {
        printf("0\n");
        return;
    }

    while (num > 0) {
        result[i++] = digits[num % base]; 
        num = num / base;
    }

    // print in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", result[j]);
    }
    printf("\n");
}

int main() {
    int num, base;
    printf("Enter decimal number: ");
    scanf("%d", &num);
    printf("Enter base (2–16): ");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("Invalid base!\n");
        return 0;
    }

    printf("Converted value: ");
    convert(num, base);

    return 0;
}

