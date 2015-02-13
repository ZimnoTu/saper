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

TEST_F(InputHandlerTest, checkMove_recievesGoodInputUppercase_A1)
{
   std::string testString = "A1";
   EXPECT_TRUE(testIH.checkMove(testString));
}

TEST_F (InputHandlerTest, checkMove_recievesBadInputUppercase_AA1)
{
    std::string testString = "AA1";
    EXPECT_FALSE(testIH.checkMove(testString));
}

TEST_F (InputHandlerTest, checkMove_recievesGoodInputUppercase_A10)
{
    std::string testString = "A10";
    EXPECT_TRUE(testIH.checkMove(testString));
}

TEST_F (InputHandlerTest, checkMove_recievesBadInputUppercase_1A0)
{
    std::string testString = "1A0";
    EXPECT_FALSE(testIH.checkMove(testString));
}
TEST_F(InputHandlerTest, checkMove_recievesGoodInputUppercase_a1)
{
   std::string testString = "a1";
   EXPECT_TRUE(testIH.checkMove(testString));
}
TEST_F (InputHandlerTest, checkMove_recievesBadInputUppercase_A1B)
{
    std::string testString = "A1B";
    EXPECT_FALSE(testIH.checkMove(testString));
}
TEST_F (InputHandlerTest, checkMove_recievesBadInputUppercase_A1B1)
{
    std::string testString = "A1B1";
    EXPECT_FALSE(testIH.checkMove(testString));
}
TEST_F (InputHandlerTest, checkMove_recievesBadInputUppercase_A1Brackets)
{
    std::string testString = "A1[]";
    EXPECT_FALSE(testIH.checkMove(testString));
}
TEST_F (InputHandlerTest, checkMove_recievesBadInputUppercase_ASlash1)
{
    std::string testString = "A/1";
    EXPECT_FALSE(testIH.checkMove(testString));
}
TEST_F(InputHandlerTest, checkMove_recievesGoodInputUppercase_A1_Space)
{
   std::string testString = "A1 ";
   EXPECT_TRUE(testIH.checkMove(testString));
}

