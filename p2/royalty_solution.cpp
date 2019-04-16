// Royalty computation

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Get and validate units sent
    
    cout << "Units sent: ";
    int unitsSent;
    cin >> unitsSent;
    cin.ignore(10000, '\n');
    if (unitsSent < 0)
    {
        cout << "---\nThe number of units sent must be nonnegative." << endl;
        return 1;
    }
    
    // Get and validate title
    
    cout << "Title: ";
    string title;
    getline(cin, title);
    if (title == "")
    {
        cout << "---\nYou must enter a title." << endl;
        return 1;
    }
    
    // Get and validate base price
    
    cout << "Base price: ";
    double basePrice;
    cin >> basePrice;
    cin.ignore(10000, '\n');
    if (basePrice < 0)
    {
        cout << "---\nThe base price must be nonnegative." << endl;
        return 1;
    }
    
    // Get and validate premium status
    
    cout << "Premium item? (y/n): ";
    string premium;
    getline(cin, premium);
    if (premium != "y"  &&  premium != "n")
    {
        cout << "---\nYou must enter y or n." << endl;
        return 1;
    }
    
    // Units sent cutoff points and credit rates
    
    const double TIER_1_CUTOFF  = 400;
    const double TIER_2_CUTOFF  = TIER_1_CUTOFF + 800;
    const double RATE_1         = 0.09;
    const double RATE_2_REGULAR = 0.13;
    const double RATE_2_PREMIUM = 0.16;
    const double RATE_3         = 0.14;
    
    // Compute weighted royalty factor
    //   The royalty amount is the base price times what we'll call the
    //   weighted royalty factor.  For example, if 600 non-premium units
    //   were sent, the weighted royalty factor is  400 * 9% + 200 * 13%.
    
    double weightedRoyaltyFactor;
    
    if (unitsSent <= TIER_1_CUTOFF)
        weightedRoyaltyFactor = unitsSent * RATE_1;
    else
    {
        // Compute weightedRoyaltyFactor for the portion of units in tier 1
        
        weightedRoyaltyFactor = TIER_1_CUTOFF * RATE_1;
        
        // Determine rate for tier 2
        
        double rate_2 = RATE_2_REGULAR;
        if (premium == "y")
            rate_2 = RATE_2_PREMIUM;
        
        if (unitsSent <= TIER_2_CUTOFF)
        {
            // Add weighted royalty rate remainder of units (in 2nd tier)
            
            weightedRoyaltyFactor += (unitsSent - TIER_1_CUTOFF) * rate_2;
        }
        else
        {
            // Add weighted royalty rates for the portion of units in 2nd tier
            // and the remainder of units (in 3rd tier)
            
            weightedRoyaltyFactor += (TIER_2_CUTOFF - TIER_1_CUTOFF) * rate_2 +
            (unitsSent - TIER_2_CUTOFF) * RATE_3;
        }
    }
    
    // Compute and print royalty
    
    double royalty = weightedRoyaltyFactor * basePrice;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "---\n" << title << " earned $" << royalty << " in royalties." << endl;
}
