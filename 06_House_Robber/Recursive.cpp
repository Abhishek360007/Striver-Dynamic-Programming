#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(int index, vector<int>& nums)
{
    // Base case
    if (index == 0)
        return nums[0];

    if (index < 0)
        return 0;

    // Rob current house
    int take = nums[index] + rob(index - 2, nums);

    // Skip current house
    int notTake = rob(index - 1, nums);

    return max(take, notTake);
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

    cout << "Maximum Money = "
         << rob(n - 1, nums);

    return 0;
}

/*
Time Complexity : O(2^N)

Space Complexity : O(N)
*/