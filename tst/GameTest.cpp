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
    std::string str = "A1";
    testGame.parseInput(str);
    EXPECT_TRUE(testGame.isMoveValid());
}
TEST_F(GameTest, MoveMatchToField_10J)
{
    std::string str = "10J";
    testGame.parseInput(str);
    EXPECT_TRUE(testGame.isMoveValid());
}

TEST_F(GameTest, MoveMatchToField_A15)
{
    std::string str = "A15";
    testGame.parseInput(str);
    EXPECT_FALSE(testGame.isMoveValid());
}
TEST_F(GameTest, MoveMatchToField_L15)
{
    std::string str = "L15";
    testGame.parseInput(str);
    EXPECT_FALSE(testGame.isMoveValid());
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
TEST_F(GameTest, MoveChangedFieldTo_Uncoverd_Uppercase)
{
    std::string str("A1");
    testGame.makeMove(str);
    EXPECT_FALSE(testGame.isFieldCovered());
}
TEST_F(GameTest, MoveChangedFieldTo_Uncoverd_Lowercase_3c)
{
    std::string str("3C");
    testGame.makeMove(str);
    EXPECT_FALSE(testGame.isFieldCovered());
}
TEST_F(GameTest, MoveChangedFieldAroundTo_Uncovered)
{
    std::string str("A1");
    testGame.makeMove(str);
    EXPECT_FALSE(testGame.isFieldCovered(1,1));
}
TEST_F(GameTest, MoveChangedFieldAroundTo_Uncoveredd)
{
    testGame.placeBomb(1,1);
    testGame.placeBomb(2,2);
    std::string str("B2");
    testGame.makeMove(str);
    EXPECT_FALSE(testGame.isFieldCovered(2,2));
}

