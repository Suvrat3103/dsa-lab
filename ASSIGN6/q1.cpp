#include <iostream>
using namespace std;


class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
    DNode* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (head != NULL)
            head->prev = newNode;
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at beginning.\n";
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (head == NULL) {
            head = newNode;
        } else {
            DNode* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted " << val << " at end.\n";
    }

    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        DNode* temp = head;
        while (temp && temp->data != val)
            temp = temp->next;

        if (!temp) {
            cout << "Node not found!\n";
            return;
        }

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Deleted node " << val << endl;
    }

    void search(int val) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found!\n";
    }

    void display() {
        DNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

class CNode {
public:
    int data;
    CNode* next;

    CNode(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    CNode* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int val) {
        CNode* newNode = new CNode(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Inserted " << val << " at beginning.\n";
    }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted " << val << " at end.\n";
    }

    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        CNode* curr = head;
        CNode* prev = NULL;

        do {
            if (curr->data == val) {
                if (curr == head && curr->next == head) {
                    head = NULL;
                } else if (curr == head) {
                    CNode* last = head;
                    while (last->next != head)
                        last = last->next;
                    head = head->next;
                    last->next = head;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                cout << "Deleted node " << val << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Node not found!\n";
    }

    void search(int val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        CNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        CNode* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, type, val;

    while (true) {
        cout << "\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nEnter choice: ";
        cin >> type;
        if (type == 3) break;

        while (true) {
            cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Delete Node\n4. Search Node\n5. Display\n6. Back\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 6) break;

            if (choice != 5) {
                cout << "Enter value: ";
                cin >> val;
            }

            if (type == 1) { // Doubly Linked List
                switch (choice) {
                    case 1: dll.insertAtBeginning(val); break;
                    case 2: dll.insertAtEnd(val); break;
                    case 3: dll.deleteNode(val); break;
                    case 4: dll.search(val); break;
                    case 5: dll.display(); break;
                    default: cout << "Invalid choice!\n";
                }
            } else if (type == 2) { // Circular Linked List
                switch (choice) {
                    case 1: cll.insertAtBeginning(val); break;
                    case 2: cll.insertAtEnd(val); break;
                    case 3: cll.deleteNode(val); break;
                    case 4: cll.search(val); break;
                    case 5: cll.display(); break;
                    default: cout << "Invalid choice!\n";
                }
            }
        }
    }
    cout << "Exiting...\n";
    return 0;
}