#include <stdio.h>

void convertSeconds(long long total, long long *h, long long *m, long long *s) {
    *h = total / 3600;
    *m = (total % 3600) / 60;
    *s = total % 60;
}

int main(void) {
    long long total, h, m, s;

    if (scanf("%lld", &total) != 1) {
        return 1;  /* invalid or missing input */
    }

    if (total < 0) {
        return 1;  /* negative duration is not meaningful */
    }

    convertSeconds(total, &h, &m, &s);
    printf("%lld %lld %lld\n", h, m, s);
    return 0;
}