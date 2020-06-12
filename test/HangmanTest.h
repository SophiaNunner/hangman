#pragma once

#include "Hangman.h"
#include "gtest/gtest.h"

class HangmanTest : public ::testing::Test {
public:
    HangmanTest() {}

    virtual ~HangmanTest() {}

    virtual void SetUp();
    virtual void TearDown();

protected:
    Hangman* mpObj;
};