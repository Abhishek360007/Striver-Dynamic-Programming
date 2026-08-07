#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << "Fibonacci Number = " << fibonacci(n, dp);

    return 0;
}

/*
Time Complexity : O(N)

Space Complexity : O(N)

DP Array : O(N)
Recursion Stack : O(N)
*/