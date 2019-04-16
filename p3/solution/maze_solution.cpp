#include "grid.h"
#include <string>
#include <cctype>
using namespace std;

bool getDeltas(char dir, int& dr, int& dc);

//*************************************
//  isRouteWellFormed
//*************************************

bool isRouteWellFormed(string route)
{
    // Each iteration of the loop will check one route segment
    
    size_t k = 0;
    while (k != route.size())
    {
        // Route segment must start with a valid direction
        
        char dir = tolower(route[k]);
        if (dir != 'n'  &&  dir != 'e'  &&  dir != 'w'  &&  dir != 's')
            return false;
        
        // Optionally, there may be a digit
        
        k++;
        if (k != route.size()  &&  isdigit(route[k]))
        {
            // If so, there may be another digit
            
            k++;
            if (k != route.size()  &&  isdigit(route[k]))
                k++;
        }
    }
    
    // We get here if we got through the route without a problem
    
    return true;
}

//*************************************
//  navigateSegment
//*************************************

int navigateSegment(int r, int c, char dir, int maxSteps)
{
    // Make sure (r,c) is a valid empty grid cell
    
    int nr = getRows();
    int nc = getCols();
    if (r < 1  ||  r > nr  ||  c < 1  ||  c > nc  ||  isWall(r,c))
        return -1;
    
    // Make sure maxSteps is nonnegative
    
    if (maxSteps < 0)
        return -1;
    
    // Make sure the direction is OK, and for a given direction
    // determine dr and dc such that moving from (r,c) to (r+dr,c+dc)
    // is a move in that direction.
    
    int dr;
    int dc;
    if (!getDeltas(dir, dr, dc))
        return -1;
    
    // Try to move maxSteps steps in the given direction
    
    int ns;
    for (ns = 0; ns < maxSteps; ns++)
    {
        // Take one step
        
        r += dr;
        c += dc;
        
        // If that results in running off the grid or hitting a wall
        // stop moving
        
        if (r < 1  ||  r > nr  ||  c < 1  ||  c > nc  ||  isWall(r,c))
            break;
    }
    
    return ns;
}

//*************************************
//  navigateRoute
//*************************************

int navigateRoute(int sr, int sc, int er, int ec, string route, int& nsteps)
{
    // Make sure (sr,sc) and (er,ec) are valid empty grid cells
    
    int nr = getRows();
    int nc = getCols();
    if (sr < 1 || sr > nr || sc < 1 || sc > nc || isWall(sr,sc))
        return 2;
    if (er < 1 || er > nr || ec < 1 || ec > nc || isWall(er,ec))
        return 2;
    
    // Make sure route is syntactically valid
    
    if (!isRouteWellFormed(route))
        return 2;
    
    // Each iteration of the loop will move along one route segment.
    // At the completion of each iteration, we adjust (sr,sc) to reflect
    // where we are along the route.
    
    nsteps = 0;
    size_t k = 0;
    while (k != route.size())
    {
        // Get the direction and proposed number of steps for this segment.
        // Since know the route is syntactically valid at this point, we
        // don't have to worry about any tricky situation other than the
        // last segment in the route having zero or one digit.
        
        char dir = route[k];      // direction
        k++;
        
        int proposedSteps = 1;  // assume number of steps is 1
        
        if (k != route.size()  &&  isdigit(route[k])) // is there a first digit?
        {
            proposedSteps = route[k] - '0';  // first digit value
            k++;
            if (k != route.size()  &&  isdigit(route[k])) // a second digit?
            {
                // accumulate second digit value
                proposedSteps = 10 * proposedSteps + route[k] - '0';
                k++;
            }
        }
        
        // Try to move proposedSteps steps in the given direction.  Update
        // the total number of steps actually taken.  Return if blocked.
        
        int actualSteps = navigateSegment(sr, sc, dir, proposedSteps);
        if (actualSteps == -1)  // This should never be true,
            return 2;           // so it doesn't matter what we do.
        nsteps += actualSteps;
        if (actualSteps < proposedSteps)  // We were blocked.
            return 3;
        
        // Since we could navigate this segment, adjust where we are.
        
        int dr;
        int dc;
        getDeltas(dir, dr, dc);  // We know the direction must be valid.
        sr += actualSteps * dr;
        sc += actualSteps * dc;
    }
    
    // All segments have been navigated.  Are we at (er,ec)?
    
    if (sr == er  &&  sc == ec)
        return 0;
    else
        return 1;
}

//*************************************
//  getDeltas
//      If a given direction is not valid, return false;
//      otherwise, set dr and dc such that moving from (r,c) to (r+dr,c+dc)
//      is a one-step move in that direction and return true.  (For example,
//      moving north decreases the row by one and leaves the column unchanged.)
//*************************************

bool getDeltas(char dir, int& dr, int& dc)
{
    switch (tolower(dir))
    {
        case 'n':  dr = -1; dc =  0; break;
        case 'e':  dr =  0; dc =  1; break;
        case 's':  dr =  1; dc =  0; break;
        case 'w':  dr =  0; dc = -1; break;
        default:   return false;
    }
    return true;
}

int main()
{
    setSize(3,4);      // make a 3 by 4 grid
    setWall(1,4);      // put a wall at (1,4)
    setWall(2,2);      // put a wall at (2,2)
    if (!isWall(3,2))  // if there's no wall at (3,2)  [there isn't]
        setWall(3,2);  //    put a wall at (3,2)
    draw(3,1, 3,4);    // draw the grid, showing an S at (3,1)
    //    start position, and an E at (3,4)
}