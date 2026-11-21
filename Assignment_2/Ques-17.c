#include <stdio.h>
#include <stdlib.h>

int isSymmetric(long long **m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m[i][j] != m[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;  /* invalid or missing input */
    }

    long long **m = malloc((size_t)(n > 0 ? n : 1) * sizeof(long long *));
    if (m == NULL) {
        return 1;  /* allocation failed */
    }

    for (int i = 0; i < n; i++) {
        m[i] = malloc((size_t)n * sizeof(long long));
        if (m[i] == NULL) {
            for (int k = 0; k < i; k++) free(m[k]);
            free(m);
            return 1;
        }
        for (int j = 0; j < n; j++) {
            if (scanf("%lld", &m[i][j]) != 1) {
                for (int k = 0; k <= i; k++) free(m[k]);
                free(m);
                return 1;  /* fewer values than promised */
            }
        }
    }

    printf("%s\n", isSymmetric(m, n) ? "YES" : "NO");

    for (int i = 0; i < n; i++) free(m[i]);
    free(m);
    return 0;
}