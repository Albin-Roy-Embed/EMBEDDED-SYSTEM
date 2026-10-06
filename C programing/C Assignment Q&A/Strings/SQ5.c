#include <stdio.h>

int main() {
    char str[200];
    int i, j = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (!(str[i] == ' ' && str[i+1] == ' ')) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    printf("Cleaned string: %s\n", str);
    return 0;
}
