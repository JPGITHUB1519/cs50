#include <stdio.h>

int main()
{
    char answer;
    printf("Answer: \n");
    scanf("%c", &answer);

    if (answer == 'y' || answer == 'Y') {
        printf("Yes\n");
    } else if (answer == 'n' || answer == 'N') {
        printf("No\n");
    } else {
        printf("Invalid answer\n");
    }
    return 0;
}
