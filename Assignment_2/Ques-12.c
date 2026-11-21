#include <stdio.h>
#include <stdlib.h>

long long minDifference(const long long arr[], int n) {
    long long best = -1;  /* -1 means "not set yet" */

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long diff = arr[i] - arr[j];
            if (diff < 0) diff = -diff;

            if (best == -1 || diff < best) {
                best = diff;
            }
        }
    }
    return best;
}

int main(void) {
    int n;

    if (scanf("%d", &n) != 1 || n < 2) {
        return 1;  /* need at least two values to form a pair */
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

    printf("%lld\n", minDifference(arr, n));

    free(arr);
    return 0;
}