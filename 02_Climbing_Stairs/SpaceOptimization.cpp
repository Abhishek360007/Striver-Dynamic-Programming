#include <iostream>
using namespace std;

int climbStairs(int n)
{
    // Base cases
    if (n == 0 || n == 1)
        return 1;

    // Only previous two values are required
    int prev2 = 1;
    int prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int current = prev1 + prev2;

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
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
Space Complexity : O(1)
*/