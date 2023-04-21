/*
                                        QOD 7
We know that prime numbers are positive integers that have exactly two distinct positive divisors.
Similarly, we'll call a positive integer k, Т-prime, if k has exactly three distinct positive divisors.
You are given an array of n positive integers. For each of them, determine whether it is Т-prime or not.

*/
#include <iostream>

using namespace std;

int sqrt(int num)
{

    float temp = 0;
    int number = num;
    float sqrt = number / 2;
   
  

    while (sqrt != temp)
    {
        temp = sqrt;
        sqrt = (number / temp + temp) / 2;
    }


    return (sqrt);
}

bool is_prime(long long n)
{
    if (n < 2)
        return false;
    for (long long i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool is_tprime(long long n)
{
    if (n < 4)
        return false;
    long long root = sqrt(n);
    return is_prime(root) && root * root == n;
}

void printarr(bool arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    bool tprime_arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        tprime_arr[i] = is_tprime(arr[i]);
    }

    printarr(tprime_arr, n);
}

/*
    Time Complexity:

n = number of integers to be checked for tprime attribute
T(n) = comparison operators
funciton complexity breakdown:
sqrt(): O(log(num))
is_prime(): O(sqrt(n)) loops from 2 to the square root of n
is_tprime(): O(sqrt(n)), since it calls sqrt() and is_prime()
Loop in main() that calls is_tprime() for each element in the array: O(n * (max(arr[i]))^0.5), where max(arr[i]) is the maximum value in the array

T(n) = O(n * (max(arr[i]))^0.5)

    Space Complexity:

The main function creates two arrays of size n, namely arr and tprime_arr, thus, the overall space complexity is O(n) as other functions don't use n dependant extra space.
*/
