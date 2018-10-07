#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

/*
    Ascii values

    Uppercase
        A = 65  - Z = 90
    
    Lowercase
        a = 97 -  z = 122
*/
const int ALPHATBETNUMBERS = 26;
const int AUPPERASCII = 65;
const int ZUPPERASCII = 90;
const int ALOWERASCII = 97;
const int ZLOWERASCII = 122;

/* Checks if a character is a valid alphabet char (A - Z) or (a - z) */
int checkValidAlphabet(char character) {
    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
        return 1;
    }

    return 0;
}

/* Encrypts a character using Caesar algorithm */
char encryptCharacter(char character, int key)
{
    int asciiValue = (int) character;
    char encryptedCharacter;

    if (checkValidAlphabet(character)) {
        asciiValue = asciiValue + (key % ALPHATBETNUMBERS);

        if (isupper(character)) {
            if (asciiValue > ZUPPERASCII) {
                asciiValue = asciiValue - (ALPHATBETNUMBERS);
            }
        } else {
            if (asciiValue > ZLOWERASCII) {
                asciiValue = asciiValue - (ALPHATBETNUMBERS);
            }
        }

        return asciiValue;
    } else {
        return character;
    } 
}

/* Encrypts a string using Caesar algorithm */
string encryptString(string plainText, int key) 
{
    for (int i = 0; i < strlen(plainText); i++) {
        plainText[i] = encryptCharacter(plainText[i], key);
    }

    return plainText;
}

int main(int argc, string argv[])
{
    if (argc < 2) {
        printf("No arguments supplied\n");
        return 1;
    } else if (atoi(argv[1]) < 0) {
        printf("Invalid argument supplied: argument must be a non-negative number\n");
        return -1;
    } else {
        int key;
        string plainText = get_string("plaintext: ");
        key = atoi(argv[1]);

        plainText = encryptString(plainText, key);

        printf("ciphertext: %s\n", plainText);
        return 0;
    }    
}