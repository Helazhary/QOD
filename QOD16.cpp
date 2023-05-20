#include <bits/stdc++.h>
using namespace std;

int MaxPoints(vector<int> a, int size)
{
    int dp[size]; //Maximum points that can be earned up to index i
    if (size == 0)
        return 0;
    if (size == 1)
        return a[0];
    dp[0] = a[0]; 
    dp[1] = max(a[0], a[1]); // Maximum points that can be earned up to index 1 is the maximum of a[0] and a[1]
    for (int i = 2; i < size; i++)
    {
        // The maximum points that can be earned up to index i is the maximum of the maximum points that can be earned up to index i-1
        // and the sum of the maximum points that can be earned up to index i-2 and a[i]
        dp[i] = max(dp[i-1], dp[i-2]+a[i]);
    }
    return dp[size-1]; 
}

int main()
{
    vector<int> a = {1, 2, 1, 3, 2, 2, 2, 2, 3}; 
    int maxPoints = MaxPoints(a, (int)a.size()); 
    cout << "Max points: " << maxPoints << endl; 
    return 0;
}