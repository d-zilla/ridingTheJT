/***
 ** Program name:  main() function for Final Project
 ** Author:        Dario Gerussi
 ** Date:          10/09/2019
 ** Description:   Main driver function for Riding the JT game.
 **                Uses Space and Map class objects and functions for displaying
 **                the menus and validating input.
 ***/

#include "Game.hpp"
#include "mainMenuSelection.hpp"

void welcome();
void enter();

int main()
{
   // Game banner
   welcome();

   while (mainMenuSelection() == 1) // 1 = play, 2 = exit
   {
      Game();
   } 

   return 0;
}

// Displays the game's opening banner
void welcome()
{
   std::cout << "\n\n              = = = = = = = = = = = = = = =\n"; 
   std::cout <<     "              = = =   Riding the JT   = = =\n";
   std::cout <<     "              = = = = = = = = = = = = = = =\n";
   std::cout <<     "  The traveling salesman: Photography in Japan edition\n";
}

