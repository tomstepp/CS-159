/***************************************************************************
*  Programmer and Purdue Email Address:
*  1. steppt@purdue.edu
*
*  Homework #: 07
*
*  Academic Integrity Statement:
*
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.
*
*  Lab Division and Section: div 08 sec 01
*
*  Program Description:Determine total number of jobs if executed in order and max number of jobs in any order.
***************************************************************************/
#include <stdio.h>
#include <math.h>
#define SIZE 25
#define EXIT -1
int getjobs(int[]);
int getlimit();
void findcapacity(int[], int, int);
void findoptimized(int[], int, int);
void sort(int[], int);
int calc(int[], int, int);

int main()
{
  int jobs[SIZE]; //input array of jobs
  int limit; //input of time limit
  int jobnum; //number of jobs
  jobnum = getjobs(jobs);
  limit = getlimit();
  findcapacity(jobs, jobnum, limit);
  findoptimized(jobs, jobnum, limit);
  return(0);
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
*       1.int pass //controls # of passes
*       2.int i //lcv
*       3.int temp //temp value for swap
*
*     Function Description:bubble sort the jobs
***************************************************************************/
void sort(int jobs[], int jobnum)
{
  int pass; //controls # of passes
  int i; //loop control variable
  int temp; //temporary value for swap

  for(pass = 1; pass < jobnum; pass++)
  {
    for(i = 0; i < jobnum - pass; i++)
    {
      if(jobs[i] > jobs[i + 1])
      {
        temp = jobs[i];
        jobs[i] = jobs[i + 1];
        jobs[i + 1] = temp;
      }
    }
  }
  return;
}
/***************************************************************************
*     Function Information
*
*     Name of Function: calc
*
*     Programmer's Name: Tom Stepp
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int cap // capacity of jobs
*       2.int i //index value of array
*
*     Function Description:calculate job capacity
***************************************************************************/
int calc(int jobs[], int jobnum, int limit)
{
  int cap = 0; //capacity of jobs
  int i = 0; //index value of array
   
  while (jobs[i] <= limit)
  {
    limit -= jobs[i];
    cap++;
    if (i == jobnum - 1)
    {
      i = 0;
    }
    else
    {
      i++;
    }
  }
  return(cap);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: findcapacity
*
*     Programmer's Name: Tom Stepp
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int capacity //current job capacity
*
*     Function Description: find job capacity for intitial order
***************************************************************************/
void findcapacity(int jobs[], int jobnum, int limit)
{
  int capacity; //current job capacity
  capacity = calc(jobs, jobnum, limit);
  printf("Job capacity in current order: %d\n", capacity);
  return;
}
/***************************************************************************
*     Function Information
*
*     Name of Function: findoptimized
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int opt // optimized job capacity
*
*     Function Description: find optimized job capacity
***************************************************************************/
void findoptimized(int jobs[], int jobnum, int limit)
{
  int opt; //optimized job capacity
  sort(jobs, jobnum);
  opt = calc(jobs, jobnum, limit);
  printf("Optimized job capacity: %d\n\n", opt);
  return;
}
/***************************************************************************
*     Function Information
*
*     Name of Function:getjobs
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int error //error of invalid input
*       2.int i //index position
*       3.int jobnum // number of jobs
*
*     Function Description:calculate number of jobs and receive job input
***************************************************************************/
int getjobs(int jobs[])
{
  int error; //error value for invalid numbers
  int i; //index for position
  int jobnum; //number of jobs
  do
  {
    i = 0; 
    error = 0;
    printf("\nEnter job sizes now: ");
    do
    {
      scanf("%d", &jobs[i]);
      i++;
    }while((jobs[i - 1] != EXIT) && (i < SIZE));
    
    jobnum = i - 1;
    if (i == SIZE)
    {
      jobnum = SIZE;
    }

    for(i = 0; i < jobnum; i++)
    {
      if (jobs[i] < 0)
      {
        error++;
      }
    }

    if (error > 0)
    {
      printf("\nInvalid data entered!  Non-negative values only!!\n");
    }
  }while(error != 0);

  return(jobnum);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: getlimit
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int limit //limit time of computer
*
*     Function Description: get limit input from user
***************************************************************************/
int getlimit()
{
  int limit; //time limit of computer
  do
  {
    printf("Enter time limit of the computer: ");
    scanf("%d", &limit);
    if (limit < 0)
    {
      printf("\nError! Non-negative values only!\n\n");
    }
  }while(limit < 0);
  printf("\n");
  return(limit);
}

