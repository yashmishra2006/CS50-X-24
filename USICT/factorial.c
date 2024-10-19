#include <stdio.h>

int main(void){

    int num = 0;

    printf("Enter a number - ");
    scanf("%d", &num);
    int mult = num;


    for(int i= num - 1; i>0; i--)
    {
        mult = mult * i;
    }

    printf("The value of factorial is %d\n", mult);
}
