#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> pieces(m);
    for (int i = 0; i < m; i++)
    {
        cin >> pieces[i];
    }
    sort(pieces.begin(), pieces.end());       // sort the pieces in non-decreasing order
    int min_diff = pieces[n - 1] - pieces[0]; // initialize the minimum difference to the largest possible value
    for (int i = n; i <= m; i++)
    {
        min_diff = min(min_diff, pieces[i - 1] - pieces[i - n]); // update the minimum difference
    }
    cout << min_diff << endl;
}

/*
The time complexity of this approach is O(m log m), where m is the number of puzzles.
This is becase the sort() function  has a time complexity of O(m log m).
The loop from n to m has a time complexity of O(m-n) but it is redundant in big O notation with n beiing a constant.
*/