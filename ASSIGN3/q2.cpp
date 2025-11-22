// rverse a string using stack

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string stringReverse(string str)
{
    string ans;
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }

    while (!s.empty())
    {
        char top = s.top();
        ans += top;
        s.pop();
    }

    return ans;
}

int main()
{
    string s = "abcd";
    cout << "reverse of string is " << stringReverse(s);

    return 0;
}
