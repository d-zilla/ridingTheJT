/***
 ** Program name:  Interior class
 ** Author:        Dario Gerussi
 ** Date:          12/09/2019
 ** Description:   Child of Space class.
 **                Inherits everything from Space class.
 **                Implements its own versions of Space's virtual functions.
 **                Adds an overcastDay member variable.
 ***/

#ifndef INTERIOR_HPP
#define INTERIOR_HPP

#include "Space.hpp"

class Interior : public Space
{
   private: 
      bool overcastDay;

   public:
      Interior(std::string, bool);
      void takePhotos(int&);
      Space* welcome(int&);
      Space* takeShip(int, int&);
      void addPort(Space*, int);
};

#endif
