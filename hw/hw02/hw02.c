
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. Tom Stepp steppt@purdue.edu
*
*  Homework #: 02
*
*  Academic Integrity Statement:
*
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.
*
*  Lab Division and Section: div08 sec 01
*
*  Program Description: To determine if three integers were entered in ascending order and if they represent a Pythagorean Triplet.
*
***************************************************************************/

#include <stdio.h>

int main(void)
{
  //LOCAL DEFINITIONS
 
  int a = 0; //Integer value for A
  int b = 0; //Integer value for B
  int c = 0; //Integer value for C
  int factor = 0 ; //Helps determine if values are ascending
  int order_status = 0 ; //Integer for ascending order
  int max = 0 ; //Allows order status to only equal 1 or 0
  int triplet_status = 0 ; //Integer for Pythagorean Triplet

  //EXECUTABLE STATEMENTS
  
  printf("\n Enter the three values to test(a b c): ") ;
  scanf("%d %d %d", &a, &b, &c) ;
  
  factor = a / b + b / c; //Determines if values are ascending order  
  max = (factor + 2) % (factor + 1); //Makes the max value 1
  order_status = 1 - max; 

  printf("\n a < b < c Status: %d ", order_status) ;

  
  triplet_status = order_status * (a * a + b * b) / (c * c);
  
  printf("\n Pythagorean Triplet Status: %d\n\n ", triplet_status) ;

  return(0);
}






