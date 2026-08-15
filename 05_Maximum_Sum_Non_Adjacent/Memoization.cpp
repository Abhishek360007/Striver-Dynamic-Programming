#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumSum(int index, vector<int>& nums, vector<int>& dp)
{
    // Base case
    if (index == 0)
        return nums[0];

    if (index < 0)
        return 0;

    // Return already calculated result
    if (dp[index] != -1)
        return dp[index];

    // Take current element
    int take = nums[index] + maximumSum(index - 2, nums, dp);

    // Do not take current element
    int notTake = maximumSum(index - 1, nums, dp);

    return dp[index] = max(take, notTake);
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> dp(n, -1);

    cout << "Maximum Sum = "
         << maximumSum(n - 1, nums, dp);

    return 0;
}

/*
Time Complexity : O(N)

Space Complexity : O(N)

DP Array        : O(N)
Recursion Stack : O(N)
*/