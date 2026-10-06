int main() {
    int number, i;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number <= 1) {
        printf("Not prime\n");
    } else {
        for (i = 2; i < number; i++) {
            if (number % i == 0) {
                printf("Not prime\n");
                return 0;  
            }
        }
        printf("Prime\n");
    }

    return 0;
}
