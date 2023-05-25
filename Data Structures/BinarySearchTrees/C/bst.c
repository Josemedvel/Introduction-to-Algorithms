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
Node* search(Node* root, int num){
    if(root == NULL){
        return NULL;
    }
    if(num < root->val){
        return search(root->left, num);
    }else if(num > root->val){
        return search(root->right, num);
    }else{
        return root;
    }
}
Node* searchIter(Node* root, int num){
    if(root == NULL){
        return NULL;
    }
    Node* it = root;
    while(1){
        if(num < it->val && it->left != NULL){
            it = it->left;
        }else if(num > it->val && it->right != NULL){
            it = it->right;
        }else if(num == it->val){
            return it;
        }
        else{
            return NULL;
        }
    }
}
Node* minimum(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* min = root;
    while(min->left != NULL){ //can still traverse
        min = root->left;
    }
    return min;
}
Node* maximum(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* max = root;
    while(max->right != NULL){
        max = max->right;
    }
    return max;
}

int checkHeightBalance(Node* root, int* height){
    int leftHeight = 0;
    int rightHeight = 0;
    int l = 0;
    int r = 0;
    if(root == NULL){ //trivial solution
        *height = 0;
        return 1;
    }
    l = checkHeightBalance(root->left, &leftHeight);
    r = checkHeightBalance(root->right, &rightHeight);
    
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    if((leftHeight - rightHeight) > 1 || (rightHeight - leftHeight) > 1){
        return 0; //not balanced
    }else{
        return l && r; // if balanced
    }
}

Node* insertNode(Node* root, int num){
    if(root == NULL){
        return createNode(num);
    }
    if(num < root->val){
        root->left = insertNode(root->left, num);
    }else{
        root->right = insertNode(root->right, num);
    }
    return root;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
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
    printf("Minimum: ");
    Node* min = minimum(root);
    if(min != NULL){
        printf("%d",min->val);
    }
    printf("\n");
    printf("Maximum: ");
    Node* max = maximum(root);
    if(max != NULL){
        printf("%d",max->val);
    }
    printf("\n");
    
    printf("Search recursive (5): ");
    Node* search5 = search(root, 5);
    if(search5 == NULL){
        printf("Not found!\n");
    }else{
        printf("Value of %d\n",search5->val);
    }
    printf("Search recursive (8): ");
    Node* search8 = search(root, 8);
    if(search8 == NULL){
        printf("Not found!\n");
    }else{
        printf("Value of %d\n",search8->val);
    }

    printf("Search iterative (5): ");
    Node* search5Iter = searchIter(root, 5);
    if(search5Iter == NULL){
        printf("Not found!\n");
    }else{
        printf("Value of %d\n",search5Iter->val);
    }
    printf("Search iterative (8): ");
    Node* search8Iter = searchIter(root, 8);
    if(search8Iter == NULL){
        printf("Not found!\n");
    }else{
        printf("Value of %d\n",search8Iter->val);
    }
    printf("Balanced: ");
    int height = 0;
    printf("%d\n", checkHeightBalance(root, &height));
    free(root);
    return EXIT_SUCCESS;
}