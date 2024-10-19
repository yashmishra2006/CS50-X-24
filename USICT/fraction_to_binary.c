/*
YASH MISHRA
CSE AI
*/

#include <stdio.h>
int main(void)
{
    int lst[32];
    int intpart, i=0, j=0, fracnum;
    double number, fracpart, fracnew;
    printf("Enter a fractional number - ");
    scanf("%lf",&number);
    intpart = (int) number;
    fracpart = number - intpart;

    //integer part
    while(intpart>0)
    {
        lst[j] = intpart%2;
        intpart = intpart/2;
        j++;
    }

    for(int l = j-1; l>=0; l--)
    {
        printf("%d",lst[l]);
    }

    printf(".");

    for(int k=0; k<5; k++)
    {
        fracnew = fracpart * 2;
        fracnum = (int) fracnew;
        fracpart = (fracnew) - (int)fracnew;
        printf("%d", fracnum);
    }
    printf("\n");

}
