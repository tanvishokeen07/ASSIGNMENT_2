#include <stdio.h>
#include <stdlib.h>

int digitSum(long long x) {
    if (x < 0) x = -x;  /* ignore sign, just in case */

    int sum = 0;
    while (x > 0) {
        sum += (int)(x % 10);
        x /= 10;
    }
    return sum;
}

long long countEqualDigitSumPairs(const int sums[], int n) {
    long long count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sums[i] == sums[j]) {
                count++;
            }
        }
    }
    return count;
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

    int *sums = malloc((size_t)n * sizeof(int));
    if (sums == NULL) {
        return 1;  /* allocation failed */
    }

    for (int i = 0; i < n; i++) {
        long long value;
        if (scanf("%lld", &value) != 1) {
            free(sums);
            return 1;  /* fewer values than promised */
        }
        sums[i] = digitSum(value);
    }

    printf("%lld\n", countEqualDigitSumPairs(sums, n));

    free(sums);
    return 0;
}