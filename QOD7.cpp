/* 
                                        QOD 7
We know that prime numbers are positive integers that have exactly two distinct positive divisors. 
Similarly, we'll call a positive integer k, Т-prime, if k has exactly three distinct positive divisors.
You are given an array of n positive integers. For each of them, determine whether it is Т-prime or not.

*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

bool is_tprime(long long n) {
    if (n < 4) return false;
    long long root = sqrt(n);
    return is_prime(root) && root*root == n;
}

void printarr(bool arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\n";
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    bool tprime_arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        tprime_arr[i] = is_tprime(arr[i]);
    }

    printarr(tprime_arr, n);

}

/*
    Time Complexity:

n = number of integers to be checked for tprime attribute
t(n) = comparison operators
The is_prime function has a time complexity of O(sqrt(n)), as it checks if n is divisible by each number from 2 to sqrt(n).
The is_tprime function calls the is_prime function and performs a single square root operation, so its time complexity is O(sqrt(n)).
The for loop in the main function iterates n times, and for each iteration, it calls the is_tprime function.
Therefore, the overall time complexity of the main function is O(n*sqrt(n)).

    Space Complexity:

The main function creates two arrays of size n, namely arr and tprime_arr, thus, the overall space complexity is O(n).
*/