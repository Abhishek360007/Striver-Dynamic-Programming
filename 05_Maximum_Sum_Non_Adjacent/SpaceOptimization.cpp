#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumSum(vector<int>& nums)
{
    int n = nums.size();

    if (n == 1)
        return nums[0];

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        int take = nums[i] + prev2;

        int notTake = prev1;

        int current = max(take, notTake);

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
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
Space Complexity : O(1)
*/