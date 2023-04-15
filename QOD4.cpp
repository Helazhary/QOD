/*

 target word "TEST"(caps merely for emphasis, program is case sensitive)
 ex 1: "djTfnkEkndSknT" = true
 ex 2: "TksfEjfkdTjkS" = false

*/

/*
Approach: will use a string similar to a stack in which it will be filled if the correct letter is located while
the text is scanned once O(n) time complexity
Currently the space complexity is O(n) where n is the length of the target word to potentially be filled in a string
however, this can be reduced to O(1) by comparing the length of the target with the number of correct letters from the word
Please refer to the file named "QOD4.1.cpp" for the O(1) space complexity version. Both versions work, but this
approach can be modified to 
*/

#include <iostream>
using namespace std;

bool word_assemble(string target, string text)
{
    string word = "";
    int j = 0; // used to traverse target word
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == target[j])
        {
            word += text[i];
            j++;
        }
        if (word == target)
            return true;
    }

    return false;
}
int main()
{

    string target = "test";
    string text = "tgegsgt"; // common letter g just for ease of understanding, arbitrarily replacable
    string text2 = "tgsgegt";
    cout << word_assemble(target, text);
}
