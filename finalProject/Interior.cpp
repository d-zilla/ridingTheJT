/***
 ** Program name:  Interior class
 ** Author:        Dario Gerussi
 ** Date:          12/09/2019
 ** Description:   Child of Space class.
 **                Inherits everything from Space class.
 **                Implements its own versions of Space's virtual functions.
 **                Adds an overcastDay member variable.
 ***/

#include "Interior.hpp"

// Constructor that sets overcast status
Interior::Interior(std::string name, bool majorCity) : Space(name, majorCity)
{
   overcastDay = false;   // Whether pictures were taken during an overcast day
}

// Takes pictures, making sure one day is 
// clear and the other is overcast
// Updates the time tracker passed to it
void Interior::takePhotos(int& time)
{
   // Declare variables
   int weather,  // 1 = overcast, 2-3 = clear
       day = 0;

   while ((!clearDay) || (!overcastDay))
   {
      // Update day
      day++;
      std::cout << "\n\n** Day " << day << " **\n";
      std::cout << "Weather: "; 

      // Determine weather
      weather = (std::rand() % 3) + 1;
      switch (weather)
      {
         case 1: std::cout << "overcast\n";
                 if (overcastDay)
                 {
                    std::cout << "Another cloudy day.\nWaiting for some sun..";
                 }
                 else
                 {
                    overcastDay = true;
                    std::cout << "Pictures taken. On we go..";
                 }
                 break;
         case 2:
         case 3: std::cout << "clear\n";
                 if (clearDay)
                 {
                    std::cout << "Sun yet again.\n";
                    std::cout << "Patiently waiting for clouds..";
                 }
                 else
                 {
                    clearDay = true;
                    std::cout << "Taken are the pictures. Onwards..";
                 }
                 break;
      }
   }
   photosTaken = true;
   time += (day * 3);
}

// Accepts the time of day to determine greeting opener
// Then proceeds to ask user what to do
// Returns the city to which is being traveled 
Space* Interior::welcome(int& time)
{
   std::cout << "\n\n\n = = = Time used: ";
   std::cout << (time/3) << "." << ((time%3)*3) << " days = = =";
   int time2 = time;
   int timeOfDay = (time2 % 3) + 1;
   switch (timeOfDay)
   {
      case 1: std::cout << "\n\nGood morning! ^_^";
              break;
      case 2: std::cout << "\n\nGood afternoon! ^_^";
              break;
      case 3: std::cout << "\n\nGood evening! ^_^";
   }

   // Check whether first visit
   if (firstVisit)
   {
      firstVisit = false;
      std::cout << "\n\nWelcome to " << name << ", one of the larger cities\n";
      std::cout << "nestled in the country's interior.\n\n";
   }
   else 
   {
      std::cout << "\n\nWelcome back to " << name << ".\n\n";
   }
   
   // Check whether eligible to take photos
   if (photoCity && (!photosTaken))
   {
      std::cout << "You have not taken photos here yet.\n";
      std::cout << "Would you like to do so at this time? (Y/N): "; 
      if (yesOrNo())
      {
         Interior::takePhotos(time);
      }
      else
      {
         std::cout << "\n\nMoving on..\n\n";
      }
   }
   
   // Ask to where user wants to move
   time += 1;
   return move();
}

// dummy functions //
Space* Interior::takeShip(int a, int& b)
{
}

void Interior::addPort(Space*, int)
{
}
