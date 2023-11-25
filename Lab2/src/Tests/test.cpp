#include <gtest/gtest.h>
#include "Controller/controller.hpp"


std::string EXAMPLE = "#Life 1.06\n#N second\n#B3/S23\n0 0\n2 0\n1 1\n2 1\n1 2";

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TestGame, test_1){
    Game game(30 , 30);
    
    EXPECT_TRUE(game.GiveSizeX() == 30);
    EXPECT_TRUE(game.GiveSizeY() == 30);

    game.RecountSize(40, 40);

    EXPECT_TRUE(game.GiveSizeX() == 40);
    EXPECT_TRUE(game.GiveSizeY() == 40);

    game.TakeCell(40);

    EXPECT_TRUE(game.GiveMap()[40] == 1);
    EXPECT_TRUE(game.LiveOfCell(40));

    game.TakeBorn(3);
    game.TakeSurval(2);
    game.TakeSurval(3);

    game.TakeCell(39);
    game.TakeCell(80);

    game.RecountMap();

    EXPECT_TRUE(game.LiveOfCell(79));
    EXPECT_TRUE(game.LiveOfCell(40));
    EXPECT_FALSE(game.LiveOfCell(80));
    EXPECT_FALSE(game.LiveOfCell(39));
    
}
