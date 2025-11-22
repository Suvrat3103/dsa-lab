#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char c) {
        data = c;
        next = nullptr;
        prev = nullptr;
    }
};

class dll{
    Node* head=nullptr;
    Node* temp=nullptr;
    
public:
    void insert(char val){
        Node* newnode= new Node(val);
        if(head==nullptr){
            head=newnode;
            temp=newnode;
            return;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    
    }
    void display(){
        Node* curr=head;
        while(curr){
            cout<<curr->data<<"  ";
            curr=curr->next;
        }
        cout<<endl;
    }
    void size(){
        int len=0;
        Node* curr=head;
        while(curr){
            len++;
            curr=curr->next;
        }
        cout<<"Size of list is "<<len<<endl;
    }
   void palindrome(){
        Node* start = head;
        Node* end = temp;
        if (head == nullptr) {
            cout << "List is empty (considered a palindrome)." << endl;
            return;
        }
        bool flag = true;
        while(start != end && start->prev != end) { 
            if(start->data != end->data){
                flag = false;
                break;
            }
            start = start->next;
            end = end->prev;
        }
        
        if(flag){
            cout << "It is a palindrome" << endl;
        }
        else{
            cout << "Not a palindrome" << endl;
        }
    }
};

int main() {
    
    dll l;
    l.insert('l');
    l.insert('e');
    l.insert('v');
    l.insert('e');
    //l.insert('l');
    l.display();
    l.palindrome();
    
    return 0;
}