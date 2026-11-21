#include <stdio.h>
#include <stdlib.h>

int longestIncreasingRun(const long long arr[], int n) {
    if (n <= 0) {
        return 0;
    }

    int best = 1;
    int current = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            current++;          /* run continues */
        } else {
            current = 1;        /* run broken (equal or smaller), restart */
        }

        if (current > best) {
            best = current;
        }
    }
    return best;
}

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;  /* invalid or missing input */
    }

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    long long *arr = malloc((size_t)n * sizeof(long long));
    if (arr == NULL) {
        return 1;  /* allocation failed */
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &arr[i]) != 1) {
            free(arr);
            return 1;  /* fewer values than promised */
        }
    }

    printf("%d\n", longestIncreasingRun(arr, n));

    free(arr);
    return 0;
}