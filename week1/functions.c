#include <stdio.h>

int square(int n);

int main() 
{
    int x;
    printf("x: ");
    scanf("%d", &x);
    printf("\n The square of x is %d\n", square(x));


    return 0;
}

int square(int n)
{
    return n * n;
}