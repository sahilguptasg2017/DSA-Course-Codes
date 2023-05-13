#include <stdio.h>
#include <stdbool.h>
#define N 3000

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
    return atMostK(arr, n, k) - atMostK(arr, n, k - 1);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int arr[N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int j = 0; j < q; j++) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        int count = 0;
        int left = 0;
        int right = 0;
        int distinct = 0;
        int freq[100001] = {0};
        for (int i = l - 1; i < r; i++) {
            if (freq[arr[i]] == 0) {
                distinct++;
            }
            freq[arr[i]]++;
            while (distinct > k) {
                if (freq[arr[left]] == 1) {
                    distinct--;
                }
                freq[arr[left]]--;
                left++;
            }
            if (distinct == k) {
                count += (left == 0 ? i - l + 2 : i - left + 1);
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
