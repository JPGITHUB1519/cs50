#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
    string s = get_string("Name: ");
    for (int i = 0; i < strlen(s); i++) {
        printf("%c %d\n", s[i], (int) s[i]);
    }
    return 0;
}