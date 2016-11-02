#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

int appendToAll (string a[], int n, string value);
int lookup (const string a[], int n, string target);
int positionOfMax (const string a[], int n);
int rotateLeft (string a[], int n, int pos);
int countRuns (const string a[], int n);
int flip (string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence (const string a1[], int n1, const string a2[], int n2);
int lookupAny (const string a1[], int n1, const string a2[], int n2);
int split(string a[], int n, string splitter);

int main()
{
    string h[7] = { "bernie", "hillary", "donald", "jeb", "", "carly", "ben" };
    assert(lookup(h, 7, "carly") == 5);
    assert(lookup(h, 7, "donald") == 2);
    assert(lookup(h, 2, "donald") == -1);
    assert(positionOfMax(h, 7) == 3);
    
    string g[4] = { "bernie", "hillary", "jeb", "carly" };
    assert(differ(h, 4, g, 4) == 2);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "bernie?" && g[3] == "carly?");
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "jeb?" && g[3] == "hillary?");
    
    string e[4] = { "donald", "jeb", "", "carly" };
    assert(subsequence(h, 7, e, 4) == 2);
    
    string d[5] = { "hillary", "hillary", "hillary", "ben", "ben" };
    assert(countRuns(d, 5) == 2);
    
    string f[3] = { "jeb", "donald", "marco" };
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(flip(f, 3) == 3 && f[0] == "marco" && f[2] == "jeb");
    
    assert(split(h, 7, "carly") == 3);
    
    cout << "All tests succeeded" << endl;
}

int appendToAll (string a[], int n, string value)
{
    string s;
    if (n < 0)
        return -1;
    for (int k = 0; k < n; k++)
    {
        s = a[k];
        s += value; //Appends on the value to each element of the array
        a[k] = s;
    }
    return n;
}

int lookup (const string a[], int n, string target)
{
    if (n < 1)
        return -1;
    for (int k = 0; k < n; k++)
    {
        if (a[k] == target) //If the element of the array is equal to the target, return the position
            return k;
    }
    return -1;
}

int positionOfMax (const string a[], int n)
{
    if (n <= 0)
        return -1;
    int maxPosition = 0; //Starts off at 0 to begin with max in the first position
    for (int k = 0; k < n; k++)
    {
        if (a[k] > a[maxPosition]) //If subsequent elements are greater than before, they become the max
            maxPosition = k;
    }
    return maxPosition;
}

int rotateLeft (string a[], int n, int pos)
{
    if (n <= 0 || pos < 0 || pos >= n)
        return -1;
    string positionMove = a[pos]; //Sets the position of the element to be rotated to a string
    for (int k = pos; k < n - 1; k++)
    {
        a[k] = a[k + 1]; //Shifts over all elements to the left one
    }
    a[n - 1] = positionMove; //Moves the position of the element to be rotated to the last element of array
    return pos;
}

int countRuns (const string a[], int n)
{
    if (n < 1)
        return -1;
    int consecutiveRuns = 1;
    for (int k = 0; k < n - 1; k++)
    {
        if (a[k] != a[k + 1]) //If two elements are different, then a new sequence occurs
            consecutiveRuns++;
    }
    return consecutiveRuns;
}

int flip (string a[], int n)
{
    if (n < 0)
        return -1;
    string temp;
    for (int k = 0; k < (n/2); k++) //Needs to be n / 2, so we don't swap the values twice
    {
        temp = a[k]; //Use of a temporary variable to swap the values of elements of the array
        a[k] = a[n - 1 - k];
        a[n - 1 - k] = temp;
        
    }
    return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0)
        return -1;
    int i = 0;
    while (i < n1 && i < n2 && a1[i] == a2[i]) //if position of i ever differ, then i will be returned
        i++;
    return i;
}

int subsequence (const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0)
        return -1;
    if (n2 > n1)
        return -1;
    if (n2 == 0 && n1 >= n2)
        return 0;
    
    int i;
    int j;
    for (i = 0; i < n1; i++)
    {
        if (a1[i] == a2[0]) //If any element of a1 contains the beginning of a2, then there is a match
        {
            for (j = 0; j < n2; j++)
            {
                if (a2[j] != a1[i + j]) //If the elements stop matching, the subsequence ends
                    break;
            }
            if (j == n2)
                return i;
        }
    }
    return -1;
}

int lookupAny (const string a1[], int n1, const string a2[], int n2)
{
    if (n1 <= 0 || n2 <= 0)
        return -1;
    int i;
    int j;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            if (a1[i] == a2[j])
                return i;
        }
    }
    return -1;
}

int split(string a[], int n, string splitter)
{
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;
    
    int positionStart = 0; //Created two markers to work through the array elements in both directions
    int positionEnd = n - 1;
    string temp; //Initialiaze a temporary variable to swap values
    
    while (positionStart < positionEnd) //When positionStart and positionEnd are equal, leave the loop
    {
        if (a[positionStart] < splitter)
        {
            positionStart++;
            continue;
        }
        if (a[positionStart] >= splitter) //Swap the values of the positions at the given markers
        {
            temp = a[positionStart];
            a[positionStart] = a[positionEnd];
            a[positionEnd] = temp;
        }
        if (a[positionEnd] > splitter)
            positionEnd--;
        
    }
    if (a[positionEnd] >= splitter)
        return positionEnd;
    else
        return positionStart + 1;
}
