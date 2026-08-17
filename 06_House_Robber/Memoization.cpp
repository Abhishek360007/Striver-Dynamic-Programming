#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(int index, vector<int>& nums, vector<int>& dp)
{
    // Base case
    if (index == 0)
        return nums[0];

    if (index < 0)
        return 0;

    // Return already calculated result
    if (dp[index] != -1)
        return dp[index];

    // Rob current house
    int take = nums[index] + rob(index - 2, nums, dp);

    // Skip current house
    int notTake = rob(index - 1, nums, dp);

    return dp[index] = max(take, notTake);
}

int main()
{
    int n;

    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter money in each house: ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> dp(n, -1);

    cout << "Maximum Money = "
         << rob(n - 1, nums, dp);

    return 0;
}

/*
Time Complexity : O(N)

Space Complexity : O(N)

DP Array        : O(N)
Recursion Stack : O(N)
*/