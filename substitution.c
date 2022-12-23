#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // makes sure the user entered exactly 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // makes sure the second argument the user entered (the cipher key) is exactly 26 characters long
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // makes sure each character in the key the user entered is unique and not a number
    for (int i = 0; i < strlen(key) - 1; i++)
    {
        if (!((key[i] >= 'A' && key[i] <= 'Z') || (key[i] >= 'a' && key[i] <= 'z')))
        {
            printf("Key must contain only alphabetical characters.\n");
            return 1;
        }

        for (int j = i + 1; j < strlen(key); j++)
        {
            if (toupper(key[j]) == toupper(key[i]))
            {
                printf("Key must contain 26 unique characters.\n");
                return 1;
            }
        }
    }

    // capitalizes all of the characters in the key
    for (int i = 0; i < strlen(key); i++)
    {
        if (islower(key[i]))
        {
            key[i] = toupper(key[i]);
        }
    }

    // asks the user for the plaintext they want to be encrypted
    string plaintext = get_string("plaintext: ");

    // prints the encrypted version of the plaintext
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        // substitutes capital letters in the plaintext to the encrypted version of capital letters
        if (isupper(plaintext[i]))
        {
            int  index = plaintext[i] - 'A';
            printf("%c", key[index]);
        }

        // substitutes capital letters in the plaintext to the encrypted version of capital letters
        else if (islower(plaintext[i]))
        {
            int index = (plaintext[i] - 32) - 'A';
            printf("%c", tolower(key[index]));
        }

        // prints spaces
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}