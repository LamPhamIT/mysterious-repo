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

void removeElementsByValue(LinkedList* linkedList, int value) {
    if(linkedList->head == NULL) {
        return;
    }
    Node* temp = linkedList->head->next;
    Node* preTemp = linkedList->head;
    while(temp != NULL) {
        if(temp->data == value) {
            Node* alterTemp = temp;
            temp = temp->next;
            preTemp->next = temp;
            free(alterTemp);
        } else {
            preTemp = temp;
            temp = temp->next;
        }
    }
    if(linkedList->head->data == value) {
        Node* alterHead = linkedList->head;
        linkedList->head = linkedList->head->next;
        free(alterHead);
    }
    linkedList->tail = preTemp;
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

bool isEmpty(LinkedList linkedList) {
    if(linkedList.head != NULL) {
        return true;
    } 
    return false;
}

bool insert(LinkedList* linkedList, int position, int value) {
    Node* temp = linkedList->head;
    if(temp == NULL && position == 1) {
        Node* node = createNode(value);
        linkedList->head = node;
        linkedList->tail = node;
        return true;
    } else if(temp == NULL && !(position == 1)) {
        return false;
    } else if(temp != NULL) {
        if(position == 1) {
            Node* node = createNode(value);
            node->next = linkedList->head;
            linkedList->head = node;
            return true;
        } 
        int count = 2;
        Node* temp = linkedList->head;
        while(temp != NULL) {
            if(count == position) {
                Node* node = createNode(value);
                node->next= temp->next;
                temp->next = node;
                return true;
            }
            temp = temp->next;
            count++;
        }
        return false;
    }
}


void freeList(LinkedList* linkedList) {
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
    Node* fourthNode = createNode(9);
    
     
    pushBack(&linkedList, firstNode);
    pushBack(&linkedList, secondNode);
    pushBack(&linkedList, thirstNode);
    pushBack(&linkedList, fourthNode);
    
    insert(&linkedList, 1, 69);

    display(linkedList);
    freeList(&linkedList);

  return 0;
}
