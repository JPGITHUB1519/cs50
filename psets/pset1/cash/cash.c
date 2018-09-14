#include <stdio.h>
#include <math.h>
#include <cs50.h>

const int quarter = 25;
const int dime = 10;
const int nicker = 5;
const int penny = 1;

int greedyCoins(int change) 
{
    if (change >= quarter) {
        change = change - quarter;
    } else if (change >= dime) {
        change = change - dime;
    } else if (change >= nicker) {
        change = change - nicker;
    } else if (change >= penny) {
        change = change - penny;
    }

    return change;
}

int convertDollarsToCents(float dollars)
{
    // C autotruncate float part
    // 41.00 -> 41
    int cents = roundf(dollars * 100);
    return cents;
}

int main()
{
    int totalCoins = 0;
    float change;
    do {
        change = get_float("Change owed: ");
    } while (change < 0);

    int changeInCents = convertDollarsToCents(change);

    while (changeInCents > 0) {
        changeInCents = greedyCoins(changeInCents);
        totalCoins++;
    } 

    printf("%d\n", totalCoins);
    return 0;
}
