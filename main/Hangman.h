#ifndef HANGMAN_INCLUDED
#define HANGMAN_INCLUDED

#include <string>

class Hangman 
{
public:
    Hangman() = default;

    void playGame(std::string const& word);
    bool makeGuess(char const c);
    void reset();

private:

    bool increament();
    void draw() const;
    void drawGallow() const;

    std::string body;
    std::string word;
    std::string guess;
    size_t errors;
};

#endif