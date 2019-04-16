#include <iostream>
using namespace std;

//This function takes as input a pointer to the first element
//of a c-string and a pointer to the last element of a c-string 
//(including 0 byte) and outputs a new c-string that reverses 
//the order of characters in the original string

char* reverseString(char* first, char* last)
{
    char* newString = new char[last - first];
    int i = 0;
    last = last -1;
    
    while (last != first)
    {
        newString[i] = *last;
        i++;
        last--;
    }
    newString[i] = *last;
    newString[i + 1] = '\0';
}

//This function takes as input a c-string containing a number and 
//the number of characters in the array (not including 0 byte)
//It outputs an integer representation of that number.
int convertStringToInt(char number[], int len)
{
    int place = 0;
    int tens=1;
    for (int i = 0; i < len; i++)
    {
        place+=(number[i]-'0')*tens;
        tens*=10;
    }
    return place;
}
















}