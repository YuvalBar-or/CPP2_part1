#pragma once 

#include <iostream>
#include <string>
#include "card.hpp"
using namespace std;
using namespace ariel;

class Player {
    string name;
    public:
        Player(string);
        int stacksize();
        int cardesTaken();

};
