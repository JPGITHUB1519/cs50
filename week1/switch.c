#include <stdio.h>

int main()
{
    char answer;
    printf("Answer: \n");
    scanf("%c", &answer);

    switch (answer) {
        case 'y':
        case 'Y':
            printf("Yes\n");
            break;
        case 'n':
        case 'N':
            printf("Not\n");
            break;
        default:
            printf("Invalid answer\n");
            break;
    }
}