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
    EXPECT_THROW(testMineField.isBombPossible(), std::string);
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
TEST_F (MineTesting, twoBombsInTheSamePlace)
{
    testMineField.putTheBomb(2,2);
    testMineField.putTheBomb(2,2);
    EXPECT_EQ(9, testMineField.getFieldValue(2,2));
}

TEST_F (MineTesting, countBombs)
{
    testMineField.putTheBomb(2,2);
    testMineField.putTheBomb(1,2);
    testMineField.putTheBomb(2,1);
    EXPECT_EQ(3, testMineField.countBombs());
}

TEST_F (MineTesting, numbersAround1Bomb)
{
    testMineField.putTheBomb(2,2);
    testMineField.checkIfbombIsAround();
    EXPECT_EQ(1, testMineField.getFieldValue(2,1));
}
TEST_F (MineTesting, numbersAround2Bombs)
{
    testMineField.putTheBomb(2,2);
    testMineField.putTheBomb(4,2);
    testMineField.checkIfbombIsAround();
    EXPECT_EQ(2, testMineField.getFieldValue(3,2));
}
TEST_F (MineTesting, bombDoesntChangeNextBomb)
{
    testMineField.putTheBomb(2,2);
    testMineField.putTheBomb(3,2);
    testMineField.checkIfbombIsAround();
    EXPECT_EQ(9,testMineField.getFieldValue(3,2));
}
TEST_F (MineTesting, bombInTheCorner)
{
    testMineField.putTheBomb(0,0);
    testMineField.checkIfbombIsAround();
    EXPECT_EQ(1, testMineField.getFieldValue(1,1));
}
