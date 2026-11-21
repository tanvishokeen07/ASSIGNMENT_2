#include <stdio.h>
#include <stdlib.h>

long long countPairs(const long long arr[], int n, long long target) {
    long long count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    int n;
    long long target;

    if (scanf("%d %lld", &n, &target) != 2 || n < 0) {
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

    printf("%lld\n", countPairs(arr, n, target));

    free(arr);
    return 0;
}