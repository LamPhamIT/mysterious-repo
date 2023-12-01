#include <iostream>
using namespace std;

struct Node {
    struct Node* leftChild;
    int data;
    struct Node* rightChild;
} *root = NULL;

void insert(int key) {
    struct Node* t = root;
    struct Node* r, *p;
    if(root == NULL) {
        p = new Node;
        p->data = key;
        p->leftChild = p->rightChild = NULL;
        root = p;
        return;
    }
    while( t != NULL) {
        r = t;
        if(key < t->data) {
            t = t->leftChild;
        } else if(key > t->data) {
            t = t->rightChild;
        } else {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->leftChild = p->rightChild = NULL;
    if(key < r->data) {
        r->leftChild = p;
    } else {
        r->rightChild = p;
    }
}

struct Node* insertRecursive(struct Node* p , int key) {
    struct Node* t = NULL;
    if(p) {
        if(p->data < key) p->leftChild = insertRecursive(p->leftChild);
        else if(p->data > key) p->rightChild = insertRecursive(p->rightChild);
        else return p;
    } else {
        t = new Node;
        t->data = key;
        t->leftChild = t->rightChild = NULL;
        return t;
    }
}

void inorder(struct Node* p) {
    if(p) {
        inorder(p->leftChild);
        cout << p->data << " ";
        inorder(p->rightChild);
    }
}

struct Node* search(struct Node* p, int key) {
    if(p) {
        if(key == p->data) return p;
        else if(key < p->data) return search(p->leftChild, key);
        else return search(p->rightChild, key);
    } else {
        return NULL;
    }
}


int main() {
    insert(10);
    insert(11);
    insert(3);
    insert(20);
    insert(15);
    cout << "start\n";
    inorder(root);
    cout << search(root, 11)->data;
    cout << "\nend";
    return 0;
}
