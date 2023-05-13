#include <stdio.h>

void Merge(int arr1[], int arr2[], int m, int n, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i <= m && j <= n) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }
    for (; i <= m; i++) {
        arr3[k++] = arr1[i];
    }
    for (; j <= n; j++) {
        arr3[k++] = arr2[j];
    }
}
void mergesort(int l, int h, int arr[]) {
    if (l < h) {
        int mid = l + (h - l) / 2;
        mergesort(l, mid, arr);
        mergesort(mid + 1, h, arr);
        int arr1[mid - l + 1];
        for (int i = l; i <= mid; i++) {
            arr1[i - l] = arr[i];
        }
        int arr2[h - mid];
        for (int i = mid + 1; i <= h; i++) {
            arr2[i - mid - 1] = arr[i];
        }
        int newarr[h - l + 1];
        Merge(arr1, arr2, mid - l + 1, h - mid-1, newarr);
        for (int i = l; i <= h; i++) {
            arr[i] = newarr[i - l];
        }
    }
}
int main() {
    int arr[] = {6,5,3,9,14,12};
    int m = sizeof(arr) / sizeof(arr[0]);
    mergesort(0, m-1, arr);
    for (int i = 0; i < m; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
