#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int frogJump(int n, int k, vector<int>& heights)
{
    vector<int> dp(n, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int minimumEnergy = 1e9;

        // Try all possible jumps from 1 to k
        for (int jump = 1; jump <= k; jump++)
        {
            if (i - jump >= 0)
            {
                int energy = dp[i - jump]
                           + abs(heights[i] - heights[i - jump]);

                minimumEnergy = min(minimumEnergy, energy);
            }
        }

        dp[i] = minimumEnergy;
    }

    return dp[n - 1];
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
         << frogJump(n, k, heights);

    return 0;
}

/*
Time Complexity : O(N * K)

Space Complexity : O(N)
*/