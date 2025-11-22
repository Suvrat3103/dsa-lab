// first non repeating letter in a string

#include <iostream>
#include <queue>
#include <string>
using namespace std;

void FirstNonRepeat(string str) // O(n)
{
    queue<char> Q;
    int freq[26] = {0}; // frequency array for lowercase letters

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        // Push current char into queue and update frequency
        Q.push(ch);
        freq[ch - 'a']++;

        // Remove all repeating characters from front
        while (!Q.empty() && freq[Q.front() - 'a'] > 1)
        {
            Q.pop();
        }

        // Print first non-repeating character till now
        if (Q.empty())
        {
            cout << "# "; // if none, print #
        }
        else
        {
            cout << Q.front() << " ";
        }
    }
    cout << endl;
}

int main()
{
    string str = "aabccxb";
    FirstNonRepeat(str);
    return 0;
}