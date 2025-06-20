#include <bits/stdc++.h>
using namespace std;

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string RESET = "\033[0m"; // resets color

void wordle(string guessedWord, string correctWord); //prints word with colored letters according to GAME INFO
bool checkIfLetterPresent(char c, string word); //check if a letter is present in the word

//words made up of UNIQUE 5 letters, UNIQUE for making the game easier to play (and code)
string fiveLetterWords[] = {
"blaze", "charm", "drain", "flock", "grape", "haste", "jumpy", "knack", "liver", "mirth",
"plume", "quilt", "stare", "badge", "brick", "claps", "dampy", "flaps", "glove", "haste", 
"impel", "jumpy", "knack", "latch", "melon", "nudge", "oiled", "palsy", "quake", "raven",
"tiger", "viper", "whale", "xenon", "yacht", "zesty", "bison", "dusty", "flick", "gavel",
"irate", "kited", "leapt", "mourn", "nifty", "scout", "alakh", "vowel", "wraps", "youth"};

int main() { 
    cout << "red letter = letter is part of the word but at wrong position" << endl    //GAME INFO
         << "green letter = letter is part of the word and at correct position" << endl//GAME INFO
         << "default(white) letter = letter is not part of the word" << endl           //GAME INFO
         << "The word is made up of 5 unique letters, you will have 5 turns to guess it correctly." << endl
         << "Dont be an asshole, type a single word in lower case and make sure its of 5 letters." << endl <<endl;

    srand(time(0));

    int elementsInArray = sizeof(fiveLetterWords) / sizeof(fiveLetterWords[0]); // find total elements in array
    int randomNum = rand() % (elementsInArray);   // if arraySize = x; randomNum would be from 0 to (x-1)
    string correctWord = fiveLetterWords[randomNum];  // choose a random word from array

    string guessedWord;
    for (int i = 0; i < 5; i++) {// repeat 5 times until won
        cout << "TURN " << i + 1 << ", guess the word\n";
        cin >> guessedWord;
        if (guessedWord == correctWord) {
            cout << GREEN << guessedWord << RESET << endl;
            cout << "thats the correct word, YOU WON!";
            return 0;
        }
        else {
            wordle(guessedWord, correctWord);
            cout << endl;
        }
    }
    cout << endl << "game over, the correct word was " << correctWord;
    return 0;
}

//prints word with colored letters according to GAME INFO
void wordle(string guessedWord, string correctWord)
{
    for (int i = 0; i < 5; i++)
    {
        if (guessedWord[i] == correctWord[i])
        {
            cout << GREEN << guessedWord[i] << RESET;
        }
        else if (checkIfLetterPresent(guessedWord[i], correctWord))
        {
            cout << RED << guessedWord[i] << RESET;
        }
        else
        {
            cout << guessedWord[i];
        }
    }
}

// check if a letter is present in the word
bool checkIfLetterPresent(char c, string word)
{
    int wordSize = sizeof(word) / sizeof(word[0]);
    for (int i = 0; i < wordSize; i++)
    {
        if (word[i] == c)
            return true;
    }
    return false;
}