#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

int multiplication (int num1, int num2);
int division (int& num1, int& num2);
void addition (int num1, int num2);
string concatenate (string word1, string word2);
int subtraction (int num1, int num2);
double subtraction (double num1, double num2);
double subtraction (double num1, double num2, double num3);
int arrayFlip (int arrayParameter[], int n);

int main()
{
    double price = 0;
    double quantity = 0;
    
    //Using String Class
    //When reading in input for strings, use getline
     
    string word;
    cout << "Enter a word phrase: ";
    getline(cin, word);
    
    cout << "The word phrase you entered is " << word << endl;
    
    cout << "Enter a new word phrase: ";
    getline(cin, word);
    
    cout << "The new word phrase you entered is " << word << endl;
    
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    cout << "The number you entered is " << number << endl;
    
    cout << "Enter the price of a pancake: ";
    cin >> price;
    cout << "Enter the quantity of pancakes: ";
    cin >> quantity;
    
    double total = price * quantity;
    
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The total price of the pancakes is $" << price * quantity << endl;
    cout << "The total price of the pancakes is $" << total << endl;
    
    // Flow control statements
    //If Statements, if-else statements
    
    int x;
    cout << "Enter a number for x: ";
    cin >> x;
    
    if (x == 50)
    {
        cout << "x is equal to ";
        cout << x << endl;
    }
    else if (x > 0 && x < 50)
    {
        cout << "x is greater than 0, but ";
        cout << "x is less than 50." << endl;
        cout << "x is equal to " << x << endl;
    }
    else if (x > 50)
    {
        cout << "x is greater than 50." << endl;
        cout << "x is equal to " << x << endl;
    }
    else
    {
        cout << "x is less than 0." << endl;
        cout << "x is equal to " << x << endl;
    }
    
    //Switch Statements
    //Used for branching: could be equivalent to an if branching statement
     
    int z;
    cout << "Please enter a value for z: ";
    cin >> z;
    
    switch (z)
    {
        case 1:
            cout << "The value of z is " << z << endl;
            break;
        case 2:
            cout << "The value of z is " << z << endl;
            break;
        case 3:
        case 4:
        case 5:
            cout << "The value of z is either 3, 4 or 5" << endl;
            break;
        default:
            cout << "The value of z is neither 1, 2, 3, 4, nor 5" << endl;
    }
     
    //Iteration Statements
    //Loops: While, Do-While, and For
    
    //While Loop
    int y;
    cout << "Enter a value for the integer y: ";
    cin >> y;
    int count = 0;
    while (y > 0)
    {
        count++;
        cout << "The value of y is " << y << endl;
        y--;
    }
    cout << "We iterated through the loop " << count << " times." << endl;
    cout << "The value of y is no longer greater than 0" << endl;
    cout << "The value of y is now " << y << endl;
    
    //Do-While Loop
    
    cout << "Enter a new value for the integer y: ";
    cin >> y;
    int newCount = 0;
    do
    {
        cout << "The value of y is " << y << endl;
        newCount++;
        y--;
    }
    while (y > 0);
    cout << "We iterated through the loop " << newCount << " times." << endl;
    cout << "The value of y is no longer greater than 0" << endl;
    cout << "The value of y is now " << y << endl;
    
    //For Loop
    cout << "Finally, enter the last value for the integer y: ";
    cin >> y;
    int lastCount = 0;
    for (; y > 0; y--)
    {
        lastCount++;
        cout << "The value of y is " << y << endl;
    }
    cout << "We iterated through the loop " << lastCount << " times." << endl;
    cout << "The value of y is no longer greater than 0" << endl;
    cout << "The value of y is now " << y << endl;
    
    //Break in Flow Control Statements
    
    //Continue Statement: Used to skip through a loop iteration if a certain condition is met
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
        {
            cout << "Can't print out the value 9." << endl;
            continue;
        }
        cout << "The value of i is " << i << endl;
    }
    cout << endl;
    
    //Break Statement: Used to leave a loop if a certain condition is met
    for (int i = 0; i < 10; i++)
    {
        if (i == 8)
        {
            cout << "Can't print out values greater than 7." << endl;
            break;
        }
        cout << "The value of i is " << i << endl;
    }
    
    //Functions: Allow the program to structure the code to designate individual tasks
    
    //Types of Functons:
    //There are two types of functions:
    //Functions that return a value (int, bool, string)
    //Functions that do not return a value (void)
    
    //Functions consist of a prototype and the definition
    
    //Prototype: Appears above the main function and has a semi-colon
    
    //Definition: Appears below the main function, and consists of the executable body in curly braces
    
    //Function Header: Consists of the type, name of function, and necessary parameters that are in ( )
    
    //Parameters: The place holders for when the function is called by the main function
    
    //Call-By-Value: When the parameters are call-by-value, and when the function is called, the values of
    //arguments are passed to the function to execute the function body. However, the values of the argument
    //remain unchanged when the flow control returns back to the main function
    //Ex: int callByValue (int num1, int num2);
    
    //Call-By-Reference: when the parameters are call-by-reference, and when the function is called, the
    //arguments themselves are passed the function, rather than just the values. This way, when the flow
    //control returns back to the main function, the values of the arguments are changed
    //Also parameters that are call-by-reference have a & sign after the type of the parameter, but before
    //the name
    //Ex: int callByReference (int& num1, int& num2);
     
     //Default Parameters: You can set default parameters if the number of arguments passed is less than the
     //number of parameters of the function being called. This way if it occurs, the parameter will be set to
     //the default value
    
    int b, c;
    cout << "Please enter a value for the integer b: ";
    cin >> b;
    cout << "Please enter a value for the integer c: ";
    cin >> c;
    
    int a = multiplication (b, c);
    cout << "The value of a is " << a << endl;
    
    int d = division (b, c);
    cout << "The value of d is " <<  d << endl;
    cout << "The value of b was changed to " << b << endl;
    cout << "The value of c was changed to " << c << endl;
    
    addition(a, b);
    string s = "Hello ";
    string t = "World.";
    string u = concatenate (s, t);
    cout << "The string s has now been concatenated with string t to produce:\n " << u << endl;
    string v = concatenate(t, s);
    cout << "The string t has now been concatenated with the new string s to produce:\n " << v << endl;
    
    //Function Overloading
    //The ability to use the same function name for two completely different functions
    //As long as the functions have either:
        //Different parameter types
        //Different number of parameters
    
    //In the example below, there are three functions all with the same name that are used in the same
    //program. They are able to coexist due to the property of overloading. As long as the functions have
    //either different number of parameters or different types of parameters, then the compiler is able to
    //know which function to call in response to the arguments that are being passed to it

    int e, f;
    cout << "Please enter the value for the integer e: ";
    cin >> e;
    cout << "Please enter the value for the integer f: ";
    cin >> f;
    
    int g = subtraction(e, f);
    cout << "The value of g is the result from calling the function with paramters of type int: "
         << g << endl;
    
    double h, i;
    cout << "Please enter the value for the integer h: ";
    cin >> h;
    cout << "Please enter the value for the integer i: ";
    cin >> i;
    
    double j = subtraction(h, i);
    cout << "The value for j is the result from calling the function with parameters of type double: "
         << j << endl;
    
    double k, l, m;
    cout << "Please enter the value for the integer k: ";
    cin >> k;
    cout << "Please enter the value for the integer l: ";
    cin >> l;
    cout << "Please enter the value for the integer m: ";
    cin >> m;
    
    double n = subtraction(k, l, m);
    cout << "The value for n is the result from calling the function with 3 parameters: "
         << n << endl;
    
    //Name Visibility: Scope
    //Variables that exist within a block of code are known as local variables
    //Ex: for each of the function that I have created, they all have parameters num1, num2
    //However, these variable parameters are local to their functions, and don't overlap with other functions
    //However, there can be global variables that exist above all of the functions, and are global to all
    //functions that are being used
    
    //Arrays: Series of elements of the same type that are place in contiguous memory locations
    
    //Arrays consist of the type of the elements that will be stored in the array, the name of the array,
    //that comes right after the type, followed by a pair of square brackets [] to symbolize that it is an
    //array. When the array is initialized, it is usually initialized with no elements (like if it were used
    //in a function. However, it can be explicitly initialized with elements, and to do this, use the
    //assignment operator = and set the array equal to the elements that are in it
    
    //Ex: int exampleArray[] = {1, 2, 3, 4, 5};
    //In the example above this is an array of type int, whose name is exampleArray, that consists of 5
    //elements. The array could also be written with[5] to illustrate the size of the array
    //If there are less elements that are initialized than the size of the array, then they are
    //initialized to zero
    
    int arrayExample1[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        cout << arrayExample1[i] << " ";
    cout << endl;
    
    //Accessing the values of Arrays:
    //To access values of the elements (or indexes) in the arrays, it is necessary to use the square brackets
    //The square brackets have two different purposes in arrays:
        //Square brackets in a declaration of an array represent the size of the array
        //Square brackets everywhere else represents the index of the array
    //Ex: int foo[5] = {0, 1, 2, 3, 4};  //Here the square bracket refers to the size
    //foo[0], foo[1], foo[2], foo[3], foo[4] refer to the 5 element indexes of the array
    //Like with string indexes, array indexes begin with 0
    
    const int ARRAY_SIZE = 5;
    int arrayReturn = arrayFlip(arrayExample1, ARRAY_SIZE);
    cout << "The number of elements in the array is " << arrayReturn << endl;
    
    //Multidimensional Arrays
    //"Arrays of Arrays" or arrays that are have multiple dimensions
    //Ex: int jimmy[HEIGHT][WEIGHT];
    //Above is an array that is bidimensional (and results in rows and columns)
    
    const int ARRAY_ROW = 5, ARRAY_COLUMN = 4;
    int arrayMultiple[ARRAY_ROW][ARRAY_COLUMN] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}, {16, 17, 18, 19}};
    
    for (int i = 0; i < ARRAY_ROW; i++)
    {
        for (int j = 0; j < ARRAY_COLUMN; j++)
        {
            cout << arrayMultiple[i][j] << " ";
        }
        cout << endl;
    }
    
    //Arrays as parameters
    //Arrays can be passed as arguments and therefore in functions, can be used as parameters
    //In the example I showed above, when the function is called, the argument being passed is an array
    //For the function calll, the array argument name stands alone while being passed
    //Array parameters are similar to call-by-reference parameters in that they pass the whole variable, and
    //the values of the arguments can be changed
    //However, array parameters only pass the memory location of the first element in the array, as well as
    //the type of the elements in the array
    //In doing this, the array size gets lost, and it is necessary to include the size of the array as
    //another parameter when calling a function for an array
    
    //C-Strings
    
    //Strings are simply a sequence of characters
    //Therefore, we can represent strings as arrays with elements that are single characters
    //However, at the end of a c-string, we have to make room for the null character '\0'
    //Ex: int foo[20];
    //The above example is a cstring (string array) that is of the type int and whose name is foo, and who
    //can store 19 elements or characters with the last element being the null character '\0'
    
    //Initialization of C-strings:
    //C-Strings are just like arrays, and therefore, initialization is the same thing
    //Except they can be initialized in two ways:
        //Similar to arrays: Ex: char foo[] = {'a', 'b', 'c', 'd', '\0'};
        //Can be initialized to string literals: Ex: char foo[] = "abcd";
    //The two examples above are equivalent ==> All string literals have the null character at the end
    
    char myWord[100] = "hello";

    //How to iterate through a C-string loop ==> Go until the '\0' is hit
    for (int i = 0; myWord[i] != '\0'; i++)
        cout << myWord[i] << endl;

    
    //Because C-strings are just arrays of type char, they cannot be assigned values
    //Therefore, saying that myWord = "hello"; is invalid because we cannot assign values
    //However, the elements of the C-string array can be assigned values like shown above

    //C-strings, unlike strings (C++ strings) can't concatenate strings, check the length of a string, or
    //compare strings
    //Instead we have to use new functions that are associated with C-strings to achieve this
    //The following include: strlen(), strcpy(), strcmp(), strcat()

    //strlen(ARRAY_NAME) is used to get the length of the C-string ==> length doesn't include the '\0'
    
    int len = strlen(myWord);
    for (int i = 0; i < len; i++)
        cout << myWord[i] << " ";
    cout << endl;
    
    //strcpy() is used to copy a C-string to another empty perhaps string
    //strcpy(destination, source);
    //If the string that is the destination is shorter in length than the source ==> Undefined Behavior
    char newWord[] = "hello";
    char otherWord[] = "hell";
    strcpy(newWord, otherWord);
    cout << newWord << endl;
    
    //strcmp() is used to compare two strings to see if they are equal
    //If they are equal, it returns 0
    //If first string < second string ==> returns negative number
    //If first string > second string ==> returns positive number
    //Strings are compared by lexicographical order
    //By the ASCII code, the characters are compared by order of greatness
    //A < a, a < b, hello < heckle
    
    //Unlike comparison of C-strings, for strings, you don't need a function to compare them
    //Ex: string s = "hello"; string t = "help" ==> To compare, use t < s
    
    char string1[] = "hello";
    char string2[] = "hell";
    if (strcmp(string1, string2) == 0)
        cout << "The strings are equal" << endl;
    else if (strcmp(string1, string2) < 0)
        cout << "First string < Second string" << endl;
    else
        cout << "First string > Second string" << endl;
    
    //strcat(destination, source) is used to concatenate C-strings to one another
    
    char string3[] = "hi";
    char string4[] = " what's good";
    strcat(string3, string4);
    cout << string3 << endl;
    
    char str1[] = "hello";
    char str2[] = "Hello";
    if(strcmp(str1, str2) == 0)
        cout << "Equal" << endl;
    else if (strcmp(str1, str2) < 0)
        cout << "str 1 < str 2" << endl;
    else
        cout << "str 1 > str 2" << endl;
    return 0;
}

//Function that returns a value of type int
//It takes the arguments of b and c and passes them by value to the function
//The arguments b and c are not changed, but are used to compute the multiplication of b and c
int multiplication (int num1, int num2)
{
    int r;
    r = num1 * num2;
    return r;
}

//Function that returns a value of type int
//It takes the arguments of b and c and passes them by reference to the function
//The values of b and c are changed because the function changes the value of the parameters in the function
//Also main purpose is to due int division of b by c
int division (int& num1, int& num2)
{
    int r;
    r = num1 / num2;
    num1--;
    num2--;
    return r;
}

//Function that doesn't return a value
//However, it prints out the value of r when the function is called
void addition (int num1, int num2)
{
    int r;
    r = num1 + num2;
    cout << "The value of r is " << r << endl;
}

//Function that takes two strings and concatenates them into 1 string
//Strings can be concatenated simply by using an assignment operator
string concatenate (string word1, string word2)
{
    string r = word1 + word2;
    return r;
}

//Function that takes two numbers of type int and subtracts them
//This function has the same name as two other functions, but it has 2 parameters of type int
int subtraction (int num1, int num2)
{
    int r;
    r = num1 - num2;
    return r;
}

//Function that takes two numbers of type double and subtracts them
//This function has the same name as two other functions, but it has 2 parameters of type double
double subtraction (double num1, double num2)
{
    double r;
    r = num1 - num2;
    return r;
}

//Function that takes three numbers of type double and subtracts them
//This function has the same name as two other functions, but it has 3 parameters of type double
double subtraction (double num1, double num2, double num3)
{
    double r;
    r = num1 - num2 - num3;
    return r;
}

int arrayFlip (int arrayParameter[], int n)
{
    int count = 0;
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = arrayParameter[i];
        arrayParameter[i] = arrayParameter[n - 1 - i];
        arrayParameter[n - 1 - i] = temp;
        count++;
    }
    for (int j = 0; j < n; j++)
        cout << arrayParameter[j] << " ";
    cout << endl;
        
    return n;
}

