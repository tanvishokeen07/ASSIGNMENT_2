#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r, c;

    if (scanf("%d %d", &r, &c) != 2 || r < 0 || c < 0) {
        return 1;  /* invalid or missing input */
    }

    long long *rowSum = calloc((size_t)(r > 0 ? r : 1), sizeof(long long));
    long long *colSum = calloc((size_t)(c > 0 ? c : 1), sizeof(long long));
    if (rowSum == NULL || colSum == NULL) {
        free(rowSum);
        free(colSum);
        return 1;  /* allocation failed */
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            long long x;
            if (scanf("%lld", &x) != 1) {
                free(rowSum);
                free(colSum);
                return 1;  /* fewer values than promised */
            }
            rowSum[i] += x;
            colSum[j] += x;
        }
    }

    for (int i = 0; i < r; i++) {
        printf("%lld%c", rowSum[i], i + 1 < r ? ' ' : '\n');
    }
    if (r == 0) printf("\n");

    for (int j = 0; j < c; j++) {
        printf("%lld%c", colSum[j], j + 1 < c ? ' ' : '\n');
    }
    if (c == 0) printf("\n");

    free(rowSum);
    free(colSum);
    return 0;
}