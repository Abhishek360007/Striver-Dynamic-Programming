#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int frogJump(int n, vector<int>& heights)
{
    int prev2 = 0;
    int prev1 = 0;

    for (int i = 1; i < n; i++)
    {
        int oneStep = prev1
                    + abs(heights[i] - heights[i - 1]);

        int twoStep = 1e9;

        if (i > 1)
        {
            twoStep = prev2
                    + abs(heights[i] - heights[i - 2]);
        }

        int current = min(oneStep, twoStep);

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

    vector<int> heights(n);

    cout << "Enter heights: ";

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    cout << "Minimum Energy = "
         << frogJump(n, heights);

    return 0;
}

/*
Time Complexity : O(N)

Space Complexity : O(1)
*/