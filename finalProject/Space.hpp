/***
 ** Program name:  Space class
 ** Author:        Dario Gerussi
 ** Date:          12/09/2019
 ** Description:   Parent class for different types of cities.
 **                Contains a city's basic info and its neighboring cities.
 ***/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "validInt.hpp"
#include "yesOrNo.hpp"
#include "compass.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

class Space
{
   protected:
      std::string name;
      bool photoCity;
      bool hasPort;
      Space* north;
      Space* east;
      Space* south;
      Space* west;
      bool firstVisit;
      bool photosTaken;
      bool clearDay;

   public:
      Space(std::string, bool);
      void setLinks(Space*, Space*, Space*, Space*);
      virtual void takePhotos(int&) = 0;
      virtual Space* welcome(int&) = 0;
      Space* move();
      std::string getName();
      bool arePhotosTaken();
      virtual void addPort(Space*, int) = 0;
      virtual Space* takeShip(int, int&) = 0; 
};

#endif 
