#include <stdio.h>
#include <unistd.h>

int main()
{
    for(int i = 1; ; i *= 2)
    {
        printf("i: %d\n", i);
        sleep(1);
    }
    return 0;
}