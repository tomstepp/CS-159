
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. steppt@purdue.edu
*	 2. login2@purdue.edu
*	 3. login3@purdue.edu (delete line if no third partner)
*
*  Lab #: 06
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
*  Program Description: Calculate water volume for any of three tanks given the height of the water.
*
***************************************************************************/

#include <stdio.h>
#include<math.h>

int input (void); //receives selection from user
int tank (int); //Determines which tank to use
float cube (void); //Calculates volume for cube tank
float sphere (void); //Calculates volume for sphere tank
float hexagon (void); //Calculates volume for hexagon tank
int getpyrheight(void);//gets height of pyramid from user
int getpriheight(void);//gets height of prism from user
int getwatheight(void);//gets height of water from user
float basecalc(int);//calculates the area of the base
float privolcalc(float, int);//calculates volume of the prism
float pyrvolcalc(int);//calculates volume of the pyramid
float totalvolcalc(int, int, int);//calculates the toptal volume of water
int getcubeheight1 (void); //gets the height of cube 1
int getcubeheight2(void); //gets height of cube 2
int getcubeheight3 (void); //gets height of cube 3
int getcylheight (void); //gets height of cylinder
int getradius (void); //gets radius of cylinder
int calcvolcube1 (int); //volume of cube 1
int calcvolcube2 (int); //volume of cube 2
int calcvolcube3 (int); //volume of cube 3
float calcvolcyl(int); //volume of cylinder
float calcvolsphere(int); //volume for hemispheres


void results (float); //Display results for volume

int main(void)
{
  int selection; //User input for tank
  float volume; //Calculated volume for tank

  selection = input();
  volume = tank(selection);
  results(volume);

  return(0);
}
int input(void)
{
  int selection;
  printf("Lab #6 Main Menu\n\n1. Cube\n2. Sphere\n3. Hexagon\n\nEnter your selection now: ");
  scanf("%d", &selection);
  return(selection);
}
int tank(int selection)
{
  float vol;
  if (selection == 1)
  {
   vol =  cube();
  }
  else if (selection ==2)
  {
   vol = sphere();
  }
  else if (selection == 3)
  {
   vol = hexagon();
  }
  else
  {
    printf("Please enter a valid integer.");
  }
  return(vol);
}
float cube()
{
  float vol;
  int cubeheight1;
  int cubeheight2;
  int cubeheight3;
  int watheight;
  int volcube1;
  int volcube2;
  int volcube3;

  cubeheight1 = getcubeheight1();
  cubeheight2 = getcubeheight2();
  cubeheight3 = getcubeheight3();
  watheight = getwatheight();
  volcube1 = calcvolcube1(cubeheight1);
  volcube2 = calcvolcube2(cubeheight2);
  volcube3 = calcvolcube3(cubeheight3);

  return(vol);
}
float sphere()
{
  float vol;
  int cylheight;
  int radius;
  int watheight;
  int volcyl;
  int volsphere;

  cylheight = getcylheight();
  radius = getradius();
  volcyl = calcvolcyl(cylheight);
  volsphere = calcvolsphere(radius);


  return(vol);
}
float hexagon()
{
  int pyrheight;//user inputed height of the pyramid
  int priheight;//user inputed height of the prism
  int watheight;//user inputed height of the water
  float totalwatvol;//total volume of water
  pyrheight = getpyrheight();
  priheight = getpriheight();
  watheight = getwatheight();
  totalwatvol = totalvolcalc(pyrheight, priheight, watheight);

  return(totalwatvol);
}
int getpyrheight(void)
{
  int pyrheight;
  printf("Enter the height of the pyramid: ");
  scanf("%d", &pyrheight);
  return(pyrheight);
}
int getpriheight(void)
{
  int priheight;
  printf("Enter the height of the prism: ");
  scanf("%d", &priheight);
  return(priheight);
}
int getwatheight(void)
{
  int watheight;
  printf("Enter the height of the water: ");
  scanf("%d", &watheight);
  return(watheight);
}
float basecalc(int pyrheight)
{
  return((pow(pyrheight, 2)) * ((3.0 * sqrt(3.0)) / 2));
}
float privolcalc(float hexbase, int priheight)
{
  return(hexbase * priheight);
}
float pyrvolcalc(int pyrheight)
{  
  return((sqrt(3.0) / 2) * (pow(pyrheight, 3)));
}
float totalvolcalc(int pyrheight, int priheight, int watheight)
{
  int top;//determines height of top part that is filled with water
  int emptyhight;//determines height of tank that is empty
  int mid;//determines height of top part that is filled with water
  float vol;//final volume
  float privolume;//volume of the prism
  float pyrvolume;//volume of the pyramid
  float hexbase;//area of the hexagonal base

  top = watheight / (pyrheight + priheight);
  top = (top + 2) % (top + 1);
  emptyhight = 2 * pyrheight + priheight - watheight;
  mid = watheight / priheight;
  mid = (mid + 2) % (mid + 1);

  hexbase = basecalc(pyrheight);
  pyrvolume = pyrvolcalc(pyrheight);
  privolume = privolcalc(hexbase, priheight);

  vol = top * (2 * pyrvolume + privolume - pyrvolcalc(emptyhight)) + mid * (1 - top) * (pyrvolume + privolcalc(hexbase,watheight - pyrheight)) + (1 - mid) * pyrvolcalc(watheight);
  return(vol);
}
int getcubeheight1()
{
  int cubeheight1;
  printf("Enter the height of the lowest cube: ");
  scanf("%d", &cubeheight1);
  return(cubeheight1);
}
int getcubeheight2()
{
  int cubeheight2;
  printf("Enter the height of the middle cube: ");
  scanf("%d", &cubeheight2);
  return(cubeheight2); 
}
int getcubeheight3()
{
  int cubeheight3;
  printf("Enter the height of the highest cube: ");
  scanf("%d", &cubeheight3);
  return(cubeheight3);
}
int getcylheight()
{
  int cylheight;
  printf("Enter the height of the cylindrical tank: ");
  scanf("%d", &cylheight);
  return(cylheight);
}
int getradius()
{
  int radius;
  printf("Enter the radius of the tank: ");
  scanf("%d", &radius);
  return(radius);
}






























