#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include "grid.h"
using namespace std;

bool isRouteWellFormed (string route);
int navigateSegment(int r, int c, char dir, int maxSteps);
int routeDigits (string a);
int navigateRoute(int sr, int sc, int er, int ec, string route, int& nsteps);

int main()
{
    setSize(3,4);      // make a 3 by 4 grid
    setWall(1,4);      // put a wall at (1,4)
    setWall(2,2);      // put a wall at (2,2)
    if (!isWall(3,2))  // if there's no wall at (3,2)  [there isn't]
        setWall(3,2);  //    put a wall at (3,2)
    draw(3,1, 3,4);  // draw the grid, showing an S at (3,1)
                       //    start position, and an E at (3,4)
    assert(isRouteWellFormed(""));
    assert(isRouteWellFormed("n"));
    assert(!isRouteWellFormed("2"));
    assert(isRouteWellFormed("n0"));
    assert(isRouteWellFormed("n22"));
    assert(!isRouteWellFormed("n222"));
    assert(!isRouteWellFormed("e1x"));
    
    cout << endl;
    
    assert(navigateSegment(3, 1, 'n', 3) == 2);
        cout << navigateSegment(3, 1, 'n', 3) << endl;
    assert(navigateSegment(0, 1, 'n', 3));
        cout << navigateSegment(0, 1, 'n', 3) << endl;
    assert(navigateSegment(0, 1, 'x', 3));
        cout << navigateSegment(0, 1, 'x', 3) << endl;
    assert(navigateSegment(0, 1, 'n', -1));
        cout << navigateSegment(0, 1, 'n', -1) << endl;
    assert(navigateSegment(1, 5, 'n', 3));
        cout << navigateSegment(1, 5, 'n', 3) << endl;
    assert(navigateSegment(1, 1, 'N', 3) == 0);
        cout << navigateSegment(1, 1, 'N', 3) << endl;
    assert(navigateSegment(1, 1, 'S', 3) == 2);
        cout << navigateSegment(1, 1, 'S', 3) << endl;
    assert(navigateSegment(1, 1, 'E', 3) == 2);
        cout << navigateSegment(1, 1, 'E', 3) << endl;
    assert(navigateSegment(1, 1, 'W', 3) == 0);
        cout << navigateSegment(1, 1, 'W', 3) << endl;
    
    cout << endl;
    
    int len;
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(3,1, 3,4, "N2eE01n0s2e1", len) == 0  &&  len == 7);
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(3,1, 3,4, "e1x", len) == 2  &&  len == -999);
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(2,4, 1,1, "w3n1", len) == 3  &&  len == 1);
    len = -999;  // so we can detect whether navigateRoute sets len
    assert(navigateRoute(1,3, 3,4, "sse", len) == 0  &&  len == 3);
    
    cout << "All tests succeeded" << endl;
    
}

bool isRouteWellFormed (string route) //to check if the route is a syntactically valid route
{
    for (int i = 0; i != route.size(); i++)
    {
        route[i] = tolower(route[i]);
    }
    if (route == "") //To allow for a valid route consisting of no segments
        return true;
    else if (route.size() == 1) //To allow for a route consisting of one segment with no digits
    {
        if (route[0] == 'n' || route[0] == 's' || route[0] == 'e' || route[0] == 'w')
            return true;
    }
    int k = 0;
    while (k != route.size()) //To allow for all other valid route possibilites
    {
        if (route[k] == 'n' || route[k] == 's' || route[k] == 'e' || route[k] == 'w') //Check if first char is a valid dir
        {
            if (k + 1 == route.size())
                break;
            if (route[k + 1] == 'n' || route[k + 1] == 's' || route[k + 1] == 'e' || route[k + 1] == 'w'); //Check if second char is valid char
            else if (isdigit(route[k + 1])) //Check if second char is a digit
            {
                int digitCount = 1;
                int j;
                for (j = k + 2; j != route.size(); j++) //if it is a digit counts subsequent digits
                {
                    if (isdigit(route[j]))
                        digitCount++;
                    else
                        break;
                }
                k = j - 1;
                if (digitCount > 2) //If more than 2 digits in a row, then invalid route
                    return false;
            }
            else
                return false;
        }
        else
            return false;
        k++;
    }
    return true;
}

int navigateSegment(int r, int c, char dir, int maxSteps) //to check the max steps robot can take in a given direction
{
    dir = tolower(dir);
    if (r <= 0 || r > getRows()) //setting conditions to allow for only valid r or c and valid steps
        return (-1);
    if (c <= 0 || c > getCols())
        return (-1);
    if (isWall(r,c))
        return (-1);
    if (dir != 'n' && dir != 's' && dir != 'e' && dir != 'w')
        return (-1);
    if (maxSteps < 0)
        return (-1);
    int count = 0;
    if (dir == 'n') //If dir is north, will count the number of steps in that given direction
    {
        for (int i = r; i - 1 != 0; i--)
        {
            if (isWall (i-1, c))
                break;
            else
                count++;
        }
    }
    if (dir == 's') //If dir is south, will count the number of steps in that given direction
    {
        for (int i = r; i != getRows(); i++)
        {
            if (isWall (i + 1, c))
                break;
            else
                count++;
        }
    }
    if (dir == 'e') //If dir is east, will count the number of steps in that given direction
    {
        for (int j = c; j != getCols(); j++)
        {
            if (isWall (r, j + 1))
                break;
            else
                count++;
        }
    }
    if (dir == 'w') //If dir is west, will count the number of steps in that given direction
    {
        for (int j = c; j - 1 != 0; j--)
        {
            if (isWall (r, j - 1))
                break;
            else
                count++;
        }
    }
    if (count < maxSteps) //if the count is less than the maxSteps, return count
        return count;
    else
        return maxSteps; //if maxSteps is greater than count, return count
    }

int routeDigits (string a) // a function for navigateRoute to process string of digits and convert to int
{
    int count = 0;
    for (int i = 0; i != a.size(); i++)
    {
        int number = (int) (a[i] - '0'); //puts the digits following the dir into one number
        count = (count * 10) + number;
    }
    return count;
}

int navigateRoute(int sr, int sc, int er, int ec, string route, int& nsteps) //to check if robot makes it from start to end position
{
    //Sets the conditions to allow for a valid start and end position
    if (sr <= 0 || sr > getRows() || er <= 0 || er > getRows() || sc <= 0 || sc > getCols() || ec <= 0 ||
        ec > getCols() || (! isRouteWellFormed(route)) ||  isWall (sr, sc) || isWall (er, ec))
        return 2;
    
    nsteps = 0;
    for (int i = 0; i != route.size(); i++) // Loop to process each position of the string and separate the char dir and the char digits
    {
        if(isalpha(route[i])) //if the string position is a valid dir, then create a new variable of type char to hold the value
        {
            char s = route[i];
            
            string b; //create a new string that will hold the digit values for the steps in the given direction
            int d = 1;
            if (isdigit(route[i + 1]))
            {
                int j = i + 1;
                while (j != route.size() && isdigit(route[j]))
                {
                    b += route[j];
                    j++;
                }
                d = routeDigits(b); //calls the function that will process the string of digits and convert to int
            }
            int steps;
            steps = navigateSegment(sr, sc, s, d); // call the navigateSegment function to get the number of steps in one direction
            if (steps < d)
            {
                nsteps += steps;
                return 3;
            }
            if (s == 'N' || s == 'n') //processes the steps to see if the sr is equal to the er
            {
                sr = sr - steps;
            }
            if (s == 'S' || s == 's') //processes the steps to see if the sr is equal to the er
            {
                sr = sr + steps;
            }
            if (s == 'W' || s == 'w') //processes the steps to see if the sc is equal to the ec
            {
                sc = sc - steps;
            }
            if (s == 'E' || s == 'e') //processes the steps to see if the sc is equal to the ec
            {
                sc = sc + steps;
            }
            nsteps+=steps;
        }
    }
    if (sr == er && sc == ec) //if robot navigates from start to finish
    {
        return 0;
    }
    return 1; 
}
