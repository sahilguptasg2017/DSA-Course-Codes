#include <stdio.h>
#include <math.h>
#define int long long

int calculate_boredom(int ai, int bi, int max_paintings) {
    return bi * (ai - ceil((double)max_paintings / 2));
}

int calculate_paintings_left(int ai, int max_paintings) {
    return fmax(0, ai - max_paintings);
}

void solve() {
    int n, k;
    scanf("%lld %lld", &n, &k);

    int paintings[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &paintings[i]);
    }

    int boredom[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &boredom[i]);
    }

    int left = 1;
    int right = 0;

    for (int i = 0; i < n; i++) {
        right = fmax(right, paintings[i]);
    }

    int max_paintings = 0;
    int total_paintings = 0;
    int total_boredom = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int paintings_left = 0;
        int current_boredom = 0;

        for (int i = 0; i < n; i++) {
            int paintings_seen = fmin(paintings[i], mid);
            int paintings_remaining = calculate_paintings_left(paintings[i], paintings_seen);

            paintings_left += paintings_remaining;
            current_boredom += calculate_boredom(paintings[i], boredom[i], paintings_seen);
        }

        if (paintings_left <= k) {
            max_paintings = mid;
            total_paintings = k - paintings_left;
            total_boredom = current_boredom;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%lld %lld\n", total_paintings, total_boredom);
}

signed main() {
    int t;
    scanf("%lld", &t);

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
