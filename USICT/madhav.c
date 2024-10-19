#include <stdio.h>
int main(void){
    int num1 =0;
    int num2 =0;
    printf("enter how many numbers you wanna enter - ");
    scanf("%d", &num1);
    for(int i=1 ; i<num1 ; i+=1){
    printf("Enter number to print\n");
    scanf("%d", &num2);
    printf("your number is %d \n",num2);
    }
}
