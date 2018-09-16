#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

/* ##### Helpers ##### */

// Get the sum of the digits of a number
int sumDigits(long long number) {
    int n;
    int sum = 0;
    while (number != 0) {
        n = number % 10;
        sum += n;
        number /= 10;
    }

    return sum;
}

// get the number of digits of a number
int getLongLen(long long number) 
{
    int numberOfDigits = log10(number) + 1;
    return numberOfDigits;
}

// get the first digit of a number
int getFirstDigit(long long number) {
    int digits = (int)log10(number);
    int firstDigit = (int) (number / pow(10, digits));
    return firstDigit;
}

// get the two first digit of a number
int getTwoFirstDigit(long long number) {
    char s[25];
    char firstTwoDigitsString[2];
    int firstTwoDigits;
    sprintf(s, "%lld", number);
    sprintf(firstTwoDigitsString, "%c%c", s[0], s[1]);
    firstTwoDigits = atoi(firstTwoDigitsString);
    return firstTwoDigits;
}

// Luhn Algorithm Checker
int checksum(long long creditCardNumber)
{
    int n;
    int doubleN;
    int counter = 1;
    int sumOfSecondsDigits = 0;
    int sumOfOthers = 0;
    int total;
    int checksumResult;

    while (creditCardNumber != 0) {
        n = creditCardNumber % 10;
        doubleN = n * 2;
        if (counter % 2 == 0) {
            // if the number * 2 is greater than 9, sum de digits
            if (doubleN > 9) {
                sumOfSecondsDigits += sumDigits(doubleN);
            } else {
                sumOfSecondsDigits += doubleN;
            }
            
        } else {
            sumOfOthers += n;
        }
        creditCardNumber /= 10;
        counter++;
    }

    total = sumOfSecondsDigits + sumOfOthers;
    checksumResult = (total % 10 == 0) ? 1 : 0;
    return checksumResult;
}

// Get the credit card type (VISA, MASTERCARD, AMEX, INVALID)
char * getCreditCardType(long long creditCardNumber)
{
    int numberOfDigits = getLongLen(creditCardNumber);
    int startDigits;
    char * invalidText = "INVALID\n";

    if (numberOfDigits == 15) {
        startDigits = getTwoFirstDigit(creditCardNumber);
        if (startDigits == 34 || startDigits == 37) {
            return "AMEX";
        } 
    }

    if (numberOfDigits == 16) {
        startDigits = getTwoFirstDigit(creditCardNumber);
        if (startDigits >= 51 && startDigits <= 55) {
            return "MASTERCARD";
        } else {
            startDigits = getFirstDigit(creditCardNumber);
            if (startDigits == 4) {
                return "VISA";
            }
        }
    }

    if (numberOfDigits == 14 || numberOfDigits == 15) 
    {
        startDigits = getTwoFirstDigit(creditCardNumber);
        if (startDigits == 4) {
            return "VISA";
        }
    }

    return invalidText;
}

/**
 * Validates a creditCardNumber
 * 
 * return string cardType(MASTERCARD, VISA, INVALID)
*/
char * validateCreditCard(long long creditCardNumber)
{
    char * cardType = getCreditCardType(creditCardNumber);
    char * invalidCreditCartText = "INVALID";
    int validChecksum;
    int isValidCreditCardType = strcmp(cardType, invalidCreditCartText) != 0;
    int isValidCreditCard = 0;

    if (isValidCreditCardType) {
        validChecksum = checksum(creditCardNumber);
        if (validChecksum) {
            isValidCreditCard = 1;  
        }
    }

    return isValidCreditCard ? cardType : invalidCreditCartText;
}

int main()
{
    long long creditCardNumber = get_long_long("Number: ");
    char * creditCardValidationResult = validateCreditCard(creditCardNumber);

    printf("%s\n", creditCardValidationResult);
}
