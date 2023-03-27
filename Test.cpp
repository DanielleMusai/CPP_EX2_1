#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

using namespace ariel;

TEST_CASE("Test 1: ") { 
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_EQ(p1.stacksize(),26);
    CHECK_EQ(p2.stacksize(),26);
};
    

TEST_CASE("Test 2: ") { 
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    REQUIRE((p2.cardesTaken() == 52 || p2.stacksize() == 0));
}


TEST_CASE("Test 3: ") { 
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    REQUIRE((p1.stacksize() == 0 || p1.stacksize() == 52));
}

TEST_CASE("Test 4: ") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    REQUIRE((p1.stacksize() == 25 ||  p1.stacksize() == 27 ));

}

TEST_CASE("Test 5: ") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    REQUIRE(( p2.stacksize() == 27 || p2.stacksize() == 25 ));

}


TEST_CASE("Test 6: ") {
    Player p1("Alice"); 
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    CHECK_NOTHROW(game.printLastTurn()); // make sure this method doesn't throw any exception
}

TEST_CASE("Test 7: ") {
    Player p1("Alice"); 
    Player p2("Bob");
    Game game(p1, p2);
    game.playTurn();
    CHECK_NOTHROW(game.printLog()); //  make sure this method doesn't throw any exception
}



TEST_CASE("Test 8: "){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }
    CHECK_NOTHROW(game.printLastTurn()); //testing with multiple turns played
    }



TEST_CASE("Test 9: ") { 
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    REQUIRE((p1.stacksize() == 0 || p2.stacksize() == 0)); //  p1 or p2 should have no cards left
}


TEST_CASE("Test 10: ") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();// Play all turns to finish the game
    CHECK_THROWS(game.playTurn());// Verify that an exception is thrown when playTurn is called after the game done
  }

TEST_CASE("Test 11: ") { 
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_THROWS(game.printLastTurn()); 
    }

TEST_CASE("Test 12: ") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();

    CHECK((p1.cardesTaken() == 0 || p1.cardesTaken() == 1));
};

TEST_CASE("Test 13: ") { 
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();

    CHECK((p2.cardesTaken() == 0 || p2.cardesTaken() == 1));// the opposite from test 13 
};

TEST_CASE("Test 14: ") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    game.playTurn();

    CHECK((p1.cardesTaken() == 0 || p1.cardesTaken() == 1 || p1.cardesTaken() == 2));
};


TEST_CASE("Test 15: ") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    for (int i = 0; i < 4; i++)
    {
        game.playTurn();
    }
    CHECK((p1.cardesTaken() == 0 || p1.cardesTaken() == 1 || p1.cardesTaken() == 2 || p1.cardesTaken() == 3|| p1.cardesTaken() == 4));
    
};


TEST_CASE("Test 16: ") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printWiner());
}


TEST_CASE("Test 17: ") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_THROWS(game.printStats());
}


TEST_CASE("Test 18: ") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
  //playTurn method updates the game state
    int prevStackSize1 = p1.stacksize();
    int prevStackSize2 = p2.stacksize();
    game.playTurn();
    int newStackSize1 = p1.stacksize();
    int newStackSize2 = p2.stacksize();
    CHECK((newStackSize1 < prevStackSize1 || newStackSize2 < prevStackSize2));
    
    }


TEST_CASE("Test 19: ") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
  //playTurn method updates the game state
    int prevCardsTaken2 = p2.cardesTaken();
    int prevCardsTaken1 = p1.cardesTaken();
    game.playTurn();
    int newCardsTaken2 = p2.cardesTaken();
    int newCardsTaken1 = p1.cardesTaken();
    CHECK((newCardsTaken2 > prevCardsTaken2 || newCardsTaken1 > prevCardsTaken1));
}

TEST_CASE("Test 20: "){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();
    CHECK_NOTHROW(game.printWiner()); 
    }
