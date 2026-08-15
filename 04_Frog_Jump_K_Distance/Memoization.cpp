#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int frogJump(int index, int k, vector<int>& heights, vector<int>& dp)
{
    // Base case
    if (index == 0)
        return 0;

    // Return already calculated result
    if (dp[index] != -1)
        return dp[index];

    int minimumEnergy = 1e9;

    // Try all possible jumps from 1 to k
    for (int jump = 1; jump <= k; jump++)
    {
        if (index - jump >= 0)
        {
            int energy = frogJump(index - jump, k, heights, dp)
                       + abs(heights[index] - heights[index - jump]);

            minimumEnergy = min(minimumEnergy, energy);
        }
    }

    return dp[index] = minimumEnergy;
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

    vector<int> dp(n, -1);

    cout << "Minimum Energy = "
         << frogJump(n - 1, k, heights, dp);

    return 0;
}

/*
Time Complexity : O(N * K)

Space Complexity : O(N)

DP Array        : O(N)
Recursion Stack : O(N)
*/