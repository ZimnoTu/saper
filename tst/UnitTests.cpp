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
    EXPECT_EQ(true, testMineField.isBombPossible());
}
TEST_F (MineTesting, tooManyBombs)
{
    testMineField.setNumberOfBombs(100);
    EXPECT_EQ(false, testMineField.isBombPossible());
}
TEST_F (MineTesting, dropDaBomb)
{

}

