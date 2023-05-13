#include <stdio.h>

#define MAX_RECTANGLES 100000

int main() {
    int rows, cols;
    scanf("%d%d", &rows, &cols);

    char grid[rows][cols];
    for (int i = 0; i < rows; i++) {
        scanf("%s", grid[i]);
    }

    int count = 0;
    int perimeters[MAX_RECTANGLES];

    for (int r1 = 0; r1 < rows; r1++) {
        for (int c1 = 0; c1 < cols; c1++) {
            for (int r2 = r1; r2 < rows; r2++) {
                for (int c2 = c1; c2 < cols; c2++) {
                    int valid = 1;
                    for (int r = r1; r <= r2 && valid; r++) {
                        for (int c = c1; c <= c2 && valid; c++) {
                            if (grid[r][c] == 'X') {
                                valid = 0;
                            }
                        }
                    }
                    if (valid) {
                        int perimeter = 2 * ((r2 - r1) + (c2 - c1) + 2);
                        perimeters[count] = perimeter;
                        count++;
                    }
                }
            }
        }
    }
    int key=perimeters[0];
    for (int i = 1; i < count; i++) {
        if (perimeters[i]>key){
            key=perimeters[i];
        }
    }
    if(key==0){
        printf("%d",0);
    }
    else{
    printf("%d",key-1);
    }
    return 0;
}
