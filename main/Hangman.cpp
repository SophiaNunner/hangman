#include "Hangman.h"

#include <algorithm>
#include <iostream>

void Hangman::playGame(std::string const& word){
    this->word = word;
    this->guess = std::string(word.length(), '_');
    this->errors = 0;
    this->body = std::string(7, '\0');

    do{
        draw();
    } while(makeGuess(tolower(std::getchar())));
}

bool Hangman::makeGuess(char const letter) {
    if(letter == '\n'){
        return true;
    }
    bool letterRight = false;

    //check if the word contains the letter
	for (size_t i = 0; i < word.size(); ++i) {
		if (word[i] == letter) {
			guess[i] = letter;
			letterRight = true;
		}
	}

    if(!letterRight && !increament()){
        draw();
        std::puts("#### you lose! ####");
        return false;
    }
    else if(letterRight && word == guess){
        draw();
        std::puts("#### you win! ####");
        return false;
    }

    return true;
}

void Hangman::reset() {
    this->word = "";
    this->guess = "";
    this->errors = 0;
}

bool Hangman::increament() {
    switch (++errors) {
		case 6: body[6] = '\\'; break;
		case 5: body[5] = '/'; break;
		case 4: body[4] = '\\'; break;
		case 3: body[3] = '|'; break;
		case 2: body[2] = '/'; break;
		case 1: body[0] = '(', body[1] = ')'; break;
	}
	return errors < 6;
}

void Hangman::draw() const {
    //clear screen
    #ifdef _WIN32
		std::system("cls");
    #else
		std::system("clear");
    #endif

    drawGallow();
    std::for_each(guess.begin(), guess.end(), [](const char c) { std::printf("%c ", c); });
	std::putchar('\n');
}

void Hangman::drawGallow() const {
	std::printf(
        " ________\n"
		"|        |\n"
		"|       %c %c\n"
		"|       %c%c%c\n"
		"|       %c %c\n"
		"|\n"
		"|\n", body[0], body[1], body[2], body[3],
		    	body[4], body[5], body[6]);
}