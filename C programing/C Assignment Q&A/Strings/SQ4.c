#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    int letters[26] = {0};  // track presence of each alphabet
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // read full line including spaces

    // Traverse the string
    for (i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {  // check if character is a letter
            char ch = tolower(str[i]);  // convert to lowercase
            letters[ch - 'a'] = 1;      // mark letter as found
        }
    }

    // Check if all 26 letters are present
    int isPangram = 1;
    for (i = 0; i < 26; i++) {
        if (letters[i] == 0) {
            isPangram = 0;
            break;
        }
    }

    if (isPangram) {
        printf("The string is a pangram.\n");
    } else {
        printf("The string is NOT a pangram.\n");
    }

    return 0;
}
