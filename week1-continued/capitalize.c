#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main()
{
    string s = get_string("before: ");
    printf("after: ");

    //optimizing strlen caching in a variable
    for (int i = 0, n = strlen(s); i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            printf("%c", s[i] - ('a' - 'A'));
        }
        else {
        printf("%c", s[i]);
        }
    } 
    return 0;
}