#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int frogJump(int index, int k, vector<int>& heights)
{
    // Base case
    if (index == 0)
        return 0;

    int minimumEnergy = 1e9;

    // Try all possible jumps from 1 to k
    for (int jump = 1; jump <= k; jump++)
    {
        if (index - jump >= 0)
        {
            int energy = frogJump(index - jump, k, heights)
                       + abs(heights[index] - heights[index - jump]);

            minimumEnergy = min(minimumEnergy, energy);
        }
    }

    return minimumEnergy;
}

int main()
{
    int n, k;

    cout << "Enter number of stairs: ";
    cin >> n;

    vector<int> heights(n);

    cout << "Enter heights: ";

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    cout << "Enter maximum jump distance: ";
    cin >> k;

    cout << "Minimum Energy = "
         << frogJump(n - 1, k, heights);

    return 0;
}

/*
Time Complexity : O(K^N)

Space Complexity : O(N)

Reason:
At each index, up to K recursive calls can be made.
*/