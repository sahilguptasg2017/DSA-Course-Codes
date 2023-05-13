#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_M 100
#define MAX_N 100

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int grid[MAX_M][MAX_N];
    int time[MAX_M][MAX_N];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
            if (grid[i][j] == 1) {
                time[i][j] = 0;
            } else {
                time[i][j] = INT_MAX;
            }
        }
    }

    int* queue = malloc(MAX_M * MAX_N * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                queue[rear++] = i * n + j;
            }
        }
    }

    while (front < rear) {
        int p = queue[front++];

        int i = p / n;
        int j = p % n;

        int di[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dj[] = {0, 0, -1, 1, -1, 1, -1, 1};
        for (int k = 0; k < 8; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 0 && time[ni][nj] == INT_MAX) {
                time[ni][nj] = time[i][j] + 1;
                queue[rear++] = ni * n + nj;
            }
        }
    }

    int max_time = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (time[i][j] < INT_MAX && time[i][j] > max_time) {
                max_time = time[i][j];
            }
        }
    }

    printf("%d\n", max_time);

    free(queue);
    return 0;
}
