/***
 ** Program name:  yesOrNo() function
 ** Author:        Dario Gerussi
 ** Date:          10/11/2019
 ** Description:   Implementation file for yesOrNo() function definition.
 **                Prompts user for input.
 **                Checks whether value is y, Y, n, or N.
 **                If not, loops until valid input is entered.
 **                Returns capitalized valid character that was entered.
 ***/

#include "yesOrNo.hpp"
#include <iostream>
#include <cctype>

bool yesOrNo()
{
   // Declare variables
   std::string input;
          bool valid,        // Used for loop
               yes = false;  // True if either y or Y were entered
          char character;

   // Prompt user for input
   do
   {
      valid = true;
      std::getline(std::cin, input);
      
      if (input.size() > 1 || input.size() == 0)
      {
         valid = false;
         std::cout << "Please enter a single character 'Y' or 'N': ";
      }
      else 
      {
         character = std::toupper(input[0]);
         if (character != 'Y' && character != 'N')
         {
            valid = false;
            std::cout << "Please enter either 'Y' or 'N': ";
         }
      }
   } while (!valid);

   if (character == 'Y')
   {
      yes = true;
   }
   return yes;
} 

