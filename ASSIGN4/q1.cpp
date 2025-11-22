#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
    }
    void push(int val) // pushback of ll
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() // popfront of ll
    {
        if (head == NULL)
        {
            cout << "queue is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;

        // if list becomes empty after deletion
        if (head == NULL)
        {
            tail = NULL;
        }

        delete temp;
    }

    int front()
    {
        if (head == NULL)
        {
            cout << "queue is empty" << endl;
            return -1;
        }

        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    Queue a;
    a.push(1);
    a.push(2);
    a.push(3);

    while (!a.empty())
    {
        cout << a.front() << endl;
        a.pop();
    }
}