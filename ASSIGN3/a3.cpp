#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextGreater(vector<int> &arr, vector<int> &ans) //O(n)
{
    stack<int> s;
    int idx = arr.size() - 1; // start from last index

    ans[idx] = -1;    // last element → no next greater
    s.push(arr[idx]); // push last element

    for (idx = idx - 1; idx >= 0; idx--)
    {
        int curr = arr[idx];

        // pop smaller or equal elements
        while (!s.empty() && curr >= s.top())
        {
            s.pop();
        }

        // if stack empty → no greater
        if (s.empty())
        {
            ans[idx] = -1;
        }
        else
        {
            ans[idx] = s.top();
        }

        // push current element for next comparisons
        s.push(curr);
    }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    
}

int main()
{
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans(arr.size());

    nextGreater(arr, ans);

    return 0;
}