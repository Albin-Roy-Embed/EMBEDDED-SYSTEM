#include <stdio.h>

int main() {
    int arr[100], n, i;
    int largest, secondLargest, smallest, secondSmallest;

    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Need at least two elements.\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = smallest = arr[0];
    secondLargest = secondSmallest = arr[0];

    // find largest and smallest
    for (i = 1; i < n; i++) {
        if (arr[i] > largest) largest = arr[i];
        if (arr[i] < smallest) smallest = arr[i];
    }

    // find second largest and second smallest
    for (i = 0; i < n; i++) {
        if (arr[i] != largest && (arr[i] > secondLargest || secondLargest == largest))
            secondLargest = arr[i];
        if (arr[i] != smallest && (arr[i] < secondSmallest || secondSmallest == smallest))
            secondSmallest = arr[i];
    }

    if (largest == smallest) {
        printf("All elements are same.\n");
    } else {
        printf("Second largest = %d\n", secondLargest);


