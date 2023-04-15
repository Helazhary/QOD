#include <iostream>
#include <string>
using namespace std;

int balanced_parentheses(string s)
{
    int longest = 0;
    int count = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
       if (s[i] == '(' && s[i+1] == ')')
        {
            count++;
            i++;
        }
        else
        {
            longest = max(longest, count);
            count = 0;
        }
        longest = max(longest, count);
    }
    return 2 * longest;
}

int main()
{
    string s = "()((()()())()()()())()(()))";
    cout << balanced_parentheses(s) << "\n";
}
