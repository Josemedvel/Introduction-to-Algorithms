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

int addFirst(LinkedList** list, int newValue){
    if((*list) == NULL){
        printf("List does not exist\n");
        return -1;
    }
    Node* newNode = createNode(newValue); 
    if((*list)->size == 0){
        (*list)->head = newNode;
    }else{
        newNode->next = (*list)->head;
        (*list)->head = newNode;
    }
    (*list)->size++;
    return newValue;
}

int insertAt(int index, int newValue, LinkedList** list){
    if((*list) == NULL){
        printf("List does not exist\n");
        return -1;
    }
    if(index < 0 || index > (*list)->size){
        printf("Indexes cannot go higher than the actual size nor below zero\n");
        return -1;
    }
    if(index == 0){
        return addFirst(list, newValue);
    }
    Node* iterator = (*list)->head;
    Node* prev = NULL;
    for(int i = 0; i < index; i++){
        prev = iterator;
        iterator = iterator->next;
    }
    Node* newNode = createNode(newValue);
    newNode->next = iterator;
    prev->next = newNode;
    (*list)->size++;
    return newValue;
}

int getValue(int index, LinkedList** list){
    if((*list) == NULL){
        printf("List does not exist\n");
        return -1;
    }
    if(index < 0 || index >= (*list)->size){
        printf("Indexes cannot go higher than the actual size nor below zero\n");
        return -1;
    }
    Node* iterator = (*list)->head;
    for(int i = 0; i < index; i++){
        iterator = iterator->next;
    }
    return iterator->value;
}

int contains(int value, LinkedList** list){
    if((*list) == NULL){
        printf("List does not exist\n");
        return -1;
    }
    if((*list)->size == 0){
        printf("List is empty\n");
        return -1;
    }
    Node* iterator = (*list)->head;
    do{
        if(iterator->value == value){
            return 1;
        }
        iterator = iterator->next;
    }while(iterator != NULL);
    return 0;
}

int removeFirst(LinkedList** list){
    if((*list) == NULL){
        printf("List does not exist\n");
        return -1;
    }
    Node* oldNode = (*list)->head;
    int result = (*list)->head->value;
    (*list)->head = oldNode->next;
    oldNode->next = NULL;
    free(oldNode);
    (*list)->size--;
    return result;
}

int removeLast(LinkedList** list){
    if((*list) == NULL){
        printf("List does not exist\n");
        return -1;
    }
    Node* oldNode = (*list)->head;
    Node* prev = NULL;
    while(oldNode->next != NULL){
        prev = oldNode;
        oldNode = oldNode->next;
    }
    prev->next = NULL;
    int result = oldNode->value;
    free(oldNode);
    (*list)->size--;
    return result;
}

int removeAt(int index, LinkedList** list){
    if((*list) == NULL){
        printf("List does not exist\n");
        return -1;
    }
    if(index < 0 || index > (*list)->size){
        printf("Indexes cannot go higher than the actual size nor below zero\n");
        return -1;
    }
    if(index == 0){
        return removeFirst(list);
    }
    Node* iterator = (*list)->head;
    Node* prev = NULL;
    for(int i = 0; i < index; i++){
        prev = iterator;
        iterator = iterator->next;
    }
    prev->next = iterator->next;
    iterator->next = NULL;
    int result = iterator->value;
    free(iterator);
    (*list)->size--;
    return result;
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
    addFirst(&list, 100);
    printList(&list);
    printf("Size of list: %d\n", list->size);
    printf("Element at 2: %d\n",getValue(2, &list));
    printf("Element at 0: %d\n",getValue(0, &list));
    printf("Element at 3: %d\n",getValue(3, &list));
    insertAt(2, 20, &list);
    insertAt(5, 88, &list);
    printList(&list);
    printf("Contains 88: %d\n", contains(88, &list));
    printf("Contains 25: %d\n", contains(25, &list));
    removeFirst(&list);
    printList(&list);
    removeLast(&list);
    removeLast(&list);
    printList(&list);
    printf("Size of list: %d\n", list->size);
    addFirst(&list, 11);
    addFirst(&list, 22);
    printList(&list);
    printf("Size of list: %d\n", list->size);
    removeAt(1, &list);
    printList(&list);
    removeAt(3, &list);
    printList(&list);
    printf("Size of list: %d\n", list->size);
    free(list);
    return EXIT_SUCCESS;
}