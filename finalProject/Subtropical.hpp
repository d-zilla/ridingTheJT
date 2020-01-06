/***
 ** Program name:  Subtropical class
 ** Author:        Dario Gerussi
 ** Date:          12/10/2019
 ** Description:   Child of Coastal and Space classes.
 **                Inherits everything from parent classes.
 **                Implements its own versions of takePhotos() and welcome().
 **                Adds the member variable clearDays.
 ***/

#ifndef SUBTROPICAL_HPP
#define SUBTROPICAL_HPP

#include "Coastal.hpp"

class Subtropical : public Coastal
{
   private:
      int clearDays;

   public:
      Subtropical(std::string, bool);
      void takePhotos(int&);
      Space* welcome(int&);
};

#endif
