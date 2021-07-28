#include <bits/stdc++.h>
using namespace std;
 
// Returns minimum time required
// to place mice in holes.
int assignHole(int mices[], int holes[],
               int n, int m)
{
     
    // Base Condition
    // No. of mouse and holes should be same
    if (n != m)
        return -1;
     
    // Sort the arrays
    sort(mices, mices + n);
    sort(holes, holes + m);
     
    // Finding max difference between
    // ith mice and hole
    int max = 0;
    for(int i = 0; i < n; ++i)
    {
        if (max < abs(mices[i] - holes[i]))
            max = abs(mices[i] - holes[i]);
    }
    return max;
}
 
// Driver Code
int main()
{
     
    // Position of mouses 
    int mices[] = { -10,-79,-79,67,93,-85,-28,-94};
   
    // Position of holes
    int holes[] = {-2, 9, 69, 25, -31, 23, 50, 78 };
   
    // Number of mouses
    int n = sizeof(mices) / sizeof(mices[0]);
   
    // Number of holes
    int m = sizeof(holes) / sizeof(holes[0]);
   
    // The required answer is returned
    // from the function
    int minTime = assignHole(mices, holes, n, m);
   
    cout << "The last mouse gets into the hole in time:"
         << minTime << endl;
   
    return 0;
}