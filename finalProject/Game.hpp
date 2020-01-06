/***
 ** Program name:  Game class
 ** Author:        Dario Gerussi
 ** Date:          12/10/2019
 ** Description:   Driver class for Riding the JT game.
 **                Connects together the various Space classes and interfaces
 **                with them.
 ***/

#ifndef GAME_HPP
#define GAME_HPP

#include "Interior.hpp"
#include "Coastal.hpp"
#include "Subtropical.hpp"

class Game
{
   private:
      // Constants
      static const int MAX_DAYS;
      static const int CHUNKS;  // Chunks in a day; morning, afternoon, evening
      static const int ROLLS;   // Rolls of film for camera

      // Container
      std::vector<std::string> bagOfPictures;

      // Variables 
      int timeUsed;

      // Pointers
      Space* player;
      Space* Sapporo;
      Space* Hakodate;
      Space* Aomori;
      Space* Akita;
      Space* Morioka;
      Space* Niigata;
      Space* Fukushima;
      Space* Toyama;
      Space* Tokyo;
      Space* Kyoto;
      Space* Nagoya;
      Space* Osaka;
      Space* Hiroshima;
      Space* Matsuyama;
      Space* Fukuoka;
      Space* Oita;
      Space* Nagasaki;
      Space* Kumamoto;
      Space* Kagoshima;
      Space* Miyazaki;

      // Functions
      void introduction();
      void enter();
      void createCities();
      void linkCities();
      void checkBag();

   public:
      Game();
};

#endif
