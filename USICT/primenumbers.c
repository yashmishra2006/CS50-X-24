#include <stdio.h>
#include <math.h>
int main()
{
double number;
printf("insert the number that u want converted:(base 10):");
scanf("%lf", &number);
int base;
printf("chose the base of the new number: ");
scanf("%d", &base);
//finding fractional and integral part
int int_part= number;
double frac_part= number-int_part;
printf("%d, %lf\n", int_part, frac_part);
while(int_part>0) //condtn: till quotient is not 0
{
int remainder = int_part % base;
printf("%d", remainder);
int_part=int_part/base; //for finding quotient
}
printf(".");
int a;
double new_frac_part;
while(frac_part>0)
{
new_frac_part = frac_part*2;
int int_new_frac_part = new_frac_part;
printf("%d", int_new_frac_part);
frac_part = new_frac_part - int_new_frac_part;
}
printf("\n");
return 0;
}
