#include <gtest/gtest.h>
#include "../Controller/controller.hpp"


const std::string EXAMPLE = "#Life 1.06\n#N second\n#B3/S23\n0 0\n2 0\n1 1\n2 1\n1 2";

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TestGame, test_1){
    Game game(30);
    
    EXPECT_TRUE(game.GiveSizeX() == 30);
    EXPECT_TRUE(game.GiveSizeY() == 30);

    game.RecountSize(40, 40);

    EXPECT_TRUE(game.GiveSizeX() == 40);
    EXPECT_TRUE(game.GiveSizeY() == 40);

    game.TakeCell(40, State::Alive);

    EXPECT_TRUE(game.LiveOfCell(0, 39));

    game.TakeBorn(3);
    game.TakeSurval(2);
    game.TakeSurval(3);

    game.TakeCell(39, State::Alive);
    game.TakeCell(80, State::Alive);

    game.RecountMap();

    EXPECT_TRUE(game.LiveOfCell(1, 38));
    EXPECT_TRUE(game.LiveOfCell(0, 39));
    EXPECT_FALSE(game.LiveOfCell(1, 39));
    EXPECT_FALSE(game.LiveOfCell(0, 38));
}
