#include <cs50.h>
#include <stdio.h>
 int main()
{
    int height;
    int actualSpaces;
     do {
        printf("Height: ");
        height = get_int();
    } while (height < 0 || height > 23);
     actualSpaces = height - 1;
     for (int i = 2; i <= height + 1; i++) {
        // print the spaces on the pyramid.
        /*
            spaces = spaces - actual row
        */
        for (int k = 1; k <= actualSpaces; k++)
        {
            printf(" ");
        }
        actualSpaces--;
        // pyramid blocks
        for (int j = 1; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
} 