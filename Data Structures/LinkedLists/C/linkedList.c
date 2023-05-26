#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList{
    struct Node* head;
    int size;
} LinkedList;

Node* createNode(int newValue){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = newValue;
    newNode->next = NULL;
    return newNode;
}

LinkedList* createLinkedList(){
    LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

int addLast(LinkedList** list, int newValue){
    if((*list) == NULL){
        printf("List does not exists");
        return -1;
    }else{
        Node* newNode = createNode(newValue);
        if((*list)->head == NULL){
            (*list)->head = newNode;
            (*list)->head->next = NULL;
        }else{
            Node* iterator = (*list)->head;
            while(iterator->next != NULL){
                iterator = iterator->next;
            }
            iterator->next = newNode;
        }
        (*list)->size++;
        return newNode->value;
    }
}
//TODO
int addFirst(LinkedList** list, int newValue){
    return 0;
}
//TODO
int insertAt(int index, int newValue, LinkedList** list){
    return 0;
}
//TODO
int getValue(int index, LinkedList** list){
    return 0;
}
//TODO
int contains(int value, LinkedList** list){
    return 0;
}
//TODO
int removeFirst(LinkedList** list){
    return 0;
}
//TODO
int removeLast(LinkedList** list){
    return 0;
}
//TODO
int removeAt(int index, LinkedList** list){
    return 0;
}



void printList(LinkedList** list){
    if((*list) == NULL){
        printf("List does not exists");
        return;
    }
    Node* iterator = (*list)->head;
    do{
        printf("%d --> ", iterator->value);
        iterator = iterator->next;
    }
    while(iterator != NULL);
    printf("NULL\n");
}

int main(){
    LinkedList* list = createLinkedList(); //empty list
    addLast(&list, 1);
    addLast(&list, 2);
    printList(&list);
    return EXIT_SUCCESS;
}