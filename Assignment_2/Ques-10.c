#include <stdio.h>

int main(void) {
    long long N;

    if (scanf("%lld", &N) != 1) {
        return 1;  /* invalid or missing input */
    }

    int found = 0;

    for (long long a = 1; a <= N; a++) {
        for (long long b = a + 1; b <= N; b++) {
            long long sum = a * a + b * b;

            /* c must be greater than b and at most N */
            for (long long c = b + 1; c <= N; c++) {
                long long sq = c * c;
                if (sq == sum) {
                    printf("%lld %lld %lld\n", a, b, c);
                    found = 1;
                    break;
                }
                if (sq > sum) {
                    break;  /* c only grows, no match possible */
                }
            }
        }
    }

    if (!found) {
        printf("None\n");
    }
    return 0;
}