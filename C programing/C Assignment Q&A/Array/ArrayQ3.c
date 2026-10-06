#include <stdio.h>

int main() {
    int arr[100], n, size, i;
    char dir;

    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) scanf("%d", &arr[i]);

    printf("Rotate by how many positions: ");
    scanf("%d", &n);

    printf("Direction (L/R): ");
    scanf(" %c", &dir);

    n = n % size;  // normalize

    int res[100];
    for (i = 0; i < size; i++) {
        if (dir == 'L' || dir == 'l')
            res[i] = arr[(i + n) % size];
        else
            res[i] = arr[(i - n + size) % size];
    }

    printf("Rotated array:\n");
    for (i = 0; i < size; i++) printf("%d ", res[i]);

    return 0;
}
