#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    char matrix[m][n+1];
    for (int i = 0; i < m; i++) {
        scanf("%s", matrix[i]);
    }

    int heights[m][n];
    memset(heights, 0, sizeof(heights));
    for (int j = 0; j < n; j++) {
        heights[0][j] = (matrix[0][j] == '.') ? 1 : 0;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            heights[i][j] = (matrix[i][j] == '.') ? 1 + heights[i-1][j] : 0;
        }
    }

    int max_perimeter = 0;
    for (int i = 0; i < m; i++) {
        int stack[n+1], top = -1;
        for (int j = 0; j <= n; j++) {
            int height = (j == n) ? 0 : heights[i][j];
            while (top >= 0 && height < heights[i][stack[top]]) {
                int h = heights[i][stack[top--]];
                int w = (top < 0) ? j : j - stack[top] - 1;
                max_perimeter = max(max_perimeter, 2*(h+w));
            }
            stack[++top] = j;
        }
    }
    if(max_perimeter==0){
        printf("%d\n",0);
    }
    else{
        printf("%d\n", max_perimeter-1);
    }
    return 0;
}
