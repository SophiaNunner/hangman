#include "HangmanTest.h"

void HangmanTest::SetUp()
{
    mpObj = new Hangman();
}

void HangmanTest::TearDown()
{
    delete mpObj; mpObj = 0;
}

TEST_F(HangmanTest, gtestBasic) {
    ASSERT_EQ(true, true);
}

TEST_F(HangmanTest, playWordEmpty){
    ASSERT_EQ(mpObj->playGame(""), false);
}

TEST_F(HangmanTest, manualWordEmpty){
    ASSERT_EQ(mpObj->manualGame(""), false);
}

TEST_F(HangmanTest, manualWordSpace){
    ASSERT_EQ(mpObj->manualGame(" "), true);
    ASSERT_EQ(mpObj->makeGuess(' '), false);
    ASSERT_EQ(mpObj->getErrors(), 0);
}

TEST_F(HangmanTest, manualWordLetter){
    ASSERT_EQ(mpObj->manualGame("t"), true);
    ASSERT_EQ(mpObj->makeGuess('t'), false);
    ASSERT_EQ(mpObj->getErrors(), 0);
}

TEST_F(HangmanTest, manualWordLetterWrong){
    ASSERT_EQ(mpObj->manualGame("t"), true);
    ASSERT_EQ(mpObj->makeGuess('x'), false);
    ASSERT_EQ(mpObj->getErrors(), 1);
}

TEST_F(HangmanTest, rightGuess){
    ASSERT_EQ(mpObj->manualGame("test"), true);
    ASSERT_EQ(mpObj->makeGuess('t'), true);
    ASSERT_EQ(mpObj->getErrors(), 0);
    ASSERT_EQ(mpObj->getGuess(), "t__t");
}

TEST_F(HangmanTest, wrongGuess){
    ASSERT_EQ(mpObj->manualGame("test"), true);
    ASSERT_EQ(mpObj->makeGuess('y'), true);
    ASSERT_EQ(mpObj->getErrors(), 1);
    ASSERT_EQ(mpObj->getGuess(), "____");
}

TEST_F(HangmanTest, win){
    ASSERT_EQ(mpObj->manualGame("test"), true);
    ASSERT_EQ(mpObj->makeGuess('t'), true);
    ASSERT_EQ(mpObj->makeGuess('e'), true);
    ASSERT_EQ(mpObj->makeGuess('s'), true);
    ASSERT_EQ(mpObj->getErrors(), 0);
    ASSERT_EQ(mpObj->getGuess(), "test");
}

TEST_F(HangmanTest, lose){
    ASSERT_EQ(mpObj->getErrors(), 0);
    ASSERT_EQ(mpObj->manualGame("asdf"), true);
    ASSERT_EQ(mpObj->getErrors(), 0);
    ASSERT_EQ(mpObj->makeGuess('t'), true);
    ASSERT_EQ(mpObj->getErrors(), 1);
    ASSERT_EQ(mpObj->makeGuess('e'), true);
    ASSERT_EQ(mpObj->getErrors(), 2);
    ASSERT_EQ(mpObj->makeGuess('n'), true);
    ASSERT_EQ(mpObj->getErrors(), 3);
    ASSERT_EQ(mpObj->makeGuess('r'), true);
    ASSERT_EQ(mpObj->getErrors(), 4);
    ASSERT_EQ(mpObj->makeGuess('z'), true);
    ASSERT_EQ(mpObj->getErrors(), 5);
    ASSERT_EQ(mpObj->makeGuess('u'), true);
    ASSERT_EQ(mpObj->getErrors(), 6);
    ASSERT_EQ(mpObj->getGuess(), "____");
}