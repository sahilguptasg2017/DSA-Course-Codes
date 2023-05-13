#include <stdio.h>

int binarysearch(int x, int arr[], int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) {
            return mid;
        } 
        else if (arr[mid] < x) {
            left = mid + 1;
        }
         else {
            right = mid - 1;
        }
    }
    return left;
}

int index1(int x, int n, int arr1[], int arr2[]) {
    int index = binarysearch(x, arr1, n);
    while (index > 0 && arr1[index - 1] == x) {
        index--;
    }
    return index;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int arr1[n];
    int arr2[q];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < q; i++) {
        printf("%d\n", index1(arr2[i], n, arr1, arr2));
    }
    return 0;
}