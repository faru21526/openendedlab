//ID:241014080
//Name:Farjana Akter Jim

#include <stdio.h>
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
}

int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == x)
            return 1;
        else if(arr[mid] < x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

int main() {
    int n1, n2, x;
printf("Lab-A n1: ");
    scanf("%d", &n1);
    int labA[n1];
    for(int i = 0; i < n1; i++){
            scanf("%d", &labA[i]);
    }
    printf("Lab-B n2: ");
    scanf("%d", &n2);
    int labB[n2];
    for(int i = 0; i < n2; i++){
            scanf("%d", &labB[i]);
    }
printf("Score to search (x): ", x);
    scanf("%d", &x);

    int merged[n1 + n2];
    for(int i = 0; i < n1; i++){
            merged[i] = labA[i];
    }
    for(int i = 0; i < n2; i++) {
            merged[n1 + i] = labB[i];
    }

    selectionSort(merged, n1 + n2);

    for(int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    if(binarySearch(merged, n1 + n2, x))
        printf("Score %d is present in the list.\n", x);
    else
        printf("Score %d is not present in the list.\n", x);

    return 0;
}
