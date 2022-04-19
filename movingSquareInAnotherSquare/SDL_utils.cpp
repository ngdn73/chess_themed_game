#include"SDL_utils.h"

string chooseWord(string path)
{
    int lineCount = 0;
    string word;
    vector<string> v;
    ifstream reader(path);
    if( reader.is_open())
    {
        while (std::getline(reader, word))
            v.push_back(word);

        int randomLine = rand() % v.size();

        word = v.at(randomLine);
        reader.close();
    }
    return word;
}

void gameOver(string secretWord)
{
    printTheLabel(" GAME OVER !", true, false);
    string x = "THE SECRET WORD IS : ";
    x+=secretWord;
    printTheLabel(x, false, true);
}

void printTheLabel(string message, bool printTop = true, bool printBottom = true)
{
    if(printTop)
    {
        cout<< "+---------------------------------+"<<endl;
        cout<< "|";
    }
    else cout<<"|";

    bool front = true;
    for( int i= message.length(); i < 33; i++)
    {
         if(front) message = " " + message;
         else      message = message + " ";

         front = !front;
    }
    cout<<message.c_str();

    if(printBottom)
    {
        cout<<"|"<<endl;
        cout<<"+---------------------------------+"<<endl;
    }
    else cout<<"|"<<endl;

}

void DrawHangman(int badGuesses)
{
    if(badGuesses >= 1) printTheLabel("|", false, false);
    else printTheLabel("", false, false);

    if(badGuesses >= 2) printTheLabel("|",false, false);
    else printTheLabel("", false, false);

    if(badGuesses >= 3) printTheLabel("0",false, false);
    else printTheLabel("", false, false);

    if(badGuesses == 4) printTheLabel("/  ",false, false);

    if(badGuesses == 5) printTheLabel("/| ", false, false);

    if(badGuesses >= 6) printTheLabel("/|\\", false, false);
    else printTheLabel("", false, false);

    if(badGuesses >= 7) printTheLabel("|", false, false);
    else printTheLabel("", false, false);

    if(badGuesses == 8) printTheLabel("/  ", false, false);

    if(badGuesses >= 9) printTheLabel("/ \\ ", false, false);
    else printTheLabel("", false, false);
}

void printLetters(string input, char from, char to)
{
    string s;
    for(char i = from; i <= to; i++)
    {
        if(input.find(i) == string::npos)
        {
            s += i;
            s +=" ";
        }
        else s += "  ";
    }
    printTheLabel(s, false, false);
}

void printAvailables( string taken )
{
    printTheLabel("Available letters");
    printLetters(taken, 'A', 'M');
    printLetters(taken, 'N', 'Z');
}

bool printWordAndCheckWin(string secretWord, string guessedWord)
{
    bool won = true;
    string s;
    for(int i = 0; i < secretWord.length(); i++)
    {
        if(guessedWord.find(secretWord[i]) == string::npos)
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += secretWord[i];
            s += " ";
        }
    }
    printTheLabel(s, false, true);
    return won;
}

int guessesLeft( string secretWord, string guessedWord )
{
    int badGuesses = 0;
    for( int i = 0; i < guessedWord.length(); i++)
    {
        if(secretWord.find(guessedWord[i]) == string::npos)
            badGuesses++;
    }
    return badGuesses;
}

char getInput(char x)
{
    char out;
    cin>>x;
    if( x > 96 && x < 123 )
    {
        out=x-32;
        return out;
    }
    else return x;
}
