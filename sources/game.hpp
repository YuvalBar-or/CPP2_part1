#pragma once

#include "player.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel{
   class Game{
        private:
            Player &p1; 
            Player &p2;

        public:
            Game (Player &player1, Player &player2);
            void playTurn();
            void printLastTurn();
            void playAll();
            string printWiner();
            void printLog();
            void printStats();

    };
}


