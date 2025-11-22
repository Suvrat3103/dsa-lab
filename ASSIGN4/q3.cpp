// interleave 2 queues
// interleave 2 halves of a queue of even size

#include <iostream>
#include <queue>
using namespace std;

// Function to interleave queue
void interleave(queue<int> &q) // Time & Space both O(n) 
{
    if (q.empty())
        return;

    int n = q.size();
    int half = n / 2;

    queue<int> firstHalf;

    // Step 1: Push first half into another queue
    for (int i = 0; i < half; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Now interleave firstHalf and secondHalf (remaining q)
    while (!firstHalf.empty())
    {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> org;

    for (int i = 1; i <= 10; i++)
    {
        org.push(i);
    }

    interleave(org);

    // Print result
    while (!org.empty())
    {
        cout << org.front() << " ";
        org.pop();
    }
    cout << endl;

    return 0;
}
