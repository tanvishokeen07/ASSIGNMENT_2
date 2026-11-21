#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r, c;

    if (scanf("%d %d", &r, &c) != 2 || r < 0 || c < 0) {
        return 1;  /* invalid or missing input */
    }

    if (r == 0 || c == 0) {
        printf("None\n");
        return 0;
    }

    long long *m = malloc((size_t)r * (size_t)c * sizeof(long long));
    long long *rowMin = malloc((size_t)r * sizeof(long long));
    long long *colMax = malloc((size_t)c * sizeof(long long));
    if (m == NULL || rowMin == NULL || colMax == NULL) {
        free(m);
        free(rowMin);
        free(colMax);
        return 1;  /* allocation failed */
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%lld", &m[(size_t)i * c + j]) != 1) {
                free(m);
                free(rowMin);
                free(colMax);
                return 1;  /* fewer values than promised */
            }
        }
    }

    /* minimum of each row */
    for (int i = 0; i < r; i++) {
        rowMin[i] = m[(size_t)i * c];
        for (int j = 1; j < c; j++) {
            if (m[(size_t)i * c + j] < rowMin[i]) rowMin[i] = m[(size_t)i * c + j];
        }
    }

    /* maximum of each column */
    for (int j = 0; j < c; j++) {
        colMax[j] = m[j];
        for (int i = 1; i < r; i++) {
            if (m[(size_t)i * c + j] > colMax[j]) colMax[j] = m[(size_t)i * c + j];
        }
    }

    /* first row-major cell that is both */
    int found = 0;
    for (int i = 0; i < r && !found; i++) {
        for (int j = 0; j < c; j++) {
            long long v = m[(size_t)i * c + j];
            if (v == rowMin[i] && v == colMax[j]) {
                printf("%d %d %lld\n", i, j, v);  /* 0-based indices */
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("None\n");
    }

    free(m);
    free(rowMin);
    free(colMax);
    return 0;
}