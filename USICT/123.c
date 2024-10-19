/*Yash Mishra
Decimal to Binary*/

#include <stdio.h>


int decitobin(int number)
{
    int j =0;
    int lst[32];
    while(number>0)
    {
        lst[j] = number%2;
        number = number/2;
        j++;
    }
    printf("In Binary- ");
    //We need to start the loop from j - 1 as otherwise it prints bogus values from the index outside of the desired range :(
    for(int i = j-1; i>=0; i--)
    {
        printf("%d",lst[i]);
    }
    printf("\n");
    return 0;
}

int main(void)
{
    int deci = 0;
    printf("Enter the decimal number - ");
    scanf("%d", &deci);
    decitobin(deci);
}
