#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumSum(int index, vector<int>& nums)
{
    // Base case
    if (index == 0)
        return nums[0];

    if (index < 0)
        return 0;

    // Take the current element
    int take = nums[index] + maximumSum(index - 2, nums);

    // Do not take the current element
    int notTake = maximumSum(index - 1, nums);

    return max(take, notTake);
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
         << maximumSum(n - 1, nums);

    return 0;
}

/*
Time Complexity : O(2^N)

Space Complexity : O(N)

Reason:
Each index creates two recursive choices:
take or not take.
*/