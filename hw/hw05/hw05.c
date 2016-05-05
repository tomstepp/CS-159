/***************************************************************************
*  Programmer and Purdue Email Address:
*  1. Tom Stepp - steppt@purdue.edu
*
*  Homework #:5
*
*  Academic Integrity Statement:
*
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.
*
*  Lab Division and Section: div08 sec01
*
*  Program Description:receive the starting address, ending address, and movement of a robot to calculate its final location.
***************************************************************************/
#include <stdio.h>
#include <math.h>

int getstart(void); //receives starting point
int getend(int); //receives end point
int getvalue(void); //receives robot movement values
int movement(int, int); //calculates movement of robot
void result(int); //displays the final location

int main(void)
{
  int start; //starting address of robot
  int end; //ending address of robot
  int final; //final location of robot
  
  start = getstart();
  end = getend(start);
  final = movement(start, end);
  result(final);
  return(0);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:getstart
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int start //starting address of robot
*
*     Function Description:receive start address of robot
***************************************************************************/
int getstart(void)
{
  int start; //starting address of robot
  printf("\nEnter starting address: ");
  scanf("%d",&start);
  return(start);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:getend
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int end //ending address of robot
*
*     Function Description : get value of end point
***************************************************************************/
int getend(int start)
{
  int end; //ending address of robot
  do
  {
    printf("Enter ending address: ");
    scanf("%d",&end);
    if(end < start)
    { printf("\nError!  Ending address must be >= %d\n\n", start);}
  }while(end < start);
  return(end);
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
*       1.int value //movement value of robot
*       
*     Function Description: get value of movement
***************************************************************************/
int getvalue(void)
{
  int value; //movement value of robot
  scanf(" %d",&value);
  return(value);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:movement
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int final // final value of robot
*       2.int value // value of movement
*    
*     Function Description: calculate the final position of rover
***************************************************************************/
int movement(int start, int end)
{
  int final; //final value of robot
  int value; //value of robot movement  
  final = start;
  printf("Enter values to move now: ");
  while (value != 0)
  {
    value = getvalue();
    final = final + value;
    if (final > end)
      {final = end;}
    else if (final < start)
      {final = start;}
  }
  return(final);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:result
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*     
*     Function Description:display final location of robot
***************************************************************************/
void result(int final)
{
  printf("\nFinal location: %d\n\n", final);
  return;
}
