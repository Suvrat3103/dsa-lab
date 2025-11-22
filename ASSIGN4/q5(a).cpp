#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    // Push element onto stack
    void push(int data) // O(n)
    {
        // Move all elements from q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Push new element into q1
        q1.push(data);

        // Move everything back from q2 to q1
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Pop element from stack
    void pop() // O(1)
    {
        if (q1.empty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        q1.pop();
    }

    // Get top element of stack
    int top() // O(1)
    {
        if (q1.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front(); // top of stack is always at front of q1
    }

    // Check if stack is empty
    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl; // 30
    st.pop();

    cout << "Top: " << st.top() << endl; // 20
    st.pop();

    cout << "Top: " << st.top() << endl; // 10
    st.pop();

    st.pop(); // extra pop → empty

    return 0;
}