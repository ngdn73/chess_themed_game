#ifndef utils_h
#define utils_h

#include<iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include<conio.h>
#include<time.h>
using namespace std;

string chooseWord(string path);
char getInput(char guess);
void gameOver(string secretWord);
void printTheLabel(string message, bool printTop, bool printBottom);
void DrawHangman(int badGuesses = 0);
void printLetters(string input, char from, char to);
void printAvailables( string taken );
void printWord(string word);
bool printWordAndCheckWin(string secretWord, string guessedWord);
int guessesLeft( string secretWord, string guessedWord);

/*
+---------------------------------+
|             HANGMAN             |
+---------------------------------+
|         _______                 |
|        |/      |                |
|        |      (_)/              |
|        |      /|                |
|        |       |                |
|        |      / \               |
|        |                        |
|       _|___                     |
+---------------------------------+
|    A B C D E F G H I J K L M    |
|    N O P Q R S T U V W X Y Z    |
+---------------------------------+
|            YOUR TURN            |
+---------------------------------+
|             _ _ _ _             |
+---------------------------------+
*/
#endif
