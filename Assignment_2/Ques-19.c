#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r, c;

    if (scanf("%d %d", &r, &c) != 2 || r < 0 || c < 0) {
        return 1;  /* invalid or missing input */
    }

    if (r == 0 || c == 0) {
        printf("0\n");
        return 0;
    }

    long long *m = malloc((size_t)r * (size_t)c * sizeof(long long));
    if (m == NULL) {
        return 1;  /* allocation failed */
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%lld", &m[(size_t)i * c + j]) != 1) {
                free(m);
                return 1;  /* fewer values than promised */
            }
        }
    }

    /* row and column offsets for up, down, left, right */
    const int di[4] = {-1, 1, 0, 0};
    const int dj[4] = {0, 0, -1, 1};

    long long peaks = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            long long v = m[(size_t)i * c + j];
            int isPeak = 1;

            for (int d = 0; d < 4; d++) {
                int ni = i + di[d];
                int nj = j + dj[d];

                if (ni < 0 || ni >= r || nj < 0 || nj >= c) {
                    continue;  /* missing neighbour is ignored */
                }
                if (v <= m[(size_t)ni * c + nj]) {
                    isPeak = 0;  /* neighbour is equal or larger */
                    break;
                }
            }

            if (isPeak) {
                peaks++;
            }
        }
    }

    printf("%lld\n", peaks);

    free(m);
    return 0;
}