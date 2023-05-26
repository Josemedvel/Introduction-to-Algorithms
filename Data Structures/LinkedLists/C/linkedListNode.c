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
//TODO
int removeAt(int index, Node* head){
    return 0;
}
//TODO
int contains(int value, Node* head){
    return 0;
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

Node* insertAt(int index, int newValue, Node* head){
    if(index < 0){
        printf("Non positive indexes are not valid\n");
        return head;
    }
    if(index > getSize(head)){
        printf("Indexes cannot go higher than the actual size\n");
        return head;
    }
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(index == 0){
        return addFirst(head, newValue);
    }
    
    Node* iterator = head;
    for(size_t i = 0; i < index - 1; i++){
        iterator = iterator->next;
    }
    Node* newNode = createNode(newValue);
    newNode->next = iterator->next;
    iterator->next = newNode;
    return head;
}

int getValue(int index, Node* head){
    if(index >= getSize(head)){
        printf("Indexes cannot go higher than the actual size\n");
        return -1;
    }
    if(head == NULL){
        printf("List is empty\n");
        return -1;
    }
    if(index == 0){
        return head->value;
    }

    Node* iterator = head;
    for(int i = 0; i < index; i++){
        iterator = iterator->next;
    }
    return iterator->value;
}




int main(int argc, char* argv[]){
    Node* list = NULL;
    for(int i = 0; i < 5; i++){
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
    list = insertAt(0, 10, list);
    printf("Size of List: %d\n", getSize(list));
    printList(list);
    list = insertAt(4, 20, list);
    printf("Size of List: %d\n", getSize(list));
    printList(list);
    list = insertAt(2, 30, list);
    printf("Size of List: %d\n", getSize(list));
    printList(list);
    printf("Element at 0: %d\n", getValue(0, list));
    printf("Element at 3: %d\n", getValue(3, list));
    printf("Element at 4: %d\n", getValue(4, list));
    free(list);
    return EXIT_SUCCESS;
}