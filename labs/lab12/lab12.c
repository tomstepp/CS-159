/***************************************************************************
*  Programmers and Purdue Email Addresses:
*	 1. steppt@purdue.edu
*	 2. ddecarde@purdue.edu
*	 3. hu234@purdue.edu (delete line if no third partner)
*
*  Lab #: 12 
*
*  Academic Integrity Statement:
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access 
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section: div 08 sec 01
*
*  Program Description:
***************************************************************************/
#include <stdio.h>
#include <math.h>
#define MAX 35
#define EXIT -1
int getweights(int[]);
int getclass(int);
void sort(int[], int);
int findmin(int[],int, int);

int main()
{
  int weights[MAX]; //input array of weights
  int size; //size of array for class
  int class; //input of class size  
  size = getweights(weights);
  class = getclass(size);
  
  sort(weights, size);
  findmin(weights, size, class);
  return(0);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:findmin
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int min //difference in weight
*       2.int i //lcv
*
*     Function Description: find minimum difference in weight
**************************************************************************/
int findmin(int weights[], int size, int class)
{
  int min = 0; //minimum difference in weight
  int i; //lcv
  
  for(i = 1; i < class; i++)
  {
    if(weights[i] > weights[i - 1])
    {
      min = weights[i] - weights[0];
    }
  }
  printf("By selecting %d of %d packages the minimum difference is: %d\n\n",class, size, min);
  return(min);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: sort
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int pass //control passes
*       2.int i //lcv
*       3.int temp // temp value
*
*     Function Description:sort array
***************************************************************************/
void sort(int weights[], int size)
{
  int pass; //controls passes
  int i; //lcv
  int temp; //temporary value for swap

  for(pass = 1; pass < size; pass++)
  {
    for(i = 0; i < size - pass; i++)
    {
      if(weights[i] > weights[i + 1])
      {
        temp = weights[i];
        weights[i] = weights[i + 1];
        weights[i + 1] = temp;
      }
    }
  }
  return;
}
/***************************************************************************
*     Function Information
*
*     Name of Function: getweights
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int size //size of class
*       2.int i //lcv
*
*     Function Description: get weights array and return size
***************************************************************************/
int getweights(int weights[])
{
  int size; //size of class
  int i; //loop control variable
  
  i = 0;
  printf("\nEnter package weight: ");
  do
  {
    scanf("%d", &weights[i]);
    i++;
  }while((weights[i - 1] != EXIT) && (i < MAX));
  
  size = i -1;
  
  if (i == MAX)
  {
    size = MAX;
  }
  return(size);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: getclass
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int class //size of class
*
*     Function Description: get the class size
***************************************************************************/
int getclass(int size)
{
  int class; //size of class
  do
  {
    printf("Enter class size: ");
    scanf("%d", &class);
    if (class < 2)
    {
      printf("\nError! Minimum number to select is 2!\n\n");
    }
    if (class > size)
    {
      printf("\nError There are only %d packages to select!\n\n", size);
    }
  }while(class < 2 || class > size);
  
  printf("\n");
  return(class);
}
