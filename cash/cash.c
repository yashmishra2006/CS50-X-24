#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int ch;
    do
    {
        ch = get_int("Change owed: ");
    }
    while (ch < 0);
    int num1 = ch / 25;
    int ch1 = ch % 25;
    int num2 = ch1 / 10;
    int ch2 = ch1 % 10;
    int num3 = ch2 / 5;
    int num4 = ch2 % 5;
    printf("%i\n", num1 + num2 + num3 + num4);
}
