// one loop iterates through the vector of size n and the components are constant therefore O(n) time complexity
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool increasingTriplet(vector<int> &nums)
{
    int n = nums.size();
    int first = INT_MAX, second = INT_MAX, third = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= first)
        {
            first = nums[i];
        }
        else if (nums[i] <= second)
        {
            second = nums[i];
        }
        else
        {
            third = nums[i];
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> num = {4, 1, 2, 3};
    vector<int> num2 = {4, 1, 2, 1, 0, 3};
    cout << increasingTriplet(num2);
}