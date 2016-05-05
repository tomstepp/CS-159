/***************************************************************************
*  Programmer and Purdue Email Address:
*  1. steppt@purdue.edu
*
*  Homework #: 6 
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
*  Program Description: Given the configuration of the fields and the desired number of years, display how the pest will spread over this time frame.
***************************************************************************/
#include <stdio.h>
#include <math.h>

long long int getfield();
int getyear();
void spread(long long int, int);

int main()
{
  long long int config;
  int year;

  config = getfield();
  year = getyear();
  spread(config, year);

  return(0);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: getfield
*
*     Programmer's Name: Tom Stepp
*
*     Function Return Type: long long int
*
*     Parameters (list data type, name, and comment one per line):
*       1.long long int //field configuration input
*       
*     Function Description: field input
***************************************************************************/
long long int getfield()
{
  long long int config;
  
  do
  {
    printf("\nEnter field configuration: ");
    scanf("%lld", &config);

    if(config < 0)
    {
      printf("Error!  Integer can contain 1  and 2 digits only!!\n\n");
    }
  }while(config < 0);

  return(config);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: getyear
*
*     Programmer's Name: Tom Stepp
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int year //input year
*
*     Function Description: year input function
***************************************************************************/
int getyear()
{
  int year;
  
  do
  {
    printf("Enter desired number of years: ");
    scanf("%d", &year);

    if (year < 0 )
    {
      printf("Error!  Non-negative years only!!\n\n");
    }
  }while(year < 0);

  return(year);
}
void spread(long long int config, int year)
{
  int i; //index value
  
  printf("\nOriginal Configuration: %lld", config);

  for(i = 1; i < year + 1; i++)
  {
        
    printf("\nYear: %d Configurations: %lld", i, config);
  }
  
  printf("\n\n");
  return;
}







