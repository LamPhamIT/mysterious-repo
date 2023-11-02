#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

struct LinkedList {
    Node* head;
    Node* tail;
};
typedef struct LinkedList LinkedList;

Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void init(LinkedList* linkedList) {
    linkedList->head = NULL;
    linkedList->tail = NULL;
}

bool pushTop(LinkedList* linkedList, Node* node) {
    if(node == NULL) {
        return false;
    }
    if(linkedList->head == NULL) {
        linkedList->head = node;
        linkedList->tail = node;
        return true;
    }
    node->next = linkedList->head;
    linkedList->head = node;
    return true;
}

bool pushBack(LinkedList* linkedList, Node* node) {
    if(node == NULL) {
        return false;
    }
    if(linkedList->head == NULL) {
        linkedList->head = node;
        linkedList->tail = node;
        return true;
    }
    linkedList->tail->next = node;
    linkedList->tail = node;
    return true;
}

bool popTop(LinkedList* linkedList) {
    if(linkedList->head == NULL) {
        return true;
    }
    Node* temp = linkedList->head;
    linkedList->head = linkedList->head->next;
    free(temp);
    return true;
}

bool popBack(LinkedList* linkedList) {
    if(linkedList->head == NULL) {
        return true;
    }
    Node* temp = linkedList->head;
    Node* preTemp = NULL;
    while(temp->next != NULL) {
        preTemp = temp;
        temp = temp->next;
    }
    if(preTemp == NULL) {
        Node* alterHead = linkedList->head;
        linkedList->head = NULL;
        linkedList->tail = NULL;
        free(alterHead);
        return true;
    }
    
    linkedList->tail = preTemp;
    linkedList->tail->next = NULL;
    free(temp);
    return true;
}

// Mark 
void removeElementsByValue(LinkedList* linkedList, int value) {
    if(linkedList->head == NULL) {
        return;
    }
    Node* temp = linkedList->head->next;;
    Node* preTemp = linkedList->head;
    while(temp != NULL) {
        if(temp->data == value) {
            preTemp->next = temp->next;
        }
        preTemp = temp;
        temp = temp->next;
    }
    if(linkedList->head->data == value) {
        
    }
}

void display(LinkedList linkedList) {
    if(linkedList.head == NULL) {
        return;
    }
    Node* node = linkedList.head;
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void free_list(LinkedList* linkedList) {
    if(linkedList->head == NULL) {
        return;
    }
    Node* node = linkedList->head;
    while(node != NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    LinkedList linkedList;
    init(&linkedList);
    
    Node* firstNode = createNode(11);
    Node* secondNode = createNode(9);
    Node* thirstNode = createNode(20);
    
    pushBack(&linkedList, firstNode);
    pushBack(&linkedList, secondNode);
    pushBack(&linkedList, thirstNode);

    display(linkedList);
    free_list(&linkedList);

  return 0;
}
