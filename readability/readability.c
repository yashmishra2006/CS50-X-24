#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int count_letters(string x);
int count_words(string x);
int count_sentances(string x);
int main(void)
{
    string text = get_string("Text: ");
    int L = round(count_letters(text)/count_words(text) * 100);
    int S = round(count_sentances(text)/count_words(text) * 100);
    int index = 0.0588 * L - 0.296 * S - 15.8;
    if(index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(index<1)
    {
        printf("Before Grade 1\n");
    }
    else printf("Grade %i\n",index);
}

int count_letters(string x)
{
    int count = 0;
    for(int i = 0; i<strlen(x); i++)
    {
        if(isalpha(x[i])!=0)
        {
            count++;
        }
    }
    return count;
}

int count_words(string x)
{
    float count = 1;
    for(int i = 0; i<strlen(x); i++)
    {
        if(isspace(x[i])!=0)
        {
            count++;
        }
    }
    return count;
}

int count_sentances(string x)
{
    float count = 0;
    for(int i = 0; i<strlen(x); i++)
    {
        if(ispunct(x[i])!=0)
        {
            count++;
        }
    }
    return count;
}
