#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int frogJump(int index, vector<int>& heights)
{
    // Base case
    if (index == 0)
        return 0;

    // Jump from previous stair
    int oneStep = frogJump(index - 1, heights)
                + abs(heights[index] - heights[index - 1]);

    // Jump from two stairs before
    int twoStep = 1e9;

    if (index > 1)
    {
        twoStep = frogJump(index - 2, heights)
                + abs(heights[index] - heights[index - 2]);
    }

    return min(oneStep, twoStep);
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

    cout << "Minimum Energy = "
         << frogJump(n - 1, heights);

    return 0;
}

/*
Time Complexity : O(2^N)

Space Complexity : O(N)

Reason:
There are overlapping recursive calls and
the recursion depth can go up to N.
*/