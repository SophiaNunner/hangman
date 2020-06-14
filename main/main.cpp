#include "Hangman.h"

using namespace std;

int main(int argc, char *argv[]){
    string word = "Hangman";
    if(argc > 1){
        word = argv[1];
    }

    Hangman hm;
    hm.playGame(word);

    return EXIT_SUCCESS;
}