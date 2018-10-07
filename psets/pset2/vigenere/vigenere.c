#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

/* ############# Alphabet Constant  #################*/
const int ALPHATBETNUMBERS = 26;
const int AUPPERASCII = 65;
const int ZUPPERASCII = 90;
const int ALOWERASCII = 97;
const int ZLOWERASCII = 122;

/* ############# Caesar Algorithm  #################*/

/* Encrypts a character using Caesar algorithm */
char encryptCharacter(char character, int key)
{
    int asciiValue = (int) character;
    char encryptedCharacter;

    if (isalpha(character)) {
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

/* Check if all the character of a string is a alphabet letter */
int isAlphaString(string text) {
    for (int i = 0; i < strlen(text); i++) {
        if (!isalpha(text[i])) {
            return 0;
        }
    }

    return 1;
}

/*  
    Get the letter position number in the alphabet starting by 0
    IE -> Treating A and a as 0, B and b as 1, …​ , and Z and z as 25. *

    A	B	C	D	E	F	G	H	I	 J	 K	 L	 M	 N	 O	 P	 Q	 R	 S	 T	 U	 V	 W	 X	 Y	 Z
    0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	25

*/
int getLetterValue(char letter) {
    int value;
    if (isupper(letter)) {
        value = 25 - (90 - (int) letter);
    } else {
        value = 25 - (122 - (int) letter);
    }
    return value;
}

/* Encrypts a string using the Vigenère’s cipher */
string encryptVigenere(string plainText, string key)
{
    int mapIndex = 0;
    int mapLetterValue;

    for (int i = 0; i < strlen(plainText); i++) {
        if (mapIndex > strlen(key) - 1) {
            mapIndex = 0;
        }

        if (isalpha(plainText[i]) && plainText[i] != ' ') {
            mapLetterValue = getLetterValue(key[mapIndex]);
            plainText[i] = encryptCharacter(plainText[i], mapLetterValue);
            mapIndex++;
        }
    }
    
    return plainText;
}

int main(int argc, string argv[])
{
    if (argc < 2) {
        printf("No arguments supplied\n");
        return 1;
    } else if (!isAlphaString(argv[1])) {
        printf("The argument must be an alphabet string\n");
        return 1;
    }

    string plainText = get_string("plaintext: ");
    string key = argv[1];
    string cipherText = encryptVigenere(plainText, key);

    printf("ciphertext: %s\n", cipherText);

    return 0;
}