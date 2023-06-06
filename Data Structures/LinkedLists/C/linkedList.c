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
    if((*list) == NULL){
        printf("List is empty");
        return -1;
    }
    Node* newNode = createNode(newValue);
    newNode->next = (*list)->head;
    (*list)->head = newNode;
    (*list)->size++;
    return newValue;
}
//TODO
int insertAt(int index, int newValue, LinkedList** list){
    return 0;
}
//TODO
int getValue(int index, LinkedList** list){
    if((*list) == NULL){
        printf("List is empty\n");
        return -1;
    }
    if(index < 0 || index > (*list)->size){//probar con última posición
        printf("Indexes cannot go higher than the actual size\n");
        return -1;
    }
    if(index == 0){
        return (*list)->head->value;
    }
    Node* iterator = (*list)->head;
    for(int i = 0; i < index; i++){
        iterator = iterator->next;
    }
    return iterator->value;
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
    addFirst(&list, 50);
    printList(&list);
    printf("Size of list: %d\n", list->size);
    printf("Element at 2: %d\n", getValue(2, &list));
    return EXIT_SUCCESS;
}