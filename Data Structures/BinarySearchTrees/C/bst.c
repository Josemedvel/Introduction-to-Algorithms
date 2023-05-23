#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int num){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = num;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int num){
    if(root == NULL){
        return createNode(num);
    }else{
        if(num < root->val){
            root->left = insertNode(root->left, num);
        }else{
            root->right = insertNode(root->right, num);
        }
    }
    return root;
}
void preOrder(Node* root){
    if(root != NULL){
        printf("%d ", root->val);
    }
    if(root->left != NULL){
        preOrder(root->left);
    }
    if(root->right != NULL){
        preOrder(root->right);
    }
}

void inOrder(Node* root)
{
    if (root == NULL) {
        return;
    }else{
        inOrder(root->left);
        printf("%d ", root->val);
        inOrder(root->right);
    }
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->val);

}

int main(){
    int array [] = {2,1,5,4,6,3,7};
    int size = 7;
    Node* root = NULL;
    for(int i = 0; i < size; i++){
        root = insertNode(root, array[i]);
    }
    printf("InOrder: ");
    inOrder(root);
    printf("\n");
    printf("PreOrder: ");
    preOrder(root);
    printf("\n");
    printf("PostOrder: ");
    postOrder(root);
    printf("\n");
    return EXIT_SUCCESS;
}