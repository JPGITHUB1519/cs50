#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int num = 321;
    // char snum[5];
    // char twoChars[2];
    // sprintf(snum, "%d\n", num);
    // sprintf(twoChars, "%c%c", snum[0], snum[1]);
    // printf("%c\n", twoChars[0]);

    char s[10] = "321";
    long long n;

    n = atoi(s);

    printf("%lld", n);
}