#include <stdio.h>
#include <cs50.h>

int main()
{
    int n;
    do {
        eprintf("I'm about to get a positive number\n");
        n = get_int("Positive Number: ");
    } while (n <= 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}