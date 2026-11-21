#include <stdio.h>

long long countMultiples(long long n, long long k) {
    if (k <= 0 || n < 1) {
        return 0;  /* no positive integers in range, or invalid k */
    }
    return n / k;
}

int main(void) {
    long long n, k;

    if (scanf("%lld %lld", &n, &k) != 2) {
        return 1;  /* invalid or missing input */
    }

    printf("%lld\n", countMultiples(n, k));
    return 0;
}