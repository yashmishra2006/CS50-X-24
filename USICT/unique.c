#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    int temp[n]; // Temporary array to store unique elements
    int j = 0;   // Index for the unique array

    // Iterate through the original array
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;

        // Check if the element is already in the unique array
        for (int k = 0; k < j; k++) {
            if (arr[i] == temp[k]) {
                isDuplicate = 1;
                break;
            }
        }

        // If not a duplicate, add to the unique array
        if (!isDuplicate) {
            temp[j] = arr[i];
            j++;
        }
    }

printf("Number of unique elements - %d\n", j);
return 0;

}




int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the %d element of the array: ", i+1);
        scanf("%d", &arr[i]);
    }

    removeDuplicates(arr, n);

    return 0;
}
