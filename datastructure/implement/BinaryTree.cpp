#include <iostream>
#include <queue>
using namespace std;

struct Node {
    struct Node* leftChild;
    int data;
    struct Node* rightChild;
};

struct Node* root = NULL;

void create() {
    struct Node* p, *t;
    int x;
    queue<struct Node*> q;
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->leftChild = root->rightChild = NULL;
    q.push(root);
    while(!q.empty()) {
        p = q.front();
        q.pop();
        cout << "Enter left child ";
        cin >> x;
        if(x != -1 ) {
            t = new Node;
            t->data = x;
            t->leftChild = t->rightChild = NULL;
            p->leftChild = t;
            q.push(t);
        }
        cout << "Enter right child ";
        cin >> x;
        if(x != -1 ) {
            t = new Node;
            t->data = x;
            t->leftChild = t->rightChild = NULL;
            p->rightChild = t;
            q.push(t);
        }
    }
}

void preorder(struct Node* p) {
    if(p) {
        cout << p->data << " ";
        preorder(p->leftChild);
        preorder(p->rightChild);
    }
}


int main() {
    create();
    preorder(root);
    return 0;
}
