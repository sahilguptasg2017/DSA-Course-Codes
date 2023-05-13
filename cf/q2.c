    #include <stdio.h>

    int f(int m, int n) {
        int list_1[100000] = {0}, list_2[100000] = {0};
        int i, j, count = 0;

        if (m > n) {
            return 0;
        } else {
            if (n == (3 * m / 2) || n == 3 * m || n == m) {
                return 1;
            } else {
                list_1[0] = n;
                while (list_1[count] > m) {
                    for (i = 0, j = 0; i <= count; i++) {
                        list_2[j++] = list_1[i] / 3;
                        list_2[j++] = (2 * list_1[i]) / 3;
                    }
                    count = j - 1;
                    for (i = 0; i <= count; i++) {
                        list_1[i] = list_2[i];
                    }
                    if (m == list_1[count]) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    
    int main() {
        int t, m, n;
        scanf("%d", &t);

        while (t--) {
            scanf("%d %d", &n, &m);
            printf("%s\n", f(m, n) ? "YES" : "NO");
        }

        return 0;
    }
