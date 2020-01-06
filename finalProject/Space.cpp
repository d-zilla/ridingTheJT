/***
 ** Program name:  Space class
 ** Author:        Dario Gerussi
 ** Date:          12/09/2019
 ** Description:   Parent class for different types of cities.
 **                Contains a city's basic info and its neighboring cities.
 ***/

#include "Space.hpp"

// Main constructor that sets the name of the city,
// whether it's a major city, default interactive flags,
// and creates a seed from which to generate random numbers
Space::Space(std::string name, bool photoCity)
{
   // City data
   this->name = name;
   this->photoCity = photoCity;

   // Random seed
   std::srand(std::time(00));

   // Interactive data
   firstVisit = true;
   photosTaken = false;
   clearDay = false;       // Whether pictures were taken during a clear day
}

// Sets to which cities this city is linked by train
void Space::setLinks(Space* north, Space* east, Space* south, Space* west)
{
   this->north = north;
   this->east = east;
   this->south = south;
   this->west = west; 
}

// Displays a greeting based
// on the time of day
void greeting(int time)
{
   int timeOfDay = (time % 3) + 1;
   switch (timeOfDay)
   {
      case 1: std::cout << "Good morning! ^_^";
              break;
      case 2: std::cout << "Good afternoon! ^_^";
              break;
      case 3: std::cout << "Good evening! ^_^";
   }
}

// Prompts user to where they want to travel by train
// Returns the pointer of the city to which is being traveled
Space* Space::move()
{
   Space* destination;
   int direction;
   bool nor = false,
        eas = false,
        sou = false,
        wes = false; 

   std::cout << "\n\n";
   std::cout << "      N\n";
   std::cout << "      |\n";
   std::cout << "   W --- E\n";
   std::cout << "      |\n";
   std::cout << "      S\n\n";
   std::cout << "Available options:";
   if (north != NULL)
   {
      std::cout << "\nN) " << north->getName();
      nor = true;
   }
   if (east != NULL)
   {
      std::cout << "\nE) " << east->getName();
      eas = true;
   }
   if (south != NULL)
   {
      std::cout << "\nS) " << south->getName();
      sou = true;
   }
   if (west != NULL)
   {
      std::cout << "\nW) " << west->getName();
      wes = true;
   }

   // Prompt user for direction of travel
   std::cout << "\n\nEnter the letter representing the cardinal direction\n";
   std::cout << "towards which you want to travel: ";
   direction = compass(nor, eas, sou, wes);
   
   // Return pointer of city towards which 
   // will be traveled
   switch (direction)
   {
      case 1: destination = north;
              break;
      case 2: destination = east;
              break;
      case 3: destination = south;
              break;
      case 4: destination = west;
              break;
   }

   return destination; 
}

// Returns name of city
std::string Space::getName()
{
   return name;
}

// Returns whether photos are taken 
// in this city
bool Space::arePhotosTaken()
{
   return photosTaken;
}
