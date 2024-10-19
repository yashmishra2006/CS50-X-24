
#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int n;
    do
    {
        n = get_int("Enter height of tower - ");
    }
    while (n < 1 || n > 8);
    int m = 0;
    int s = n - 1;
    for (int i = 0; i < n; i++)
    {
        m = m + 1;
        s = s - 1;
        for (int space = 0; space <= s; space++)
            printf(" ");
        for (int j = 0; j < m; j++)
            printf("#");
        printf("  ");
        for (int j = 0; j < m; j++)
            printf("#");
        printf("\n");
    }
}
