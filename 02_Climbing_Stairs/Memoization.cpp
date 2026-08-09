#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n, vector<int>& dp)
{
    // Base case
    if (n == 0 || n == 1)
        return 1;

    // Return already calculated answer
    if (dp[n] != -1)
        return dp[n];

    // Store the result
    return dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp);
}

int main()
{
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << "Total Ways = " << climbStairs(n, dp);

    return 0;
}

/*
Time Complexity : O(N)

Space Complexity : O(N)

DP Array       : O(N)
Recursion Stack: O(N)
*/