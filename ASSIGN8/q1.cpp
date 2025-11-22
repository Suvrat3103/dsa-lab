#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
void preorder(Node* root){
    if(root!=nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}
void postorder(Node* root){
    if(root!=nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    return;
}
void inorder(Node* root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return;
}
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = new Node(16);
    root->left = new Node(8);
    root->right = new Node(25);
    root->right->right = new Node(42);
    root->right->right->right = new Node(62);
    root->right->right->right->left = new Node(49);
    root->right->right->right->left->right = new Node(58);
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    deleteTree(root);
    
    return 0;
}