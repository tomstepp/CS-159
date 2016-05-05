/***************************************************************************
 * *
 * *  Programmers and Purdue Email Addresses:
 * *        
 * *         1. thoma420@purdue.edu
 * *         2. lthibaul@purdue.edu
 * *         3. steppt@purdue.edu (delete line if no third partner)
 * *  
 * *
 * *  Lab #: 04 
 * *
 * *  Academic Integrity Statement:
 * *
 * *       We have not used source code obtained from
 * *       any other unauthorized source, either modified
 * *       or unmodified.  Neither have we provided access 
 * *       to our code to another. The project we are submitting
 * *       is our own original work.
 * *
 * *  Lab Division and Section: Yuchen Cui SC 189 3:30-5:20p
 * *
 * *  Program Description:
 * *
 * ***************************************************************************/
#include<stdio.h>
#include<math.h>
#define BORDER "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"

double hex_height(void);
double hex_side(void);
double hex_apothem(double side);
double hex_base_area(double side);
double hex_side_area(double side, double height);
double hex_prism_volume(double side, double height);
double hex_prism_SA(double side_area, double base_area);
double pyra_side_area(double height, double side);
double pyra_volume(double side, double height);
double pyra_SA(double base_area, double pyra_area);
void displayresults(double apothem, double base_area, double side_area, double hex_volume, double hex_SA, double pyra_area, double pyra_vol, double pyra_surface_area);

int main()
{
    //Local Declarations
    double height;
    double side;
    double apothem;
    double base_area;
    double side_area;
    double hex_volume;
    double hex_SA;
    double pyra_area;
    double pyra_vol;
    double pyra_surface_area;

    //Executable Statements
                               
    height = hex_height ( );
    side = hex_side ( );
    apothem = hex_apothem (side);
    base_area = hex_base_area (side);

    side_area = hex_side_area(side, height);
    hex_volume = hex_prism_volume(side, height);
    hex_SA = hex_prism_SA(side_area, base_area);

    pyra_area = pyra_side_area(height,side);
    pyra_vol = pyra_volume(side,height);
    pyra_surface_area = pyra_SA(base_area, pyra_area);

    displayresults(apothem, base_area, side_area, hex_volume, hex_SA, pyra_area, pyra_vol, pyra_surface_area);
   
   return(0);
}

/***************************************************************************
 * *
 * *     Function Information
 * *
 * *     Name of Function: height
 * *
 * *     Programmer's Name: Alex Thomas
 * *
 * *     Function Return Type: double
 * *
 * *     Parameters (list data type, name, and comment one per line):
 * *       1. 
 * *       2.
 * *       3.
 * *
 * *     Function Description:Gets the value of the height of the figure
 * *
 * ***************************************************************************/
double hex_height ()
{
    //Local Declarations
        double height;
          //Executable Statements  
              printf("Enter the total height of the figure: ");
                scanf("%lf", &height);

                  return(height);
}  

/***************************************************************************
 * *
 * *     Function Information
 * *
 * *     Name of Function: side
 * *
 * *     Programmer's Name: Alex Thomas
 * *
 * *     Function Return Type: double
 * *
 * *     Parameters (list data type, name, and comment one per line):
 * *       1. 
 * *       2.
 * *       3.
 * *
 * *     Function Description: Gets the value of the hexagon side.
 * *
 * ***************************************************************************/
double hex_side ()
{
    //Local Declarations
    double side;
      
    //Executable Statements
    printf("Enter the length of the hexagon side: ");
    scanf("%lf", &side);
   
   return(side);
}

/***************************************************************************
 * *
 * *     Function Information
 * *
 * *     Name of Function: apothem
 * *
 * *     Programmer's Name:Alex Thomas
 * *
 * *     Function Return Typeouble
 * *
 * *     Parameters (list data type, name, and comment one per line):
 * *       1. side double - the side of the hexagon 
 * *       2.
 * *       3.
 * *
 * *     Function Description:Calculates the apothem length of the hexagon.
 * *
 * ***************************************************************************/
double hex_apothem(double side)
{
    return( sqrt(3) / 2 * side);
}

/***************************************************************************
 * *
 * *     Function Information
 * *
 * *     Name of Function:hex_base_area
 * *
 * *     Programmer's Name:Alex Thomas
 * *
 * *     Function Return Typeouble
 * *
 * *     Parameters (list data type, name, and comment one per line):
 * *       1. side double - length of the hexagon side
 * *       2.
 * *       3.
 * *
 * *     Function Description:Calculates the base area of the hexagon.
 * *
 * ***************************************************************************/
double hex_base_area(double side)
{
    return( sqrt(3) * 3 / 2 * side * side);
}
/***************************************************************************
 * *
 * *     Function Information
 * *
 * *     Name of Function: hex_side_area
 * *
 * *     Programmer's Name:Alex Thomas
 * *
 * *     Function Return Typeouble
 * *
 * *     Parameters (list data type, name, and comment one per line):
 * *       1. side double - length of the side of the hexagon
 * *       2. height double - height of the figure
 * *       3.
 * *
 * *     Function Description:Calculates the hexagonal prism'*     s side area.
 * *
 * ***************************************************************************/
double hex_side_area(double side, double height)
{
    return(side * height * 0.8);
}

/***************************************************************************
 * *
 * *     Function Information
 * *
 * *     Name of Function:hex_prism_volume
 * *
 * *     Programmer's Name:Alex Thomas
 * *
 * *     Function Return Typeouble
 * *
 * *     Parameters (list data type, name, and comment one per line):
 * *       1. side double - length of the side of the prism
 * *       2. height double - height of the figure
 * *       3.
 * *
 * *     Function Description:Calculates the hexagonal prism'*     s volume.
 * *
 * ***************************************************************************/
double hex_prism_volume(double side, double height)
{
    return( sqrt(3) * 3 / 2 * side * side * height * 0.8);
}

/***************************************************************************
 * *
 * *     Function Information
 * *
 * *     Name of Function:hex_prism_SA
 * *
 * *     Programmer's Name:Alex Thomas
 * *
 * *     Function Return Typeouble
 * *
 * *     Parameters (list data type, name, and comment one per line):
 * *       1. side_area double - area of a side of the hexagon.
 * *       2. base_area double - area of the base of the hexagon.
 * *       3.
 * *
 * *     Function Description:Calculates the surface area of the hexagonal prism.
 * *
 * ***************************************************************************/
double hex_prism_SA(double side_area, double base_area)
{
    return(6 * side_area + 2 * base_area);
}

/***************************************************************************
 * *
 * *     Function Information
 * *
 * *     Name of Functionyra_side_area
 * *
 * *     Programmer's Name:Alex Thomas
 * *
 * *     Function Return Typeouble
 * *
 * *     Parameters (list data type, name, and comment one per line):
 * *       1. side double - length of the hexagon side
 * *       2. height double - height of the figure
 * *       3.
 * *
 * *     Function Description:Calculates the side area of the hexagonal pyramid.
 * *
 * ***************************************************************************/
double pyra_side_area( double height, double side)
{
    return(2 * side * 2.6339);
}

/***************************************************************************
 * *
 * *     Function Information
 * *
 * *     Name of Functionyra_volume
 * *
 * *     Programmer's Name:Alex Thomas
 * *
 * *     Function Return Typeouble
 * *
 * *     Parameters (list data type, name, and comment one per line):
 * *       1.base_area double - area of the hexagon
 * *       2.height double - height of the figure
 * *       3.
 * *
 * *     Function Description:Calculates the volume of the hexagonal pyramid.
 * *
 * ***************************************************************************/
double pyra_volume(double side, double height)
{
    return(sqrt(3) / 2 * side * side * height * 0.2);
}

/***************************************************************************
 * *
 * *     Function Information
 * *
 * *     Name of Functionyra_SA
 * *
 * *     Programmer's Name:Alex Thomas
 * *
 * *     Function Return Typeouble
 * *
 * *     Parameters (list data type, name, and comment one per line):
 * *       1. base_area double - area of the base hexagon
 * *       2. pyra_side_area double - area of the side of the pyramid
 * *       3.
 * *
 * *     Function Description:Calculates the surface area of the hexagonal pyramid.
 * *
 * ***************************************************************************/
double pyra_SA(double base_area, double pyra_area)
{
    return(6 * pyra_area + base_area);
}

/***************************************************************************
 * *
 * *     Function Information
 * *
 * *     Name of Functionisplayresults
 * *
 * *     Programmer's Name:Alex Thomas
 * *
 * *     Function Return Type:void
 * *
 * *     Parameters (list data type, name, and comment one per line):
 * *       1. apothem double - length of the apothem
 * *       2. base_area double - area of the hexagon base
 * *       3. side_area double - area of the side of hex
 * *       4. hex_volume double - volume of hex prism
 * *       5. hex_SA double - surface area of hex prism
 * *       6. pyra_area double - area of the side pyra prism
 * *       7. pyra_vol double - volume of pyra prism
 * *       8. pyra_surface_area double - SA of pyra prism
 * *
 * *     Function Descriptionisplays Results of Calculations.
 * *
 * ***************************************************************************/
void displayresults(double apothem, double base_area, double side_area, double hex_volume, double hex_SA, double pyra_area, double pyra_vol, double pyra_surface_area)
{
    printf("\n\n");
    printf(BORDER);
    printf("Hexagon\n");
    printf(BORDER);
    printf("Apothem Length:%14.2lf\n",apothem);
    printf("Base Area:%19.2lf\n",base_area);
    printf(BORDER);
    printf("Hexagonal Prism\n");
    printf(BORDER);
    printf("Prism Side Area:%13.2lf\n",side_area);
    printf("Prism Volume:%16.2lf\n",hex_volume);
    printf("Prism Surface Area:%10.2lf\n",hex_SA);
    printf(BORDER);
    printf("Hexagonal Pyramid\n");
    printf(BORDER);
    printf("Pyramid Side Area:%11.2lf\n",pyra_area);
    printf("Pyramid Volume:%14.2lf\n",pyra_vol);
    printf("Pyramid Surface Area:%8.2lf\n",pyra_surface_area  );
    printf(BORDER);

   return;
}







