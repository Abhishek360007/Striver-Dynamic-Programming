#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int frogJump(int index, vector<int>& heights, vector<int>& dp)
{
    // Base case
    if (index == 0)
        return 0;

    // Return already calculated result
    if (dp[index] != -1)
        return dp[index];

    // Jump from previous stair
    int oneStep = frogJump(index - 1, heights, dp)
                + abs(heights[index] - heights[index - 1]);

    // Jump from two stairs before
    int twoStep = 1e9;

    if (index > 1)
    {
        twoStep = frogJump(index - 2, heights, dp)
                + abs(heights[index] - heights[index - 2]);
    }

    return dp[index] = min(oneStep, twoStep);
}

int main()
{
    int n;

    cout << "Enter number of stairs: ";
    cin >> n;

    vector<int> heights(n);

    cout << "Enter heights: ";

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    vector<int> dp(n, -1);

    cout << "Minimum Energy = "
         << frogJump(n - 1, heights, dp);

    return 0;
}

/*
Time Complexity : O(N)

Space Complexity : O(N)

DP Array        : O(N)
Recursion Stack : O(N)
*/