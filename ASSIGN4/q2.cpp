// queue using array

#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int capacity;
    int f, r;     // front and rear
    int currSize; // current number of elements

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f = r = -1;
    }

    void push(int data)
    {
        if (currSize == capacity)
        {
            cout << "Queue is full!" << endl;
            return;
        }
        if (f == -1)
        {
            f = 0;
        }
        r = (r + 1) % capacity; // circular increment
        arr[r] = data;
        currSize++;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        f = (f + 1) % capacity;
        currSize--;
        if (currSize == 0)
        { // reset when queue becomes empty
            f = r = -1;
        }
    }

    int front()
    {
        if (empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[f];
    }

    int rear()
    {
        if (empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[r];
    }

    bool empty()
    {
        return currSize == 0;
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl; // 10
    q.pop();
    cout << q.rear() << endl;
    cout << "Front: " << q.front() << endl; // 20
    q.pop();

    q.push(40);
    cout << q.rear() << endl;

    cout << "Front: " << q.front() << endl; // 30
    q.pop();
    cout << q.rear() << endl;

    q.pop(); // trying to pop from empty queue

    return 0;
}