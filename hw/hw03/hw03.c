/***************************************************************************
*  Programmer and Purdue Email Address:
*  1. Tom Stepp steppt@purdue.edu
*
*  Homework #: 3 
*
*  Academic Integrity Statement:
*
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.
*
*  Lab Division and Section: sec01 div08
*
*  Program Description: Given a year and day number, display the date, previous sunday, and next saturday
***************************************************************************/

#include <stdio.h>
#include <math.h>

int getyear(); //input year from user
int getday(); //input day number from user
int leap(int); //determine if it is a leap year
int day_of_week(int, int); //find day of week for input
int findmonth(int,int, int); //determine which month it is
int day_of_month(int, int, int, int); //determine day of month
int sunday(int, int, int, int, int, int); //determine previous sunday
int saturday(int, int, int, int, int, int); //determine next saturday
int display(int, int, int, int, int, int); //display results

int main(void)
{
  //Local Definitions
  int year; //year input
  int day; //day input
  int leapyear; //binary for if it is a leap year or not
  int weekday; //day of week
  int month; //month of year
  int monthday; //day of month

  //Executable Statements  
  year = getyear();
  day = getday();
  leapyear = leap(year);
  weekday = day_of_week(year, day);
  month = findmonth(year, day, leapyear);
  monthday = day_of_month(day, year, month, leapyear);
  display(year, day, leapyear, weekday, month, monthday);
  sunday(year, day, leapyear, weekday, month, monthday);
  saturday(year, day, leapyear, weekday, month, monthday); 
  return(0);
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
*       1.
*       2.
*       3.
*
*     Function Description:display input date
***************************************************************************/

int display(int year, int day, int leapyear, int weekday, int month, int monthday)
{
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

  return(0);
}

/****************************************************************************
*     Function Information
*
*     Name of Function:sunday
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int sunmonth
*       2.int nextday
*       3.
*
*     Function Description:display the previous sunday
*
***************************************************************************/

int sunday(int year, int day, int leapyear, int weekday, int month, int monthday)
{
  //Local Declarations
  int sunmonth; //month of previous sunday
  int prevday; //Date of previous sunday
  //Local Executions
  if (day < 8)
  { printf("\nThere is no previous Sunday in %d.", year); }
  else
  { printf("\nPrevious Sunday: "); 

  if (weekday > 0)
  { prevday = day - weekday;}
  else
  { prevday = day - 7; }

  sunmonth = findmonth(year, prevday, leapyear);
 
  if (sunmonth == 1)
   { printf("January ");}
  else if (sunmonth == 2)
   { printf("February ");}
  else if (sunmonth == 3)
   { printf("March ");}
  else if (sunmonth == 4)
   { printf("April ");}
  else if (sunmonth == 5)
   { printf("May ");}
  else if (sunmonth == 6)
   { printf("June ");}
  else if (sunmonth == 7)
   { printf("July ");}
  else if (sunmonth == 8)
   { printf("August ");}
  else if (sunmonth == 9)
   { printf("September ");}
  else if (sunmonth == 10)
   { printf("October ");}
  else if (sunmonth == 11)
   { printf("November ");}
  else if (sunmonth == 12)
   { printf("December ");}

  prevday = day_of_month(prevday, year, sunmonth, leapyear);
  
  printf("%d, %d", prevday, year);
}
  return(0);
}
   
/****************************************************************************
*     Function Information
*
*     Name of Function: saturday
*
*     Programmer's Name:Tom Stepp
*
*     Function Return Type:void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int satmonth
*       2.int nextday
*       3.
*
*     Function Description:display the next saturday
***************************************************************************/

int saturday(int year, int day, int leapyear, int weekday, int month, int monthday)
{
  //Local Declarations
  int satmonth; //month of next saturday
  int nextday; //day of next saturday
  //Executable Statements
  if (day > 357 || (leapyear == 1 && day > 358))
  { printf("\nThere is no next Saturday in %d.", year); }
  else
  {
  printf("\nNext Saturday: ");

  if (weekday == 6)
  { nextday = day + 7 ;}
  else
  { nextday = day + (6 - weekday);}

  satmonth = findmonth(year, nextday, leapyear);

  if (satmonth == 1)
   { printf("January ");}
  else if (satmonth == 2)
   { printf("February ");}
  else if (satmonth == 3)
   { printf("March ");}
  else if (satmonth == 4)
   { printf("April ");}
  else if (satmonth == 5)
   { printf("May ");}
  else if (satmonth == 6)
   { printf("June ");}
  else if (satmonth == 7)
   { printf("July ");}
  else if (satmonth == 8)
   { printf("August ");}
  else if (satmonth == 9)
   { printf("September ");}
  else if (satmonth == 10)
   { printf("October ");}
  else if (satmonth == 11)
   { printf("November ");}
  else if (satmonth == 12)
   { printf("December ");}
 
  nextday = day_of_month(nextday, year, satmonth, leapyear);

  printf("%d, %d", nextday, year);
  }

  printf("\n\n");
  return(0);
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
*       1.
*       2.
*       3.
*
*     Function Description: get value of year
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
*       1.
*       2.
*       3.
*
*     Function Description: get value of day
***************************************************************************/

int getday()
{
  //Local Declarations
  int day;
  //Executable Statements
  printf("Enter the day number (1 - 365): ");
  scanf("%d", &day);
  return(day);
}

/***************************************************************************
*     Function Information
*
*     Name of Function: Leap
*
*     Programmer's Name: Tom Stepp
*
*     Function Return Type:int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int leapyear
*       2.int year
*       3.
*
*     Function Description:determine if it is a leap year
*
***************************************************************************/

int leap(int year)
{
  //Local
  int leapyear;
  //Execute 
  leapyear = 0;

  if ((year % 4 == 0) && ((!(year % 100) == 0) || (year % 400 == 0)))
  {
         leapyear = 1;
  }
  return(leapyear);
}

/***************************************************************************
*     Function Information
*    
*     Name of Function: day_of_week
*
*     Programmer's Name: Tom Stepp
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int year
*       2.int day
*       3.
*
*     Function Description: determine the corresponding day number
***************************************************************************/

int day_of_week(int year, int day)
{
  //Local Declarations
  int weekday; //day of the week

  //Executable Statements
  weekday = (((year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) + day) % 7;
    
  return(weekday);
}

/***************************************************************************
*     Function Information
*
*     Name of Function:
*
*     Programmer's Name:
*
*     Function Return Type:
*
*     Parameters (list data type, name, and comment one per line):
*       1.int year
*       2.int day
*       3.int leapyear
*
*     Function Description: determine which month it is
***************************************************************************/
 
int findmonth(int year, int day, int leapyear)
{
  //Local Declarations
  int month ; //Determines what month the input day is

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
*     Name of Function: day_of_month
*
*     Programmer's Name: Tom Stepp
* 
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int day
*       2.int month
*       3.int year
*
*     Function Description: determine the day of the month
***************************************************************************/

int day_of_month(int day, int year, int month, int leapyear)
{
  //Local
  int monthday; //day of the month
  //Execute
  if (month == 1)
    monthday = day;
  else if (month == 2)
    monthday = day - 31;
  else if (month == 3)
    monthday = day - 59;
  else if (month == 4)
    monthday = day - 90;
  else if (month == 5)
    monthday = day - 120;
  else if (month == 6)
    monthday = day - 151;
  else if (month == 7)
    monthday = day - 181;
  else if (month == 8)
    monthday = day - 212;
  else if (month == 9)
    monthday = day - 243;
  else if (month == 10)
    monthday = day - 273;
  else if (month == 11)
    monthday = day - 304;
  else if (month == 12)
    monthday = day - 334;
  
  if (leapyear == 1 && month > 2)
    monthday = monthday - 1;

  return(monthday);
}

