#include <iostream>
#include "doctest.h"
#include "sources/card.hpp"
#include "sources/player.hpp"
#include "sources/game.hpp"
using namespace ariel; 
using namespace std;

TEST_CASE("player checks"){
    Player p1("Alice");
    Player p2("Bob");
    CHECK_THROWS(Player (NULL));

}

TEST_CASE("game checks"){
    Player p1("Alice");
    Player p2("Bob");
    CHECK_THROWS(Game(p2,p2)); 

    Game game2(p1,p2);
    CHECK_THROWS(Game(p1,p2));
    CHECK_THROWS(game2.printLog());

    CHECK (p1.stacksize()==p2.stacksize());
    game2.playAll();
    game2.playAll();
    game2.playTurn();
    CHECK (p1.stacksize()==0);
    CHECK (p2.stacksize()==0);
    CHECK (p1.stacksize()!=p2.stacksize());
    CHECK (p1.cardesTaken()+p2.cardesTaken()==52);
    CHECK_NOTHROW(game2.playAll());
    

}

TEST_CASE("card checks"){
    Player p1("Alice");
    Player p2("Bob");
    Game game3(p1,p2);

    CHECK(p1.stacksize()==0);
    CHECK(p1.stacksize()==26);
    CHECK(p2.stacksize()==0);
    CHECK(p2.stacksize()==26);

    game3.playAll();
    game3.playAll();
    if (p1.stacksize()==0){
        CHECK(game3.printWiner()== "Bob");
    }
    CHECK(game3.printWiner()== "Alice");

    bool stacks = (p1.stacksize()<26)||(p2.stacksize()<26);
    CHECK(stacks);

    bool cards = (p1.cardesTaken()>=2) || (p2.cardesTaken()>=2);
    CHECK(cards);

    CHECK(p2.cardesTaken() >= 26);
    CHECK(p1.cardesTaken() >= 26);
  
    
}

