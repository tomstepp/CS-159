/***************************************************************************
*  Programmers and Purdue Email Addresses:
*	 1. steppt@purdue.edu
*	 2. tthystru@purdue.edu
*	 3. li1210@purdue.edu (delete line if no third partner)
*
*  Lab #: 07
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
*  Program Description: given an integer, display the cardinality of the number and find the next number that is greater and has a higher cardinality of that value input by the user.
***************************************************************************/
#include <stdio.h>
#include <math.h>

int getvalue(); //receives integer value from user
int calccardinality(int); //calculates cardinality of value
int largervalue(int, int); //find first value larger than input with a greater cardinality
int display(int, int, int); // displays output

int main(void)
{
  int value; //user input value
  int cardinality; //cardinality of user input
  int nextvalue; //next value with larger cardinality

  value = getvalue();
  cardinality = calccardinality(value);
  nextvalue = largervalue(value, cardinality);
  display(value, cardinality, nextvalue);
  return(0);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:get value
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.value //user input
*
*     Function Description: recieve value from user
****************************************************************************/
int getvalue(void)
{
  int value; //user input value
  printf("\nEnter a non-negative integer value: ");
  scanf("%d", &value);
  return(value);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: calccardinality
*
*     Programmer's Name:Tom stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int input //user input
*       2.int x //binary number
*       3.int cardinality //cardinality of input
*
*     Function Description: calcualte the cardinality of input
***************************************************************************/
int calccardinality(int input)
{
  int x; //binary number
  int cardinality; //cardinality of user input
  for(cardinality = 0; input > 0; input /= 2)
  {
    x = input % 2;
    cardinality += x;
    x = 0;
  }
  return(cardinality);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:larger value
*
*     Programmer's Name:Tom stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int value //input
*       2.int cardinality //cardinality of input
*       3.int nextvalue //first value with larger input
*       4.int nextcardinality //cardinality of nextvalue
*
*     Function Description: find the next value with larger cardinality
***************************************************************************/
int largervalue(int value, int cardinality)
{
  int nextvalue;
  int nextcardinality;
  nextvalue = value;

  for(nextcardinality = 0; nextcardinality != cardinality + 1; nextvalue++)
  {
    nextcardinality = calccardinality(nextvalue);
  }
  nextvalue -= 1;
  return(nextvalue);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: display
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int value //input
*       2.int cardinality //cardinality of input
*       3.int nextvalue //first value with larger cardinality
*
*     Function Description:display results
***************************************************************************/
int display(int value, int cardinality, int nextvalue)
{
  printf("\nValue input: %d", value);
  printf("\nCardinality: %d", cardinality);
  printf("\nFirst value larger than input with a greater cardinality: %d\n\n", nextvalue);
  return(0);
}

