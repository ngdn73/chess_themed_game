#include"SDL_utils.h"

int main()
{
    srand(time(0));
    int badGuesses=0;
    string secretWord = chooseWord("words.txt");
    string guessedWord;
    bool win;

    while( badGuesses <= 9 and secretWord != guessedWord)
    {
        system("cls");
        printTheLabel("HANGMAN", true, true);
        DrawHangman(badGuesses);
        printAvailables(guessedWord);
        printTheLabel("Guess the word", true, false);
        win = printWordAndCheckWin(secretWord, guessedWord);
        if(win) break;
        char guess;
        cout<< ">"; cin>>guess;
        if( guess > 96 && guess < 123 )
        {
            guess-=32;
        }
        //guess=getInput(guess);
        if(guessedWord.find(guess) == string::npos)
            guessedWord += guess;
        badGuesses = guessesLeft(secretWord, guessedWord);
    }
    if(win) printTheLabel(" YOU WIN !", true, true);
    else gameOver(secretWord);
    system("pause");
    return main();
}
