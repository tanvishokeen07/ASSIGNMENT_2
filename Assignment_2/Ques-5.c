#include <stdio.h>

long long gcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    if (b == 0) {
        return a;           /* base case */
    }
    return gcd(b, a % b);   /* same rule: (a, b) -> (b, a % b) */
}

int main(void) {
    long long a, b;

    if (scanf("%lld %lld", &a, &b) != 2) {
        return 1;
    }

    printf("%lld\n", gcd(a, b));
    return 0;
}