/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. steppt@purdue.edu
*
*  Homework #: HW 01
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
*  Program Description: Given a principal amount from the user, determine the
*               monthly interest generated at the rates of each year listed in the table. Create float variable and utilize printf and scanf commands to gather and display information.
*
***************************************************************************/

#include <stdio.h>

int main (void)
{
  //LOCAL DECLARATIONS
  float principal; //Initial amount in CD
  float rate; //Interest rate of CD
  float interest; //Amount of interest earned

  //EXECUTABLE STATEMENTS
  printf("\nEnter principal amount: ");
  scanf("%f", &principal);
  
  printf("\n  Principal \n-=-=-=-=-=-=- \n $ %10.2f\n\n",principal);

  printf("%s %5s %10s \n-=-=-=-=-=-=-=-=-=-=-=\n","Year","Rate","Interest"); //these two lines set the header for the programi

  rate = 9.10; //Percent interest in 1984
  interest = principal * rate / 12 * 0.01;
  printf("1984 %5.2f%% $ %8.2f\n",rate,interest); 
 
  rate = 7.00; //Percent interest in 1988
  interest = principal * rate / 12 * 0.01;
  printf("1988 %5.2f%% $ %8.2f\n",rate,interest);

  rate = 3.60; //Percent interest in 1992
  interest = principal * rate / 12 * 0.01;
  printf("1992 %5.2f%% $ %8.2f\n",rate,interest);
 
  rate = 4.90; //Percent interest in 1996
  interest = principal * rate / 12 * 0.01;
  printf("1996 %5.2f%% $ %8.2f\n",rate,interest);

  rate = 5.30; //Percent interest in 2000
  interest = principal * rate / 12 * 0.01;
  printf("2000 %5.2f%% $ %8.2f\n",rate,interest);

  rate = 1.20; //Percent interest in 2004
  interest = principal * rate / 12 * 0.01;
  printf("2004 %5.2f%% $ %8.2f\n",rate,interest);

  rate = 1.80; //Percent interest in 2008
  interest = principal * rate / 12 * 0.01;
  printf("2008 %5.2f%% $ %8.2f\n",rate,interest); 

  rate = 0.40; //Percent interest in 2012
  interest = principal * rate / 12 * 0.01;
  printf("2012 %5.2f%% $ %8.2f\n\n",rate,interest);

  return 0;
} // main



