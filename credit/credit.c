// Take card number from user
#include <stdio.h>
#include <cs50.h>
int sumDoubleCardNumber (int digit);
void checkAMEX(long card);
void checkMC(long card);
int main(void)
{
long cardNumber = get_long("Number: ");

// get the length of the CC Number
int length = 0;
long a = cardNumber; // is going to store the card number
do
{
  a = a/10;
    length ++;
    }
    while(a > 0);

// Check if card length is Valid
if(length != 13 && length != 15 && length != 16)
{
  printf("INVALID\n");
    return 0;
    }
    long x = cardNumber;
    int last;
    int y = 0;
    int sum1;
    int secondToLast;
    int notDoubledSum = 0;
    int doubledSum=0;
    long last2;

    do
    {
      last = x % 10;
        x = x / 10;
          notDoubledSum += last;

            secondToLast = x % 10;
              x = x / 10;
                y = sumDoubleCardNumber(secondToLast);
                  doubledSum = doubledSum + y;
                  }
                  while(x > 0);
                  int addResults = doubledSum + notDoubledSum;


if(addResults % 10 != 0)
{
  printf("INVALID\n");
    return 0;
    }
    if(length == 13)
    {
      printf("VISA\n");
      }
      else if(secondToLast == 4 && length == 16)
      {
        printf("VISA\n");
        }
        else if(length==15)
        {
          checkAMEX(cardNumber);
          }
          else if(length==16)
          {
            checkMC(cardNumber);
            }

            } // END OF MAIN


int sumDoubleCardNumber (int digit)
{
  digit = digit * 2;
    if(digit >= 10)
      {
          digit = 1 + digit % 10;
              return digit;
                }
                return digit;
                }
void checkAMEX(long card)
{
  do
    {
        card = card / 10;
          }
            while(card > 38);
              if(card == 34 || card == 37)
                {
                    printf("AMEX\n");
                        return;
                          }
                            printf("INVALID\n");
                              }

                              void checkMC(long card)
                              {
                                do
                                  {
                                      card = card / 10;
                                        }
                                          while(card > 56);
                                            if(card == 51 || card == 55)
                                              {
                                                  printf("MASTERCARD\n");
                                                      return;
                                                        }
                                                          printf("INVALID\n");
                                                            }

