#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <minefield.h>


using namespace testing;

struct TestSuite : public Test
{
};

class MineTesting : public ::testing :: Test
{
protected:
    MineField testMineField;
};

TEST_F (MineTesting, FildeSize_Horizon)
{
    EXPECT_EQ(5, testMineField.getHorizontalLength());
}
TEST_F (MineTesting, FildeSize_Vertical)
{
    EXPECT_EQ(5, testMineField.getVerticalLength());
}
TEST_F (MineTesting, otherField)
{
    MineField mineField2 (7,4);
    EXPECT_EQ(7, mineField2.getHorizontalLength() );
}
TEST_F (MineTesting, possibleBomb)
{
    EXPECT_TRUE(testMineField.isBombPossible());
}
TEST_F (MineTesting, tooManyBombs)
{
    testMineField.setNumberOfBombs(100);
    EXPECT_FALSE(testMineField.isBombPossible());//zrobic wyjatek
}
TEST_F (MineTesting, drop1Bomb)
{
    testMineField.putTheBomb(2,2);
    EXPECT_TRUE(testMineField.isBombPlaced(2,2));
}
TEST_F (MineTesting, drop1Bomb_missed)
{
    testMineField.putTheBomb(2,2);
    EXPECT_FALSE(testMineField.isBombPlaced(1,1));
}
TEST_F(MineTesting, bombOutOfSpace)
{
    EXPECT_THROW(testMineField.putTheBomb(10,10), std::string);
}

TEST_F (MineTesting, coutnBombs)
{
    testMineField.putTheBomb(2,2);
    testMineField.putTheBomb(1,2);
    testMineField.putTheBomb(2,1);
    EXPECT_EQ(3, testMineField.countBombs());
}

