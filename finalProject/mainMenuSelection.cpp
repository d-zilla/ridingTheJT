/***
 ** Program name:  mainMenuSelection() function
 ** Author:        Dario Gerussi
 ** Date:          10/09/2019
 ** Description:   Displays main menu on screen.
 **                Prompts user to select a hoice by its integer value.
 **                Calls validInt() function to validate that an integer is
 **                entered, and performs a range validation to check whether
 **                entered integer is a valid menu option.
 **                Loops until a valid choice is selected.
 **                Returns integer value of the menu choice that was selected.
 ***/

#include "mainMenuSelection.hpp"
#include "validInt.hpp"
#include <iostream>

int mainMenuSelection()
{
   // Declare variables
   const int CHOICES = 2;
         int selection;

   // Define array
   std::string choices[CHOICES] = {"Play", "Exit"};

   // Display menu
   std::cout << "\n\n  * *  Main Menu  * *\n\n";
   for (int i = 0; i < CHOICES; i++)
   {
      std::cout << (i + 1) << ") " << choices[i] << "\n";
   }
   std::cout << "\n\n";

   // Prompt user for int
   std::cout << "What would you like to do?\n";
   std::cout << "Enter a number in the range 1-" << CHOICES << ": ";
   selection = validInt(1, CHOICES);

   return selection;
}
