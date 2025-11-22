#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string str) //0(n)
{
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        // opening brackets
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        {
            // closing bracket but stack is empty → invalid
            if (s.empty())
            {
                return false;
            }

            char top = s.top();

            // check matching pair
            if ((top == '(' && ch == ')') ||
                (top == '[' && ch == ']') ||
                (top == '{' && ch == '}'))
            {
                s.pop();
            }
            else
            {
                return false; // mismatch
            }
        }
    }

    return s.empty(); // valid if stack is empty at the end
}

int main()
{
    string str1 = "([}])";
    string str2 = "([{}])";

    cout<<isValid(str1)<<endl;
    cout<<isValid(str2)<<endl;

    return 0;
}