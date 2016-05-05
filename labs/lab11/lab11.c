/***************************************************************************
*	 1. hu234@purdue.edu
*	 2. steppt@purdue.edu
*	 3. ddecarde@purdue.edu (delete line if no third partner)
*
*  Lab #: 11 
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
*  Program Description: compare elements of an array to a value and update the value if they are equal to eachother by adding.
***************************************************************************/
#include <stdio.h>
#include <math.h>
#define SIZE 30 

void getarray(int[]);
int getiterations();
int getvalue();
int newvalue();
int scanarray(int, int[]);
void calculation(int, int, int[]);

int main()
{
  int array[SIZE];//input array
  int index;//number of iterations
  int val;//value being tested

  getarray(array);
  index = getiterations();
  val = getvalue();
  calculation(index, val, array);
  return(0);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:calculation
*
*     Programmer's Name:  Tom Stepp
*
*     Function Return Type: VOID
*
*     Parameters (list data type, name, and comment one per line):
*       1.index// positioning variable
*       2.val// value
*       3.array// inputed array
*
*     Function Description: Prints iterations and changes of value
***************************************************************************/
void calculation(int index, int val, int array[])
{
  int pass;//number of scan iterations

  for(pass = 1; pass < index + 1; pass++)
  {
    val = scanarray(val, array);    
    printf("Value after interations #%d: %d\n", pass, val);
  }
  return;
}
/***************************************************************************
*     Function Information
*
*     Name of Function:scanarray
*
*     Programmer's Name: Tommy Stepp
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. val// value
*       2. array//inputed array
*
*     Function Description: returns new values
***************************************************************************/
int scanarray(int val, int array[])
{
  int i;//index value 
  for(i = 0; i < SIZE; i++)
  {
    if (val == array[i])
    {
      val += array[i];
    }
  }
  return(val);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:getarry
*
*     Programmer's Name:Tom stepp
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int array //list of numbers
*       2.int i //index value
*
*     Function Description:receive array
***************************************************************************/
void getarray(int array[])
{
  int i;//index positioning receptor 
  printf("\nEnter 30 integer values now: ");
  for(i = 0; i < SIZE; i++)
  {
    scanf("%d", &(array[i]));
  }
  return;
}
/***************************************************************************
*     Function Information
*
*     Name of Function : getiterations
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int index //number of iterations
*
*     Function Description: get iteration value
***************************************************************************/
int getiterations()
{
  int index;//number of iterations
  printf("\nEnter desired number of iterations: ");
  scanf("%d", &index);
  return(index);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:getvalue
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int val //starting value
*
*     Function Description: get starting value
***************************************************************************/
int getvalue()
{
  int val;//starting value
  printf("\nEnter starting value: ");
  scanf("%d", &val);
  return(val);
}
