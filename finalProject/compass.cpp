/***
 ** Program name:  compass() function
 ** Author:        Dario Gerussi
 ** Date:          12/10/2019
 ** Description:   Header file for compass() function declaration.
 **                Prompts user to enter input.
 **                Returns which cardinal direction was chosen.
 ***/

#include "compass.hpp"
#include <iostream>
#include <cctype>

int compass(bool north, bool east, bool south, bool west)
{
   // Declare variables
   std::string input;
           int direction;        
          bool valid = false;
          char character;

   // Prompt user for input
   while (!valid)
   {
      std::getline(std::cin, input);
      
      if (input.size() > 1 || input.size() == 0)
      {
         std::cout << "Please enter a single character: ";
      }
      else 
      {
         character = std::toupper(input[0]);
         if (north && (character == 'N'))
         {
            valid = true;
            direction = 1;
         }
         else if (east && (character == 'E'))
         {
            valid = true;
            direction = 2;
         }
         else if (south && (character == 'S'))
         {
            valid = true;
            direction = 3;
         }
         else if (west && (character == 'W'))
         {
            valid = true;
            direction = 4;
         }
         else
         {
            std::cout << "Please enter a valid letter: ";
         }
      }
   } 

   return direction;
} 

