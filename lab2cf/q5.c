#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
 
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
 
    int ishu = 0;
    int rohu = 0;
    int count = 1;
 
    int *deque = malloc(k * sizeof(int));
    int front = 0, rear = -1;
 
    for (int i = 0; i < n; i++) {
        while (front <= rear && deque[front] < i - k + 1) {
            front++;
        }
 
        while (front <= rear && arr[deque[rear]] < arr[i]) {
            rear--;
        }
 
        deque[++rear] = i;
 
 
        if (i >= k - 1) {
            if (count == 1) {
                ishu += arr[deque[front]];
                count = 2;
            } else {
                rohu += arr[deque[front]];
                count = 1;
            }
        }
    }
 
    free(deque);
 
    if (ishu > rohu) {
        printf("ishu");
    } else if (rohu > ishu) {
        printf("rohu");
    } else {
        printf("draw");
    }
 
    return 0;
}