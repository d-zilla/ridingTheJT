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

#ifndef COASTAL_HPP
#define COASTAL_HPP

#include "Space.hpp"

class Coastal : public Space
{
   protected:
      std::vector<Space*> ports;
      std::vector<int> travelTime;

   public:
      Coastal(std::string, bool);
      virtual void addPort(Space*, int);
      virtual Space* takeShip(int, int&);
      virtual void takePhotos(int&);
      virtual Space* welcome(int&);
};

#endif
      
      
