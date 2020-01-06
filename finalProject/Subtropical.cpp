/***
 ** Program name:  Subtropical class
 ** Author:        Dario Gerussi
 ** Date:          12/10/2019
 ** Description:   Child of Coastal and Space classes.
 **                Inherits everything from parent classes.
 **                Implements its own versions of takePhotos() and welcome().
 **                Adds the member variable clearDays.
 ***/

#include "Subtropical.hpp"

// Constructor that sets clearDays to 0
Subtropical::Subtropical(std::string name, bool phCity) : Coastal(name, phCity)
{
   clearDays = 0;
}

// Accepts the time tracker
// Updates it with time spent taking pictures
void Subtropical::takePhotos(int&)
{
   // Declare variables
   int weather,  // 1 = overcast, 2-3 = clear
       day = 0;

   while (clearDays < 2)
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
                 if (day == 1)
                 {
                    std::cout << "First day and it's already rainy.\n";
                    std::cout << "Might as well relax while you're here..";
                 }
                 else
                 {
                    std::cout << "An extra day in paradise..\n";
                    std::cout << "but will we finish in time?";
                 }
                 break;
         case 2:
         case 3: std::cout << "clear\n";
                 if (day == 1)
                 {
                    clearDay = true;
                    clearDays++;
                    std::cout << "Good start so far.\n";
                    std::cout << "One more day of sun is all we need..";
                 }
                 else if (clearDays == 0)
                 {
                    clearDay = true;
                    clearDays++;
                    std::cout << "Our first sun here in " << name << ".\n";
                    std::cout << "Let's see what tomorrow brings..";
                 }
                 else
                 {
                    clearDays++;
                    std::cout << "Got 'em!\n";
                    std::cout << "Pictures of " << name << " are in the bag.";
                 }
      }
   }
}

// Accepts the time of day to determine greeting opener
// Then proceeds to ask user what to do
// Returns the city to which is being traveled 
Space* Subtropical::welcome(int& time)
{
   Space* destination;
   int selection;  // For deciding to which port to travel

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
      std::cout << "\n\nWelcome to warm city of " << name << ", home to\n";
      std::cout << "beautiful beaches and surrounded by subtropical forests.";
      std::cout << "\n\n";
   }
   else 
   {
      if ((name == "Kagoshima") && photosTaken)
      {
         std::cout << "You are in Kagoshima and still have work to do ";
         std::cout << "elsewhere.\n\n";
      } 
      std::cout << "\n\nWelcome back to " << name << ".\n\n";
   }
   
   // Check whether eligible to take photos
   if (photoCity && (!photosTaken))
   {
      std::cout << "You have not taken photos here yet.\n";
      std::cout << "Would you like to do so at this time? (Y/N): "; 
      if (yesOrNo())
      {
         takePhotos(time);
         if (name == "Kagoshima")
         {
            std::cout << "\n\nReady to double-check your bag of pictures??";
            std::cout << " (Y/N): ";
            if (yesOrNo())
            {
               std::cout << "\n\n";
               destination =  this;
            }
            else
            {
               std::cout << "\n\nWhere would you like to go?\n\n";
            } 
         }
      }
      else
      {
         std::cout << "Where to, then?\n\n";
      }
   }

   // Display transportation options 
   // if this is a port city
   if (name != "Fukuoka")
   {
      std::cout << "This city offers train services to:";
      if (north != NULL)
      {
         std::cout << "\nNorth) " << north->getName();
      }
      if (east != NULL)
      {
         std::cout << "\nEast) " << east->getName();
      }
      if (south != NULL)
      {
         std::cout << "\nSouth) " << south->getName();
      }
      if (west != NULL)
      {
         std::cout << "\nWest) " << west->getName();
      }

      std::cout << "\n\nYou can also take a ship to: ";
      for (int i = 0; i < ports.size(); i++)
      {
         std::cout << "\nPort " << (i + 1) << ") " << (ports.at(i))->getName();
      }

      std::cout << "\n\nWould you like to travel by sea? (Y/N): ";
      if (yesOrNo())
      {
         if (ports.size() == 1)
         {
            destination = takeShip(0, time);
         }
         else
         {
            std::cout << "Enter the port number of the city to which to sail: ";
            selection = (validInt(1, ports.size()) - 1);
            destination = takeShip(selection, time);
         }
      }
      else
      {
         time++;
         destination = move();
      }
   }
   else
   {
      time++;
      destination = Space::move();
   }

   return destination;
}
