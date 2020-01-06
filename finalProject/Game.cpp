/***
 ** Program name:  Game class
 ** Author:        Dario Gerussi
 ** Date:          12/10/2019
 ** Description:   Driver class for Riding the JT game.
 **                Connects together the various Space classes and interfaces
 **                with them.
 ***/

#include "Game.hpp"

// Initialize constants
const int Game::MAX_DAYS = 28;
const int Game::CHUNKS = 3;
const int Game::ROLLS = 7;

// Constructor that gets the game going
Game::Game()
{
   // Set time to 0
   timeUsed = 0;
    
   // Prompt user whether to display game intro
   std::cout << "\n\nWould you like an introduction to the game? (Y/N): ";
   if (yesOrNo())
   {
      introduction();
   }

   // Create map
   createCities();
   linkCities(); 

   // Start in Tokyo
   player = Tokyo;

   // Play until time is up or
   // player has a full bag in Kagoshima
   while ((timeUsed < (MAX_DAYS * CHUNKS)) &&
          (!((bagOfPictures.size() == ROLLS) && (player == Kagoshima))))
   {
      player = player->welcome(timeUsed);
      checkBag();
   }
   std::cout << "\n\nTime used: " << timeUsed << " days\n";
   std::cout << "Destinations captured: " << bagOfPictures.size();
   std::cout << " of 7"; 
   if ((bagOfPictures.size() == 7) && (player == Kagoshima)
       && (timeUsed < (MAX_DAYS * CHUNKS)))
   {
      std::cout << "\n\nCongrats! You've earned a trip to Okinawa!\n\n";
   }
   else
   {
      std::cout << "\n\nGood luck in finding a new job!\n\n";
   }
}

// Creates each city
void Game::createCities()
{
   Sapporo = new Coastal("Sapporo", true);
   Hakodate = new Coastal("Hakodate", false);
   Aomori = new Coastal("Aomori", false);
   Akita = new Coastal("Akita", false);
   Morioka = new Interior("Morioka", false);
   Niigata = new Coastal("Niigata", false);
   Fukushima = new Interior("Fukushima", true);
   Toyama = new Coastal("Toyama", false);
   Tokyo = new Coastal("Tokyo", true);
   Kyoto = new Interior("Kyoto", true);
   Nagoya = new Coastal("Nagoya", false);
   Osaka = new Coastal("Osaka", true);
   Hiroshima = new Coastal("Hiroshima", false);
   Matsuyama = new Coastal("Matsuyama", false);
   Fukuoka = new Subtropical("Fukuoka", true);
   Oita = new Subtropical("Oita", false);
   Nagasaki = new Subtropical("Nagasaki", false);
   Kumamoto = new Subtropical("Kumamoto", false);
   Kagoshima = new Subtropical("Kagoshima", true);
   Miyazaki = new Subtropical("Miyazaki", false);
}

// Links all the cities together
// via train and ships
void Game::linkCities()
{
   Sapporo->setLinks(NULL, NULL, Hakodate, NULL);
   Sapporo->addPort(Akita, 3);
   Sapporo->addPort(Niigata, 4);

   Hakodate->setLinks(Sapporo, NULL, NULL, NULL);
   Hakodate->addPort(Aomori, 1);
   Hakodate->addPort(Tokyo, 4);
   Hakodate->addPort(Nagoya, 5);
   Hakodate->addPort(Osaka, 6);

   Aomori->setLinks(NULL, Morioka, NULL, Akita);
   Aomori->addPort(Hakodate, 1);

   Akita->setLinks(Aomori, Morioka, Niigata, NULL);
   Akita->addPort(Sapporo, 3);

   Morioka->setLinks(Aomori, NULL, Fukushima, Akita);

   Niigata->setLinks(Akita, Fukushima, Toyama, NULL);
   Niigata->addPort(Sapporo, 4);

   Fukushima->setLinks(Morioka, NULL, Tokyo, Niigata);

   Toyama->setLinks(Niigata, Tokyo, Kyoto, NULL);

   Tokyo->setLinks(Fukushima, NULL, Nagoya, Toyama);
   Tokyo->addPort(Hakodate, 4);
   Tokyo->addPort(Nagoya, 1);
   Tokyo->addPort(Osaka, 2);

   Kyoto->setLinks(Toyama, Nagoya, Osaka, Hiroshima);
   
   Nagoya->setLinks(Tokyo, NULL, Osaka, Kyoto);
   Nagoya->addPort(Tokyo, 1);
   Nagoya->addPort(Hakodate, 5);

   Osaka->setLinks(Kyoto, Nagoya, Matsuyama, Hiroshima);
   Osaka->addPort(Hakodate, 6);
   Osaka->addPort(Tokyo, 2);
   Osaka->addPort(Nagoya, 1);
   Osaka->addPort(Miyazaki, 2);

   Hiroshima->setLinks(Kyoto, Osaka, Fukuoka, NULL);
   Hiroshima->addPort(Matsuyama, 1);
   Hiroshima->addPort(Oita, 1);

   Matsuyama->setLinks(Osaka, NULL, NULL, NULL);
   Matsuyama->addPort(Hiroshima, 1);
   Matsuyama->addPort(Oita, 1);

   Fukuoka->setLinks(Hiroshima, Oita, Kumamoto, Nagasaki);

   Oita->setLinks(Fukuoka, NULL, Miyazaki, Kumamoto);
   Oita->addPort(Hiroshima, 1);
   Oita->addPort(Matsuyama, 1);

   Nagasaki->setLinks(Fukuoka, NULL, NULL, NULL);
   Nagasaki->addPort(Kumamoto, 1);
   Nagasaki->addPort(Kagoshima, 1);

   Kumamoto->setLinks(Oita, Miyazaki, Kagoshima, Fukuoka);
   Kumamoto->addPort(Nagasaki, 1);

   Kagoshima->setLinks(Kumamoto, Miyazaki, NULL, NULL);
   Kagoshima->addPort(Nagasaki, 1);
  
   Miyazaki->setLinks(Oita, NULL, Kagoshima, Kumamoto);
   Miyazaki->addPort(Osaka, 2);
}

// Checks where all pictures have been taken
void Game::checkBag()
{
   bagOfPictures.clear();
   if (Tokyo->arePhotosTaken())
   {
      bagOfPictures.push_back("Tokyo");
   }
   if (Kyoto->arePhotosTaken())
   {
      bagOfPictures.push_back("Kyoto");
   }
   if (Osaka->arePhotosTaken())
   {
      bagOfPictures.push_back("Osaka");
   }
   if (Fukushima->arePhotosTaken())
   {
      bagOfPictures.push_back("Fukushima");
   }
   if (Sapporo->arePhotosTaken())
   {
      bagOfPictures.push_back("Sapporo");
   }
   if (Fukuoka->arePhotosTaken())
   {
      bagOfPictures.push_back("Fukuoka");
   }
   if (Kagoshima->arePhotosTaken())
   {
      bagOfPictures.push_back("Kagoshima");
   }
}

// Displays the game background, goals, and rules
void Game::introduction()
{
  std::cout << "\n\n              ^  ^  ^   Introduction   ^  ^  ^\n\n";
  std::cout << "It's springtime 1987, a few days after the privately owned,\n";
  std::cout << "for-profit company Japan Tracks (JT) took over most of what\n";
  std::cout << "the government-owned national railway system had left after\n";
  std::cout << "years of management inefficiences and profit losses\n\n";

  std::cout << "As part of the rebranding effort, they hired you to go around\n"
            << "and take exquisite photos of Japan to boost domestic tourism,\n"
            << "and thus ridership on the JT lines.\n\n";
  enter();


  std::cout << "You will begin your journey from Tokyo, where the JT HQ is\n";
  std::cout << "located. Your assignment is to capture photos in and around\n";
  std::cout << "3 of the 4 major cities - Tokyo, Kyoto, and Osaka - as well\n";
  std::cout << "as the mountainous Sapporo in the north, the idyllic villages\n"
            << "surrounding the interior city of Fukushima, and the subtropical"
            << "\ncities of Fukuoka and Kagoshima.\n\n";
  enter(); 


  std::cout << "To get to Hokkaido, the island on which Sapporo is located,\n";
  std::cout << "you will need to take a ship from one of the port cities. You\n"
            << "do not have to return to Honshu, the main island, the same\n";
  std::cout << "way from which you came. You do, however, have to end your\n";
  std::cout << "trip in Kagoshima.\n\n";
  enter();


  std::cout << "As part of the internal rebranding, you will have limited\n";
  std::cout << "resources to complete your assignment. You are given 7 rolls\n";
  std::cout << "of empty film for your camera and " << MAX_DAYS;
  std::cout << " days to complete";
  std::cout << "\neverything.\n\n";

  std::cout << "If you finish taking pictures in Kagoshima on time, you will\n";
  std::cout << "be rewarded with a weeklong trip to Okinawa, flying out of\n";
  std::cout << "Kagoshima. If you don't make it on time, then you will be fired"
            << "\nand all of your work will be destroyed.\n\n";
  enter();


  std::cout << "Each day will have a morning, afternoon, and evening; thus,\n";
  std::cout << "you will have " << MAX_DAYS * CHUNKS; 
  std::cout << " units of time to work with. Traveling from\n";
  std::cout << "city to its neighboring one by train will cost 1 unit. Taking";
  std::cout << "\nphotos will cost 6. Sea voyages will cost varying amounts,\n";
  std::cout << "depending on the distance.\n\n";
  enter();


  std::cout << "While in subtropical cities, all picture taking must take place"
            << "\nduring clear days. Therefore, it will cost 3 units of extra";
  std::cout << "\ntime per rainy day. For cities of the interior, you must take"
            << "\npictures during one clear day and one overcast day. Non-\n";
  std::cout << "subtropical coastal cities must have at least one day of\n";
  std::cout << "clear weather during your stay.\n\n";
  enter();
}  

// Prompts user to press enter when they are ready
void Game::enter()
{
  std::cout << "Press enter to continue..\n\n";
  std::cin.get();
}   
