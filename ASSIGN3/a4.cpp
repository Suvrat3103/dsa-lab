#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    vector<int> ans(n, 0);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temp[i] > temp[st.top()]) {
            int idx = st.top();
            st.pop();
            ans[idx] = i - idx; // days waited
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(temp);

    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}