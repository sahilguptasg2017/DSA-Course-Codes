#include <stdio.h>
 
#define N 3000

 
int partitioning(int l, int h, int arr[]) {
    int pivot = arr[l];
    int i = l, j = h;
    while (i < j) {
        do {
            i++;
        } while (arr[i] <= pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        int key = arr[i];
        if (i < j) {
            arr[i] = arr[j];
            arr[j] = key;
        }
    }
    int key1 = arr[l];
    arr[l] = arr[j];
    arr[j] = key1;
    return j;
}
 
void Quicksort(int l, int h, int arr[]) {
    if (l < h) {
        int j = partitioning(l, h, arr);
        Quicksort(l, j, arr);
        Quicksort(j + 1, h, arr);
    }
}
 
int atMostK(int arr[], int n, int k) {
    int count = 0;
    int left = 0;
    int right = 0;
    int distinct = 0;
    int freq[100001] = {0};
    while (right < n) {
        if (freq[arr[right]] == 0) {
            distinct++;
        }
        freq[arr[right]]++;
        while (left <= right && distinct > k) {
            if (freq[arr[left]] == 1) {
                distinct--;
            }
            freq[arr[left]]--;
            left++;
        }
        count += right - left + 1;
        right++;
    }
    return count;
}
 
int exactlyK(int arr[], int n, int k) {
    return (atMostK(arr, n, k) - atMostK(arr, n, k - 1));
}
 
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int arr[N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Quicksort(0, n, arr);
    for (int j = 0; j < q; j++) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        int arr2[r - l + 1];
        int h = 0;
        for (int b = l; b <= r; b++) {
            arr2[h++] = arr[b];
        }
        int count = exactlyK(arr2, r - l + 1, k);
        printf("%d\n", count);
    }
    return 0;
}

