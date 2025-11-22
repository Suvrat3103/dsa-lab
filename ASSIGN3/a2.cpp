#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerToLeft(vector<int>& A) {
    int n = A.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        if (!st.empty()) ans[i] = st.top();
        st.push(A[i]);
    }
    return ans;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> res = nearestSmallerToLeft(A);

    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}