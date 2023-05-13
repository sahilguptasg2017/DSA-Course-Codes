#include <stdio.h>

#define N 3000
#define MAX_VAL 100000

int freq[MAX_VAL + 1] = {0};

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + j + 1];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k++] = L[i++];

        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int atMostK(int arr[], int l, int r, int k) {
    int count = 0;
    int left = 0;
    int right = 0;
    int distinct = 0;
    int pre[r-l + 1];
    pre[0] = 0;
    int possible = 1; 

    while (right < r-l) {
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

        pre[right + 1] = pre[right] + (right - left + 1);
        count += pre[right + 1] - pre[left]; 
        right++;

        
        if (possible && freq[r-l]-freq[right-l]<k-1) {
            possible = 0;
        }
    }

   
    for (int i = left; i < right; i++) {
        freq[arr[i]]--;
    }

    
    return possible ? count : 0;
}


int exactlyK(int arr[], int l,int r, int k) {
    return (atMostK(arr, l,r, k) - atMostK(arr, l,r, k - 1));
}
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int arr[N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr,0,n-1);
    for (int j = 0; j < q; j++) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        int arr2[r - l + 1];
        int h = 0;
        for (int b = l; b <= r; b++) {
            arr2[h++] = arr[b];
        }
       

        int count = exactlyK(arr2, l, r , k);
        printf("%d\n", count);
    }   
    return 0;
}