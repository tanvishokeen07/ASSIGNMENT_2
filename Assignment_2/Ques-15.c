#include <stdio.h>

int main(void) {
    int ch;
    int prev = EOF;      /* character of the current run */
    long long run = 0;   /* length of the current run */

    while ((ch = getchar()) != EOF && ch != '\n' && ch != '\r') {
        if (ch == prev) {
            run++;                       /* run continues */
        } else {
            if (prev != EOF) {
                printf("%c%lld", prev, run);  /* emit the finished run */
            }
            prev = ch;                   /* start a new run */
            run = 1;
        }
    }

    if (prev != EOF) {
        printf("%c%lld", prev, run);     /* emit the final run */
    }
    printf("\n");
    return 0;
}