#include <stdio.h>
#define MAX 100005

void merge(int arr[], int arr2[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    int L_arr2[n1], R_arr2[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        L_arr2[i] = arr2[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        R_arr2[j] = arr2[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            arr2[k] = L_arr2[i];
            i++;
        }
        else {
            arr[k] = R[j];
            arr2[k] = R_arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        arr2[k] = L_arr2[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        arr2[k] = R_arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int arr2[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, arr2, l, m);
        mergeSort(arr, arr2, m + 1, r);

        merge(arr, arr2, l, m, r);
    }
}

int minSwaps(int arr[], int n) {

    int arr2[n];
    for (int i = 0; i < n; i++) {
        arr2[i] = i;
    }

    mergeSort(arr, arr2, 0, n-1);

    int vis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        
        if (vis[i] || arr2[i] == i) {
            continue;
        }
        int cycle_size = 0;
        int j = i;
    
        while (!vis[j]) {
            vis[j] = 1;
            j = arr2[j];
            cycle_size += 1;
        }

        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }

  
    return ans;
}

int main() {
    int n;
    int arr[MAX];
    scanf("%d",&n);
    for (int o=0;o<n;o++){
        scanf("%d",&arr[o]);
    }
    printf("%d", minSwaps(arr, n));
    return 0;
}