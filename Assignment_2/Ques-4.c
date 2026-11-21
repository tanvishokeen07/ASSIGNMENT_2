#include <stdio.h>

int isPerfectSquare(long long n) {
    if (n < 0) {
        return 0;  /* negatives are never perfect squares */
    }

    long long low = 0;
    long long high = 3037000499LL;  /* largest i with i*i <= LLONG_MAX */

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long sq = mid * mid;

        if (sq == n) {
            return 1;
        } else if (sq < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

int main(void) {
    long long n;

    if (scanf("%lld", &n) != 1) {
        return 1;  /* invalid or missing input */
    }

    printf("%d\n", isPerfectSquare(n));
    return 0;
}