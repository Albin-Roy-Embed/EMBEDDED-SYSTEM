#include <stdio.h>

// Function to count digit frequencies

void countDigits(int num, int freq[]) {
    while (num > 0) {
        int digit = num % 10;  
        freq[digit]++;        
        num = num / 10;         
    }
}

int main() {
    int num;
    int freq[10] = {0}; 

    printf("Enter an integer: ");
    scanf("%d", &num);

    countDigits(num, freq);

    for (int i = 0; i < 10; i++) {
        if (freq[i] > 0) {
            printf("%d occurs %d times\n", i, freq[i]);
        }
    }

    return 0;
}
