#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* createNode(int newValue){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = newValue;
    newNode->next = NULL;
    //printf("valor nuevo: %d\n", newValue);
    return newNode;
}

int getSize(Node* head){
    if(head == NULL){
        return 0;
    }
    Node* iterator = head;
    int size = 1;
    while(iterator->next != NULL){
        iterator = iterator->next;
        size++;
    }
    return size;
}

Node* addFirst(Node* head, int newValue){
    if(head == NULL){
        head = createNode(newValue);
        head->next = NULL;
        return head;
    }
    Node* newHead = createNode(newValue);
    newHead->next = head;
    return newHead;
}

Node* addLast(Node* head, int newValue){
    if(head == NULL){
        head = createNode(newValue);
        return head;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = newValue;
    newNode->next = NULL;
    Node* iterator = head;
    while(iterator->next != NULL){
        iterator = iterator->next;
    }
    iterator->next = newNode;
    return head;
}

int removeLast(Node** head){
    if(*head == NULL){
        printf("List is empty\n");
        return -1;
    }
    int result = 0;
    Node* iterator = *head;
    Node* prev = NULL;
    while(iterator->next != NULL){
        prev = iterator;
        iterator = iterator->next;
    }
    result = iterator->value;
    prev->next = NULL;
    free(iterator);
    return result;
}

int removeFirst(Node** head){
    if(*head == NULL){
        printf("List is empty\n");
        return -1;
    }
    Node* oldHead = *head;
    int result = oldHead->value;
    *head = oldHead->next;
    oldHead->next = NULL;
    free(oldHead);
    return result;
}

void printList(Node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    Node* iterator = head;
    do{
        printf("%d --> ",iterator->value);
        iterator = iterator->next;
    }
    while(iterator != NULL);
    printf("NULL\n");
}

int main(int argc, char* argv[]){
    Node* list = NULL;
    for(int i = 0; i < 5; i++){
        //list = addFirst(list, i);
        list = addLast(list, i);
    }
    printf("Size of List: %d\n", getSize(list));
    printList(list);
    removeLast(&list);
    printf("Size of List: %d\n", getSize(list));
    printList(list);
    removeFirst(&list);
    printf("Size of List: %d\n", getSize(list));
    printList(list);
    return EXIT_SUCCESS;
}