#include <stdio.h>
#include <stdlib.h>





void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

int extract_min(int *arr, int *n) {
    int min = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return min;
}



// Function to find the infimum value of K
int find_infimum_capacity(int N, int *goats, int Tu) {
    // Create a min-heap using an array
    int *heap = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        heap[i] = goats[i];
    }
    // Heapify the array
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(heap, N, i);
    }

    int curr_time = 0;
    int K = 1;

    while (N > 0) {
        if (K > N) {
            K = N;
        }

        int eating_time = extract_min(heap, &N);
        curr_time += eating_time;
        K--;

        if (curr_time > Tu) {
            free(heap);
            return K;
        }
    }

    free(heap);
    return K;
}

// Function to heapify the array


// Function to extract the minimum element from the heap

// Function to swap two elements


int main(){
    int n,tu;
    scanf("%d %d",&n,&tu);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int capacity=find_infimum_capacity(n,arr,tu);
    printf("%d",capacity);
    return 0;
}


