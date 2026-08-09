#include <iostream>
using namespace std;

int climbStairs(int n)
{
    // Base case
    if (n == 0 || n == 1)
        return 1;

    // Recursive relation
    return climbStairs(n - 1) + climbStairs(n - 2);
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
Time Complexity : O(2^N)
Space Complexity : O(N)

Reason:
Each function call creates two more recursive calls.
The recursion stack can go up to N levels.
*/