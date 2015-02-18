#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <game.h>


using namespace testing;

struct TestSuite : public Test
{
};

class GameTest : public ::testing :: Test
{
protected:
    Game testGame;
};
/*TEST_F(GameTest, SetFieldSizeByGameClass)
{
    Game testGame2(3,4);
    EXPECT_EQ(3,testGame2.mineField.getHorizontalLength());
    EXPECT_EQ(4, testGame2.mineField.getVerticalLength());
}*/

TEST_F(GameTest, MoveMatchToField_A1)
{
    EXPECT_TRUE(testGame.isMoveValid("A1"));
}
TEST_F(GameTest, MoveMatchToField_10J)
{
    EXPECT_TRUE(testGame.isMoveValid("10J"));
}
TEST_F(GameTest, MoveMatchToField_A15)
{
    EXPECT_FALSE(testGame.isMoveValid("A15"));
}
TEST_F(GameTest, MoveMatchToField_L15)
{
    EXPECT_FALSE(testGame.isMoveValid("L15"));
}

TEST_F(GameTest, GetValueOfFieldWithBomb)
{
    testGame.placeBomb(1,1);
    EXPECT_EQ(9, testGame.getFieldValue(1,1));
}
TEST_F(GameTest, GetValueOfFieldNearBomb)
{
    testGame.placeBomb(1,1);
    testGame.checkingField();
    EXPECT_EQ(1, testGame.getFieldValue(1,2));
}
TEST_F(GameTest, MoveChangedFieldTo_Uncoverd)
{
    std::string str("A1");
    testGame.makeMove(str);
    EXPECT_FALSE(testGame.isFieldCovered());
}
