#include <stdio.h>

int main() {
    int arr[100], neg[100], pos[100];
    int n, i, ni = 0, pi = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Separate negatives and positives
    for (i = 0; i < n; i++) {
        if (arr[i] < 0)
            neg[ni++] = arr[i];
        else
            pos[pi++] = arr[i];
    }

    // Merge back into arr
    for (i = 0; i < ni; i++) arr[i] = neg[i];
    for (i = 0; i < pi; i++) arr[ni + i] = pos[i];

    printf("Rearranged array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

