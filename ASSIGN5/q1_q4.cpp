#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Linked List class
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    // Insert at end
    void push_back(int val)
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

    // Insert at front
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert at a given position (0-based index)
    void insertAt(int pos, int val)
    {
        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Position out of range!" << endl;
                return;
            }
            temp = temp->next;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL)
        {
            tail = newNode; // update tail if inserted at last
        }
    }

    // delete first element
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to delete!" << endl;
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

    // delete last element
    void pop_back()
    {
        Node *temp = head;
        while (temp->next->next != NULL) // or (temp->next!=tail) if tail is given
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // search idx
    int searchItr(int key) // time comp = 0(n)
    {
        Node *temp = head;
        int idx = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx; // found
            }
            temp = temp->next;
            idx++;
        }

        return -1; // not found
    }

    // reccursive search
    int helper(Node *temp, int key)
    {
        if (temp == NULL)
            return -1;
        if (temp->data == key)
        {
            return 0;
        }
        int idx = helper(temp->next, key);
        if (idx == -1)
        {
            return -1;
        }
        return idx + 1;
    }

    int rec_search(int key)
    {
        return helper(head, key);
    }

    // reverse // q4
    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // size(no. of elements)
    int getsize()
    {
        Node *temp = head;
        int size = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }

    // remove nth term from last
    void remove_nth(int n) // time comp = O(n) and space comp = 0(1)
    {
        int size = getsize();
        Node *prev = head;

        for (int i = 1; i < (size - n); i++)
        {
            prev = prev->next;
        }
        Node *todel = prev->next;
        cout << "going to delete " << todel->data << endl;

        prev->next = prev->next->next;
    }

    // Print list
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    List l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(40);

    l.push_front(5);

    l.insertAt(2, 15); 
    l.insertAt(4, 30); 

    cout << "Before pop_front: ";
    l.print();

    l.pop_front(); // remove first element

    cout << "After pop_front: ";
    l.print();

    l.pop_back();

    cout << "After pop_back: ";
    l.print();

    cout << l.searchItr(20) << endl;
    cout << l.rec_search(15) << endl;

    l.reverse();
    cout << "After reverse: ";
    l.print();

    cout << "no. of elements in l is: " << l.getsize() << endl;

    l.remove_nth(3);
    cout << "after remove:";
    l.print();

    return 0;
}