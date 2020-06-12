#ifndef HANGMAN_INCLUDED
#define HANGMAN_INCLUDED

#include <string>

class Hangman 
{
public:
    Hangman(bool output = true);

    bool playGame(std::string const& word);
    bool manualGame(std::string const& word);
    bool makeGuess(char const c);
    void reset();

    size_t getErrors() const;
    std::string getGuess() const;

private:

    bool increament();
    void draw() const;
    void drawGallow() const;

    std::string body;
    std::string word;
    std::string guess;
    size_t errors;
    bool output;
};

#endif
