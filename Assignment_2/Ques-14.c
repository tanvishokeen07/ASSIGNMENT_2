#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch;
    long long vowels = 0, consonants = 0, digits = 0, spaces = 0;

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (isalpha(ch)) {
            char lower = (char)tolower(ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' ||
                lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(ch)) {
            digits++;
        } else if (ch == ' ') {
            spaces++;
        }
        /* anything else (punctuation, tabs, '\r') is ignored */
    }

    printf("%lld %lld %lld %lld\n", vowels, consonants, digits, spaces);
    return 0;
}