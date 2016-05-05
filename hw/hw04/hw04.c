/***************************************************************************
*  Programmer and Purdue Email Address:
*  1. Tom Stepp steppt@purdue.edu
*
*  Homework #: 4 
*
*  Academic Integrity Statement:
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.
*
*  Lab Division and Section: sec01 div08
*
*  Program Description: Given a year, day number, and desired future saturdays, display the date and future saturdays.
***************************************************************************/
#include <stdio.h>
#include <math.h>

int getyear(); //input year from user
int getday(int); //input day number from user
int getfuture(); //input desired number of future saturdays
int leap(int); //determine if it is a leap year
int inputday(int, int, int); //displays input date
int findweekday(int, int); //find day of week for input
int findmonth(int,int, int); //determine which month it is
int findmonthday(int, int, int); //determine day of month
void saturday(int, int, int, int, int); //determine next saturday
void display(int, int, int); //Display month, day, year
int main(void)
{
  //Local Definitions
  int year; //year input
  int day; //day input
  int future; //number of future saturdays
  int leapyear; //binary for if it is a leap year or not
  int weekday; //day of the week
  //Executable Statements  
  year = getyear();
  leapyear = leap(year);
  day = getday(leapyear);
  future = getfuture();
  weekday = inputday(year, day, leapyear);
  saturday(year, day, leapyear, weekday, future);
  return(0);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: display
*
*     Programmer's Name: Tom Stepp
*
*     Function Return Type: void
*
*     Function Description: display year, month, and day
***************************************************************************/
void display(int year, int month, int monthday)
{
  if (month == 1)
   { printf("January ");}
  else if (month == 2)
   { printf("February ");}
  else if (month == 3)
   { printf("March ");}
  else if (month == 4)
   { printf("April ");}
  else if (month == 5)
   { printf("May ");}
  else if (month == 6)
   { printf("June ");}
  else if (month == 7)
   { printf("July ");}
  else if (month == 8)
   { printf("August ");}
  else if (month == 9)
   { printf("September ");}
  else if (month == 10)
   { printf("October ");}
  else if (month == 11)
   { printf("November ");}
  else if (month == 12)
   { printf("December ");}
  
  printf("%d, %d", monthday, year);
  return;
}
/***************************************************************************
*     Function Information
*
*     Name of Function: inputday
*
*     Programmer's Name: Tom Stepp
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int month //month of input date
*       2. int monthday //number of input date
*       3. int weekday //day of input date
*
*     Function Description: call functions to display the input date
***************************************************************************/
int inputday(int year, int day, int leapyear)
{
  //Local
  int month;
  int monthday;
  int weekday;
  //Executable
  weekday = findweekday(year, day);
  month = findmonth(year, day, leapyear);
  monthday = findmonthday(day, month, leapyear);
  display(year, month, monthday);
  return(weekday);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: saturday
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int month //month of next saturday
*       2. int monthday //day of next saturday
*       3. int x //control variable of loop
*
*     Function Description: calculate next saturday dates
***************************************************************************/
void saturday(int year, int day, int leapyear, int weekday, int future)
{
  //Local Declarations
  int month;
  int monthday;
  int x; 
  //Executable Statements
  x = 0;
  while (x < future)
  {
    if (day > 357 || (leapyear == 1 && day > 358))
    { printf("\nNo more Saturday dates in %d.", year); 
      x = future; 
    }
    else
    {
    printf("\nNext Saturday: ");
    
    if (x == 0)
    {
      if (weekday == 6)
      { day = day + 7 ;}
      else
      { day = day + (6 - weekday);}
    }
    else
      {day += 7;}

    month = findmonth(year, day, leapyear);
    monthday = findmonthday(day, month, leapyear);

    display(year, month, monthday);
    x++;
    }
  }
  printf("\n\n");
  return;
}
/***************************************************************************
*     Function Information
*
*     Name of Function: getyear
*
*     Programmer's Name: Tom STepp
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int year //input from user
*
*     Function Description: Receive year number from user
***************************************************************************/
int getyear()
{
  //Local Declarations
  int year;
  //Executable Statements
  printf("\nEnter the year number: ");
  scanf("%d", &year);
  return(year);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:getday
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int day //input day from user
********************************************************************/
int getday(int leapyear)
{
  //Local Declarations
  int day;
  //Executable Statements
  if (leapyear == 1) 
    {printf("Enter the day number (1 - 366): ");}
  else
    {printf("Enter the day number (1 - 365): ");}
  
  scanf("%d", &day);
  return(day);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: getfuture
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int future //desired number of future saturdays
*
*     Function Description: receive input for number of saturdays from user
***************************************************************************/
int getfuture()
{
  //Local
  int future;
  //Executable
  printf("Enter desired number of future Saturdays: ");
  scanf("%d", &future);
  return(future);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:leap
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int leapyear //binary for if it is a leapyear or not
*
*     Function Description: determine if it is a leapyear
***************************************************************************/
int leap(int year)
{
  //Local
  int leapyear;
  //Execute 
  leapyear = 0;

  if ((year % 4 == 0) && ((!(year % 100) == 0) || (year % 400 == 0)))
  { leapyear = 1; }
  return(leapyear);
}
/***************************************************************************
*     Function Information
*
*     Name of Function:findweekday
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int weekday //which day of the week it is
*
*     Function Description:determine which day of the week it is
***************************************************************************/
int findweekday(int year, int day)
{
  //Local Declarations
  int weekday; //day of the week
  //Executable Statements
  weekday = (((year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) + day) % 7;
  printf("\nInput date: ");
  if (weekday == 0)
   { printf("Sunday ");}
  else if (weekday == 1)
   { printf("Monday ");}
  else if (weekday == 2)
   { printf("Tuesday ");}
  else if (weekday == 3)
   { printf("Wednesday ");}
  else if (weekday == 4)
   { printf("Thursday ");}
  else if (weekday == 5)
   { printf("Friday ");}
  else if (weekday == 6)
   { printf("Saturday ");}

  return(weekday);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: findmonth
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int month //what month it is
*
*     Function Description:determine which month it is
***************************************************************************/
int findmonth(int year, int day, int leapyear)
{
  //Local Declarations
  int month ; 
  //Executable Statements
  if (leapyear == 0)
  {
  if (day <= 31)
  { month = 1;}
  else if (day <= 59 )
  { month = 2;}
  else if (day <= 90)
  { month = 3;}
  else if (day <= 120)
  { month = 4;}
  else if (day <= 151)
  { month = 5;}
  else if (day <= 181)
  { month = 6;}
  else if (day <= 212)
  { month = 7;}
  else if (day <= 243)
  { month = 8;}
  else if (day <= 273)
  { month = 9;}
  else if (day <= 304)
  { month = 10;}
  else if (day <= 334)
  { month = 11;}
  else if (day <= 365)
  { month = 12;}
  }

  if (leapyear == 1)
  {
  if (day <= 31)
  { month = 1;}
  else if (day <= 60 )
  { month = 2;}
  else if (day <= 91)
  { month = 3;}
  else if (day <= 121)
  { month = 4;}
  else if (day <= 152)
  { month = 5;}
  else if (day <= 182)
  { month = 6;}
  else if (day <= 213)
  { month = 7;}
  else if (day <= 244)
  { month = 8;}
  else if (day <= 274)
  { month = 9;}
  else if (day <= 305)
  { month = 10; }
  else if (day <= 335)
  { month = 11; }
  else if (day <= 366)
  { month = 12;}
  }
  return(month);
}
/***************************************************************************
*     Function Information
*
*     Name of Function: findmonthday
*
*     Programmer's Name: Tom STepp
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int monthday //day of month
*
*     Function Description: determine what day of the month it is
***************************************************************************/
int findmonthday(int day, int month, int leapyear)
{
  //Local
  int monthday;
  //Execute
  if (month == 1)
    {monthday = day;}
  else if (month == 2)
    {monthday = day - 31;}
  else if (month == 3)
    {monthday = day - 59;}
  else if (month == 4)
    {monthday = day - 90;}
  else if (month == 5)
    {monthday = day - 120;}
  else if (month == 6)
    {monthday = day - 151;}
  else if (month == 7)
    {monthday = day - 181;}
  else if (month == 8)
    {monthday = day - 212;}
  else if (month == 9)
    {monthday = day - 243;}
  else if (month == 10)
    {monthday = day - 273;}
  else if (month == 11)
    {monthday = day - 304;}
  else if (month == 12)
    {monthday = day - 334;}
  
  if (leapyear == 1 && month > 2)
    {monthday = monthday - 1;}

  return(monthday);
}
