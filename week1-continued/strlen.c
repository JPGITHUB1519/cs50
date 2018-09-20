#include <cs50.h>
#include <stdio.h>

int main()
{
    string s = get_string("String: ");
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    printf("%i\n", n);
}