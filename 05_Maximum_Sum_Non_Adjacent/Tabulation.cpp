#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumSum(vector<int>& nums)
{
    int n = nums.size();

    if (n == 1)
        return nums[0];

    vector<int> dp(n);

    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int take = nums[i];

        if (i > 1)
            take += dp[i - 2];

        int notTake = dp[i - 1];

        dp[i] = max(take, notTake);
    }

    return dp[n - 1];
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

    cout << "Maximum Sum = "
         << maximumSum(nums);

    return 0;
}

/*
Time Complexity : O(N)
Space Complexity : O(N)
*/