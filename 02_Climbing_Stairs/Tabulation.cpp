#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n)
{
    // Base cases
    if (n == 0 || n == 1)
        return 1;

    vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;

    // Build the solution from bottom to top
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Total Ways = " << climbStairs(n);

    return 0;
}

/*
Time Complexity : O(N)
Space Complexity : O(N)
*/