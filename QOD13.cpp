#include <iostream>
using namespace std;

int uniquePaths(int m, int n) {
    // Compute the binomial coefficient (m+n-2) choose (n-1) or (m+n-2) choose (m-1).
    long long paths = 1;
    for (int i = 1; i <= n-1; i++) {
        paths *= m-1+i;
        paths /= i;
    }
    return (int)paths;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
    return 0;
}
