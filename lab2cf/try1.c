#include <stdio.h>

#define MAX_N 100000

int n, k, arr[MAX_N];
int deque[MAX_N], front = 0, rear = -1;

void push(int index) {
    while (rear >= front && arr[index] >= arr[deque[rear]]) {
        rear--;
    }
    rear++;
    deque[rear] = index;
}

void pop() {
    if (deque[front] == front) {
        front++;
    }
}

int peek() {
    return deque[front];
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ishu = 0, rohu = 0, count = 0;
    for (int i = 0; i < n; i++) {
        push(i);
        if (i >= k - 1) {
            int max_index = peek();
            if (count % 2 == 0) {
                ishu += arr[max_index];
            } else {
                rohu += arr[max_index];
            }
            count++;
            pop();
        }
    }

    if (ishu > rohu) {
        printf("ishu");
    } else if (rohu > ishu) {
        printf("rohu");
    } else {
        printf("draw");
    }

    return 0;
}
