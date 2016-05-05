/***************************************************************************
*  Programmers and Purdue Email Addresses:
*	 1. steppt@purdue.edu
*	 2. ddecarde@purdue.edu
*	 3. hu234@purdue.edu (delete line if no third partner)
*
*  Lab #:09
*
*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access 
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section: div 08 sec 01
*
*  Program Description:Given a non-negative int, remove adjacent pairs of digits that are the same and display the new number.
***************************************************************************/

#include <stdio.h>
#include <math.h>

long long int getinput();
int getlast(long long int);
int getnext(long long int);
void createnew(long long int);
int getlength(long long int);

int main(void)
{
  long long int input;
  input = getinput();
  createnew(input);
  return(0);
}
long long int getinput()
{
  long long int input;
  do
  {  
    printf("\nEnter your non-negative integer:");
    scanf(" %lld", &input);
    if (input < 0)
    {
      printf("\nError! Non-negative values only!\n\n");
    }
  }while(input < 0);

return(input);
}
int getlast(long long int input)
{
  int last;
  last = input % 10;
  return(last);
}
int getnext(long long int input)
{
  int next;
  next = (input % 100) / 10;
  return(next);
}
int getlength(long long int number)
{
  int ct = 0;
  while (number != 0)
  {  
    number /= 10;
    ct++;
  }
  return(ct);
}
void createnew(long long int input)
{
  int last;
  int next;
  long long int new;
  int number = 0;
  int ct = 1;
  int length;
  int control = 1;
  do
  {  
    last = getlast(input);
    next = getnext(input);
     
    if (next == last)
      {
        new = input / 100;
        length = getlength(number);
        new = (new * pow(10, length)) + number;
        printf("After change #%d: %lld\n", ct++, new);
        input = new;
        number = 0;
      }
    else
    {
      if (number == 0)
      {
        number = input % 10;
      }
      else
      {  
        number += (input % 10) * pow(10, control);
        control++;
      }
      input = input / 10;
    }  
  }
  while(input != 0); 
}

