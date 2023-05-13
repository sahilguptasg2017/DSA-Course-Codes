#include <stdio.h>

#define MAX_M 500
#define MAX_N 500

struct Pair {
    int sum;
    int index;
};

void* my_malloc(int size) {
    static char memory[MAX_M * MAX_N * sizeof(int)];
    static int used = 0;
    void* ptr = memory + used;
    used += size;
    return ptr;
}

void my_free(void* ptr) {
}

void my_calloc(int size, int num, void* ptr) {
    for (int i = 0; i < size*num; i++) {
        ((char*)ptr)[i] = 0;
    }
}

void swap(struct Pair *a, struct Pair *b) {
    struct Pair temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Pair arr[], int low, int high) {
    int pivot = arr[high].sum;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].sum < pivot || (arr[j].sum == pivot && arr[j].index < arr[high].index)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quicksort(struct Pair arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index-1);
        quicksort(arr, pivot_index+1, high);
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int (*A)[MAX_N] = my_malloc(m * sizeof(int[MAX_N]));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    struct Pair* sums = my_malloc(n * sizeof(struct Pair));
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += A[j][i];
        }
        sums[i].sum = sum;
        sums[i].index = i;
    }

    quicksort(sums, 0, n-1);

    int (*B)[MAX_N] = my_malloc(m * sizeof(int[MAX_N]));
    my_calloc(n, m, B);
    for (int k = 0; k < n; k++) {
        int i = sums[k].index;
        for (int j = 0; j < m; j++) {
            B[j][k] = A[j][i];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++) {
        my_free(A[i]);
        my_free(B[i]);
    }

    return 0;
}
