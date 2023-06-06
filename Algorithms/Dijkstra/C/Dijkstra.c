#include <stdio.h>
#include <stdlib.h>
#include <float.h>

//linked list to save the result of Dijkstra's algorithm
typedef struct Node{
    int value;
    struct Node* next;
}Node;

//creates a node for the list
Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

//adds a node at the beginning of the list
Node* addFirst(Node* node, int newValue){
    if(node == NULL){
        return createNode(newValue);
    }else{
        Node* newNode = createNode(newValue);
        newNode->next = node;
        return newNode;
    }
}

//adds a node at the end of the list
Node* addLast(Node* node, int newValue){
    if(node == NULL){
        return createNode(newValue);
    }else{
        Node* newNode = createNode(newValue);
        Node* iterator = node;
        while(iterator->next != NULL){
            iterator = iterator->next;
        }
        iterator->next = newNode;
        return node;
    }
}

//prints the whole list
void printList(Node* node){
    Node* iterator = node;
    while(iterator != NULL){
        printf("%d --> ",iterator->value);
        iterator = iterator->next;
    }
    printf("NULL\n");
}

//performs Dijkstra's algorithm on the given graph from origin to destination
Node* bestPath(int numberOfNodes, double graph[numberOfNodes][numberOfNodes],  int origin, int destination){
    double distances[numberOfNodes];
    for(int i = 0; i < numberOfNodes; i++){
        distances[i] = DBL_MAX;
    }
    distances[origin] = 0;
    int visited[numberOfNodes];
    for(int i = 0; i < numberOfNodes; i++){
        visited[i] = 0;
    }
    int previous[numberOfNodes];
    for(int i = 0; i < numberOfNodes; i++){
        previous[i] = -1;
    }
    for(int i = 0; i < numberOfNodes - 1; i++){
        double minDistance = DBL_MAX;
        int minDistanceLoc = -1;
        for(int j = 0; j < numberOfNodes; j++){
            if(distances[j] < minDistance && !visited[j]){
                minDistance = distances[j];
                minDistanceLoc = j;
            }
        }
        if(minDistanceLoc == -1){
            break;
        }
        visited[minDistanceLoc] = 1;
        for(int j = 0; j < numberOfNodes; j++){
            double edgeWeight = graph[minDistanceLoc][j];
            if(!visited[j] && edgeWeight != 0){
                double newDistance = edgeWeight + distances[minDistanceLoc];
                if(distances[j] > newDistance){
                    distances[j] = newDistance;
                    previous[j] = minDistanceLoc;
                }
            }
        }
    }
    if(previous[destination] != -1){
        Node* path = NULL;
        int node = destination;
        while(node != -1){
            path = addFirst(path, node);
            node = previous[node];
        }
        return path;
    }else{
        return NULL;
    }
}

int main(){
    double graph[][8] =     {{0, 2, 4, 0, 2, 0, 0, 0},
                            {2, 0, 0, 0, 0, 0, 0, 6},
                            {4, 0, 0, 0, 0, 0, 0, 3},
                            {0, 0, 0, 0, 1.5, 0, 0, 3},
                            {2, 0, 0, 1.5, 0, 2, 2, 0},
                            {0, 0, 0, 0, 2, 0, 1, 0},
                            {0, 0, 0, 0, 0, 1, 0, 3},
                            {0, 6, 3, 3, 0, 0, 3, 0}};   
    Node* list = bestPath(8,graph,0,7);
    printList(list);
}