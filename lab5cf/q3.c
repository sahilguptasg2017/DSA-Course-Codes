#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
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

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    long long *list_1 = malloc(n * sizeof(long long));
    long long *list_2 = malloc(n * sizeof(long long));
    long long *list_3 = malloc(n * n * sizeof(long long));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &list_1[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%lld", &list_2[i]);
    }

    int index = 0;
    for (int j = 0; j < n; j++) {
        for (int u = 0; u < n; u++) {
            list_3[index++] = list_1[j] + list_2[u];
        }
    }

    mergeSort(list_3, 0, (n * n) - 1);

    for (int i = 0; i < q; i++) {
        int y;
        scanf("%d", &y);
        printf("%lld\n", list_3[y - 1]);
    }

    free(list_1);
    free(list_2);
    free(list_3);

    return 0;
}
