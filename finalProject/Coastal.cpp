/***
 ** Program name:  Coastal class
 ** Author:        Dario Gerussi
 ** Date:          12/10/2020
 ** Description:   Child of Space class. Parent of Subtropical class.
 **                Inherits everything from space.
 **                Implements its own versions of takePhotos() and greeting().
 **                Adds member variables and functions needed for a fully
 **                functioning port city.
 ***/

#include "Coastal.hpp"

// Constructor
Coastal::Coastal(std::string name, bool photoCity) : Space(name, photoCity)
{
}

// Accepts a port destination 
// and time it takes to get there
// to add as a linking port
void Coastal::addPort(Space* port, int time)
{
   ports.push_back(port);
   travelTime.push_back(time);
}

// Accepts the port destination number
// and the reference to the total time spent
// Updates the total time spent and
// returns the pointer to the new current location
Space* Coastal::takeShip(int selection, int& time)
{
   time += travelTime.at(selection);
   return ports.at(selection);
}

// Accepts the time tracker
// Updates it with time spent taking pictures
void Coastal::takePhotos(int& time)
{
   // Declare variables
   int weather,  // 1 = overcast, 2-3 = clear
       day = 0;

   while ((!clearDay) || (day < 2))
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
                 if ((day > 1) && (!clearDay))
                 {
                    std::cout << "Overcast pictures are fine, but we\n";
                    std::cout << "need at least one sunny day here.."; 
                 }
                 else
                 {
                    std::cout << "It is destined for there to be\n";
                    std::cout << "overcast pictures in " << name << ".";
                    if (!clearDay)
                    {
                       std::cout << "\nNow we wait for sun.";
                    }
                 }
                 break;
         case 2:
         case 3: std::cout << "clear\n";
                 if (day == 1)
                 {
                    clearDay = true;
                    std::cout << "Clear skies on your first day of ";
                    std::cout << "pictures here.\n";
                    std::cout << "Any weather is acceptable tomorrow.";
                 }
                 else if (!clearDay)
                 {
                    clearDay = true;
                    std::cout << "Sunny pictures taken.\n";
                    std::cout << "On to the next city..";
                 }
                 else
                 {
                    std::cout << "Two days of sun in " << name << ".\n";
                    std::cout << "That works. Let us move on..";
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
Space* Coastal::welcome(int& time)
{
   Space* destination;
   int selection;  // For deciding to which port to travel
   
   std::cout << "\n\n\n = = = Time used: ";
   std::cout << (time/3) << "." << ((time%3) * 3) << " days = = =";
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
      std::cout << "\n\nWelcome to the coastal city of " << name << ".\n";
      if (name == "Toyama")
      {
         std::cout << "While not a port city, the waterfront views here\n";
         std::cout << "are just as beautiful as elsewhere.\n\n";
      }
      else
      {
         std::cout << "This city offers maritime transportation as well\n";
         std::cout << "as great views of the sea.\n\n";
      }
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
         takePhotos(time);
      }
      else
      {
         std::cout << "Where to, then?\n\n";
      }
   }

   // Display transportation options 
   // if this is a port city
   if (name != "Toyama")
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
      destination = move();
   }

   return destination;
}
