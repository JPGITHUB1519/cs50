#include <stdio.h>

int main()
{
    int height;
    int actualSpaces;

    do {
        printf("Height: ");
        scanf("%d", &height);
    } while (height < 0 || height > 23);
    
    actualSpaces = height - 1;

    for (int i = 1; i <= height; i++) {
        // print the spaces on the pyramid. 
        /*
            spaces = spaces - actual row
        */
        for (int j = 1; j <= actualSpaces; j++)
        {
            printf(" ");
        }
        actualSpaces--;
        // pyramid blocks
        for (int k = 1; k <= i; k++) {
            printf("#");
        }

        printf("  ");

        // second pyramid
        for (int l = 1; l <= i;  l++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}