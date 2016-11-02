#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstring>
#include <cassert>
#include "utilities.h"
using namespace std;

const int MAXWORDS = 9000;

int manageOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum);
bool isAllLower(const char word[]);
bool isKnown (const char words[][MAXWORDLEN + 1], int nWords, const char probe[]);
int countRocks(const char probe[], const char secret[]);
int countPebbles(const char probe[], const char secret[]);

int main()
{
    char wordList[MAXWORDS][MAXWORDLEN + 1];
    int nWords = loadWords(wordList, MAXWORDS);
    int min = 0, max = 0, total = 0;
    double average = 0.0;
    
    if (nWords < 1 || nWords > MAXWORDS)
    {
        cout << "No words were loaded, so I can't play the game." << endl;
        return -1;
    }
    
    cout << "How many rounds do you want to play? ";
    int nRounds;
    cin >> nRounds;
    cin.ignore(10000, '\n');
    
    if (nRounds < 1)
    {
        cout << "The number of rounds must be positive." << endl;
        return -1;
    }
    
    //Each loop is for a single round of the game
    for (int i = 1; i <= nRounds; i++)
    {
        cout << "Round " << i << endl;
        int wordNum = randInt(0, nWords - 1);
        cout << "The secret word is " << strlen(wordList[wordNum]) << " letters long." << endl;
        int score = manageOneRound(wordList, nWords, wordNum);
        if (score == -1)
        {
            cout << "Error in manageOneRound" << endl;
            return -1;
        }
        
        //If the secret word is guessed on the first try
        if (score == 1)
            cout << "You got it in 1 try." << endl;
        else
            cout << "You got it in " << score << " tries." << endl;
        
        //Sets min tries and max tries to the number of tries taken in the first round
        if (i == 1)
        {
            min = score;
            max = score;
            total = 0;
        }
        
        //If in a later round, the number of tries is greater than previous max, this is new max
        if (score > max)
            max = score;
        
        //If in a later round, the number of tries is less than the previous min, this is new min
        if (score < min)
            min = score;
        total += score; //Total is equal to the number of tries in all rounds
        average = static_cast<double>(total)/i; //Type cast to double, so no integer division
        
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Average: " << average << ", minimum: " << min << ", maximum: " << max << endl;
    }
    return 0;
}

int manageOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum)
{
    if (nWords < 1 || wordnum < 0 || wordnum >= nWords)
        return -1;
    
    char secret[MAXWORDLEN + 1];
    strcpy (secret, words[wordnum]);
    
    char probe[100];
    int nTries = 0;
    
    while (true) //Loop through until the secret word is guessed
    {
        cout << "Probe word: ";
        cin.getline (probe, 99);
        
        //If word is not 4 to 6 letters, or if the word has uppercase letter
        if (strlen(probe) < 4 || strlen(probe) > 6 || isAllLower(probe) == false)
        {
            cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
            continue;
        }
        //If probe word is not known in the word list
        if (!isKnown(words, nWords, probe))
        {
            cout << "I don't know that word." << endl;
            continue;
        }
        
        nTries++;
        
        //Check if the probe word matches the secret word
        if (strcmp(probe, secret) == 0)
            break;
        //Check the rocks and the pebbles
        int nRocks = countRocks(probe, secret);
        int nPebbles = countPebbles(probe, secret);
        cout << "Rocks: " << nRocks << ", Pebbles: " << nPebbles << endl;
        
    }
    return nTries;
}

//To check if the word has any uppercase letters
bool isAllLower(const char word[])
{
    for (int i = 0; i < strlen(word); i++)
    {
        //if lowercase, return false
        if (islower(word[i]) == false)
            return false;
    }
    return true; //There was no error
}

//To check if the probe word is in the word list
bool isKnown (const char words[][MAXWORDLEN + 1], int nWords, const char probe[])
{
    for (int i = 0; i < nWords; i++)
    {
        if (strcmp(probe, words[i]) == 0)
            return true; //Found word
    }
    return false;
}

int countRocks(const char probe[], const char secret[])
{
    //Rocks are letters that are in the same position
    int count = 0;
    for (int i = 0; i < strlen(probe) && i < strlen(secret); i++)
    {
        //If characters at the position are equal, then it is a rock
        if (probe[i] == secret[i])
            count++;
    }
    return count;
}

int countPebbles(const char probe[], const char secret[])
{
    //Pebbles are letters that appear in both, but are not used as rocks or other pebbles
    int count = 0;
    
    //Create two cstrings to record the used rocks and pebbles to prevent reuse of pebbles
    char usedInProbe[MAXWORDLEN + 1] = "      ";
    char usedInSecret[MAXWORDLEN + 1] = "      ";
    
    //Find the rocks and mark them as used
    for (int i = 0; i < strlen(probe) && i < strlen(secret); i++)
    {
        if (probe[i] == secret[i])
        {
            //If rock, mark the position as a rock
            usedInProbe[i] = 'r';
            usedInSecret[i] = 'r';
        }
    }
    
    //Find the pebbles and marke them as used
    for (int i = 0; i < strlen(probe); i++)
    {
        for (int j = 0; j < strlen(secret); j++)
        {
            if(probe[i] == secret[j] && usedInProbe[i] == ' ' && usedInSecret[j] == ' ')
            {
                count++;
                //If a pebble, mark the position as a pebble
                usedInProbe[i] = 'p';
                usedInSecret[j] = 'p';
            }
        }
    }
    return count;
}


