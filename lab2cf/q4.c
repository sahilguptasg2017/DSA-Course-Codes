#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
typedef struct {
    int r;
    int c;
    int t;
} s1;
 
int time(int m, int n, int **matrix) {
    s1 *queue = (s1*) malloc(m * n * sizeof(s1));
    int front = 0, rear = 0;
    int max_time = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                queue[rear++] = (s1) {i, j, 0};
            }
        }
    }
    while (front != rear) {
        s1 temp1 = queue[front++];
        max_time = temp1.t;
        
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue;
                int r = temp1.r + dr;
                int c = temp1.c + dc;
                if (r >= 0 && r < m && c >= 0 && c < n && matrix[r][c] == 0) {
                    matrix[r][c] = 1;
                    queue[rear++] = (s1) {r, c, temp1.t+1};
                }
            }
        }
    }
    
    free(queue);
    return max_time;
}
 
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int **matrix = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int t2 = time(m, n, matrix);
    printf("%d\n", t2);
    
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}