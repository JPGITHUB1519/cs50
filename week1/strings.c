#include <stdio.h>

int main()
{
    char name[20];
    printf("Enter a name: \n");
    // safest weay t oread string
    fgets(name, sizeof(name), stdin);
    printf("Your name is %s: \n", name);


    printf("Enter your name again: ");
    fgets(name, sizeof(name), stdin);
    return 0;
}