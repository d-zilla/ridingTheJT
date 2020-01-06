/***
 ** Program name:  validInt() function
 ** Author:        Dario Gerussi
 ** Date:          10/09/2019
 ** Description:   Implementation file for validInt() function definition.
 **                Prompts user to enter input.
 **                Returns whether the input is a valid integer.
 ***/

#include "validInt.hpp"
#include <iostream>
#include <string>
#include <cstdlib>


// General validation for int
int validInt()
{
   // Declare variables
   std::string input;
          char *cPtr;
          bool valid;
           int integer;
   
   // Prompt user for input
   do
   {
      valid = true;
      std::getline(std::cin, input);
      cPtr = new char[input.size()];      
      
      // Check whether first character is digit or - sign
      if ( (!(std::isdigit(input[0]))) && (input[0] != '-'))
      {
         valid = false;
      }

      // Check whether remaining characters are digits
      for (int i = 1; i < input.size(); i++)
      {
         if (!(std::isdigit(input[i])))
         {
            valid = false;
         }
      }

      if (!valid)
      {
         std::cout << "Please enter a valid integer value: ";
      }
      else
      {
         for (int i = 0; i < input.size(); i++)
         {
            cPtr[i] = input[i];
         }
         integer = std::atoi(cPtr);
      }

      // Deallocate cPtr memory
      delete [] cPtr;
      cPtr = NULL;

   } while (!valid);

   return integer;
}


// Accepts two ints representing
// the min and max values of a range
// within which a value is valid
int validInt(int MIN, int MAX)
{
   int input;

   input = validInt();
   while (input < MIN || input > MAX)
   {
      std::cout << "Please enter an integer in the range of ";
      std::cout << MIN << "-" << MAX << ": ";
      input = validInt();
   }

   return input;
}
