#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string cipherer(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error: Invalid Input\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Invalid Length of Key\n");
        return 1;
    }

    char ch[27];
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Invalid Key\n");
            return 1;
        }
        ch[i] = tolower(argv[1][i]);
    }
    ch[26] = '\0';
    string key = ch;

    for (int k = 0; k < 26; k++)
    {
        for (int l = k + 1; l < 26; l++)
        {
            if (key[k] == key[l])
            {
                printf("Invalid Key: Multiple Similar Characters\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: %s\n", cipherer(plaintext, key));

    return 0;
}

string cipherer(string plaintext, string key)
{
    int length = strlen(plaintext);
    static char ciphe[1000];

    for (int i = 0; i < length; i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphe[i] = toupper(key[plaintext[i] - 'A']);
        }
        else if (islower(plaintext[i]))
        {
            ciphe[i] = tolower(key[plaintext[i] - 'a']);
        }
        else
        {
            ciphe[i] = plaintext[i];
        }
    }
    ciphe[length] = '\0';

    return ciphe;
}
