
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
        cout << "Enter left child of " << p->data << " ";
        cin >> x;
        if(x != -1 ) {
            t = new Node;
            t->data = x;
            t->leftChild = t->rightChild = NULL;
            p->leftChild = t;
            q.push(t);
        }
        cout << "Enter right child of " << p->data << " ";
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

void levelorder(struct Node* p) {
    queue<struct Node*> q;
    q.push(p);
    cout << p->data << " ";
    while(!q.empty()) {
        p = q.front();
        q.pop();
        if(p->leftChild) {
            cout << p->leftChild->data << " ";
            q.push(p->leftChild);
        }
         if(p->rightChild) {
            cout << p->rightChild->data << " ";
            q.push(p->rightChild);
        }
    }
}

int countNodes(struct Node* p) {
    if(p)
        return countNodes(p->leftChild) + countNodes(p->rightChild) + 1;
    return 0;
}
int height(struct Node* p) {
    int x = 0, y = 0;
    if(p) {
        return 0;
    }
    x = height(p->leftChild);
    y = height(p->rightChild);
    if(x > y) return x + 1;
    else return y + 1;
}

int countLeafs(struct Node* p) {
    int x = 0, y = 0;
    if(p) {
        if(!(p->leftChild && p->rightChild)) {
            return 1;
        } else {
            x += countLeafs(p->leftChild);
            y += countLeafs(p->rightChild);
        }
    }
    return x + y;
}

int main() {
    create();
    // preorder(root);
    levelorder(root);
    cout << countLeafs(root);
    cout << "end";
    return 0;
}
