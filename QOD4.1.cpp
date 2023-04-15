#include <iostream>
using namespace std;

bool word_assemble(string target, string text)
{
    int j = 0; // used to traverse target word
    for (int i = 0; i < text.size(); i++)
    {
        if (toupper(text[i]) == toupper(target[j]))
        {
            j++;
            if (j == target.size())
                return true;
        }
    }
    return false;
}

int main()
{
    string target = "test";
    string text = "tgegsgt"; // common letter g just for ease of understanding, arbitrarily replacable
    string text2 = "tgsgegt";
    cout << word_assemble(target, text2);
}
