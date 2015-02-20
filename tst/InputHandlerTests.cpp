#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <inputhandler.h>


using namespace testing;

struct TestSuite : public Test
{
};

class InputHandlerTest : public ::testing :: Test
{
protected:
    InputHandler testIH;
};

TEST_F(InputHandlerTest, checkMove_recievesGoodInput_A1)
{
   std::string testString = "A1";
   EXPECT_TRUE(testIH.checkMove(testString));
}

TEST_F (InputHandlerTest, checkMove_recievesBadInput_AA1)
{
    std::string testString = "AA1";
    EXPECT_FALSE(testIH.checkMove(testString));
}

TEST_F (InputHandlerTest, checkMove_recievesGoodInput_A10)
{
    std::string testString = "A10";
    EXPECT_TRUE(testIH.checkMove(testString));
}
TEST_F(InputHandlerTest, checkMove_recievesGoodInputLowercase_a1)
{
   std::string testString = "a1";
   EXPECT_TRUE(testIH.checkMove(testString));
}
TEST_F (InputHandlerTest, checkMove_recievesBadInput_A1B)
{
    std::string testString = "A1B";
    EXPECT_FALSE(testIH.checkMove(testString));
}
TEST_F (InputHandlerTest, checkMove_recievesBadInput_A1B1)
{
    std::string testString = "A1B1";
    EXPECT_FALSE(testIH.checkMove(testString));
}
TEST_F (InputHandlerTest, checkMove_recievesGoodInput_A1Brackets)
{
    std::string testString = "A1[]";
    EXPECT_TRUE(testIH.checkMove(testString));
}
TEST_F (InputHandlerTest, checkMove_recievesGoodInput_A_Slash_1)
{
    std::string testString = "A/1";
    EXPECT_TRUE(testIH.checkMove(testString));
}

TEST_F(InputHandlerTest, checkMove_recievesGoodInput_A1_Space)
{
   std::string testString = "A1 ";
   EXPECT_TRUE(testIH.checkMove(testString));
}

TEST_F(InputHandlerTest, checkMove_recievesGoodInput_A_Space_1)
{
   std::string testString = "A 1";
   EXPECT_TRUE(testIH.checkMove(testString));
}

TEST_F(InputHandlerTest, checkMove_recievesGoodInput_Space_A1)
{
   std::string testString = " A1";
   EXPECT_TRUE(testIH.checkMove(testString));
}
TEST_F(InputHandlerTest, checkMove_recievesGoodInput_1A)
{
   std::string testString = "1A";
   EXPECT_TRUE(testIH.checkMove(testString));
}
TEST_F (InputHandlerTest, checkMove_recievesBadInput_1A0)
{
    std::string testString = "1A0";
    EXPECT_FALSE(testIH.checkMove(testString));
}
TEST_F(InputHandlerTest, checkMove_recievesGoodInput_10a)
{
    std::string testString = "10a";
    EXPECT_TRUE(testIH.checkMove(testString));
}
TEST_F(InputHandlerTest, changingToUppercase_11cl)
{
    std::string testString = "11c";
    testIH.checkMove(testString);
    EXPECT_EQ("C11", testIH.changeToUppercase(testString));
}
TEST_F(InputHandlerTest, interpretInputHorizontal_A1)
{
    std::string testString = "A1";
    testIH.setParameters(testString);
    EXPECT_EQ(0, testIH.getHorizontalParameter());
}
TEST_F(InputHandlerTest, interpretInputVertical_A1)
{
    std::string testString = "A1";
    testIH.setParameters(testString);
    EXPECT_EQ(0, testIH.getVerticalParameter());
}
TEST_F(InputHandlerTest, interpretInputVertical_A11)
{
    std::string testString = "A11";
    testIH.setParameters(testString);
    EXPECT_EQ(10, testIH.getVerticalParameter());
}
