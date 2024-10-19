#include <stdio.h>

#include <cs50.h>
#include <ctype.h>
#include <string.h>
int score(string x);
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int main(void)
{
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");
    if (score(p1) > score(p2))
    {
        printf("Player 1 wins!\n");
    }
    else if (score(p1) < score(p2))
    {
        printf("Player 2 wins!\n");
    }
    else
        (printf("Tie!\n"));
}
int score(string x)
{
    int sum = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (toupper(x[i]) - 65 >= 0)
        {
            sum = sum + points[toupper(x[i]) - 65];
        }
        else
            break;
    }
    return sum;
}
