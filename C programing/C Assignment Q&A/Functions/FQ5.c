
#include <stdio.h>

float add(float a, float b) { return a + b; }
float sub(float a, float b) { return a - b; }
float mul(float a, float b) { return a * b; }
float div(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

float calc(float a, float b, char op) {
    switch (op) {
        case '+': return add(a, b);
        case '-': return sub(a, b);
        case '*': return mul(a, b);
        case '/': return div(a, b);
        default:
            printf("Invalid operator!\n");
            return 0;
    }
}

int main() {
    float x, y, result;
    char op;

    printf("Enter first number: ");
    scanf("%f", &x);
    printf("Enter operator (+ - * /): ");
    scanf(" %c", &op);
    printf("Enter second number: ");
    scanf("%f", &y);

    result = calc(x, y, op);
    printf("Result: %.2f\n", result);

    return 0;
}


