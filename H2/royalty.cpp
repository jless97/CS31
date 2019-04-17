#include <iostream>
#include <string>
using namespace std;

int main()
{
    // collect the variables
    
    int unitsSent;
    string titleOfMovie;
    double basePrice;
    string moviePremium;
    double royalty = 0.0;
    
    cout << "Units sent: ";
    cin >> unitsSent;
    cin.ignore(10000, '\n'); // ignore the rest of the line with the number
    
    cout << "Title: ";
    getline(cin, titleOfMovie);
    
    cout.setf(ios::fixed);
    cout.precision(2);
    
    cout << "Base price: ";
    cin >> basePrice;
    cin.ignore(10000, '\n');
    
    cout << "Premium item? (y/n): ";
    getline(cin, moviePremium);
    
    if (unitsSent >= 0 && unitsSent <= 400) // calculate the royalty if there are only 400 units or less
    {
        royalty = (0.09 * basePrice) * unitsSent;
    }
    else if (unitsSent > 400 && unitsSent <= 1200) /* calculate the royalty if there are more than 400 units, but
                                                      less than or equal to 1200 */
    {
        royalty = (0.09 * basePrice) * 400;
        if (moviePremium == "y")
        {
            royalty += (0.16 * basePrice) * (unitsSent - 400);
        }
        if (moviePremium == "n")
        {
            royalty += (0.13 * basePrice) * (unitsSent - 400);
        }
    }
    else if (unitsSent > 1200) // calculate the royalty if there are more than 1200 units
    {
        royalty = (0.09 * basePrice) * 400;
        if (moviePremium == "y")
        {
            royalty += (0.16 * basePrice) * 800;
        }
        if (moviePremium == "n")
        {
            royalty += (0.13 * basePrice) * 800;
        }
        royalty += (0.14 * basePrice) * (unitsSent - 1200);
    }
    
    
    cout << "---" << endl;
    
    // write out the conditions to correct
    
    if (unitsSent < 0)
    {
        cout << "The number of units sent must be nonnegative." << endl;
    }
    else if (titleOfMovie == "" )
    {
        cout << "You must enter a title." << endl;
    }
    else if (basePrice < 0)
    {
        cout << "The base price must be nonnegative." << endl;
    }
    else if (moviePremium != "y" && moviePremium != "n")
    {
        cout << "You must enter y or n." << endl;
    }
    else
    {
        cout << titleOfMovie << " earned $" << royalty << " in royalties." << endl;
    }
    return 0;
}