/*  10. Design, Develop and Implement a menu driven Program for the following operations on Binary Tree (BT) of Integers.
    a. Create a BT of N Integers.
    b. Traverse the BT in Inorder, Preorder and Post Order.
    c. Search the BT for a given element (KEY) and display the suitable message.
    d. Exit. 
*/

#include<stdio.h>
#include<stdlib.h>

int size = 0, maxSize = 0;

struct node {
    int data;
    struct node *left, *right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct node *root) {
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);    
}

void preorder(struct node *root) {
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);    
}

void postorder(struct node *root) {
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);    
}

struct node *search(struct node *root, int key) {
    if(root==NULL || root->data==key)
        return root;

    struct node *found = search(root->left, key);
    if(found != NULL)
        return found;
    return search(root->right, key);        
}

struct node *insert(struct node *root) {
    if(size >= maxSize) {
        printf("Cannot insert more nodes, maximum size reached\n");
        return root;
    }

    int isLeft, isRight;
    if(root == NULL) {
        int ele;
        printf("Enter the element : ");
        scanf("%d", &ele);
        size++;
        return createNode(ele);
    }

    printf("Do you want to insert to the left of %d ? (1->YES, 0->NO) : ", root->data);
    scanf("%d", &isLeft);
    if(isLeft && size < maxSize)
        root->left = insert(root->left);
    if(size >= maxSize) 
        return root;

    printf("Do you want to insert to the right of %d ? (1->YES, 0->NO) : ", root->data);
    scanf("%d", &isRight);
    if(isRight && size < maxSize)
        root->right = insert(root->right);
    return root;            
}

void setSize(int max) {
    maxSize = max;
}

int main() {
    struct node *root = NULL;
    int max, choice, key;

    printf("Enter the number of nodes in the tree : ");
    scanf("%d", &max);
    setSize(max);

    printf("\nMENU :\n");
    printf("1. Insertion\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Search an element\n");
    printf("6. Exit\n");

    do {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1 : root = insert(root);
                     break;

            case 2 : printf("Inorder Traversal : ");
                     inorder(root);
                     printf("\n");
                     break;

            case 3 : printf("Preorder Traversal : ");
                     preorder(root);
                     printf("\n");
                     break;

            case 4 : printf("Postorder Traversal : ");
                     postorder(root);
                     printf("\n");
                     break;

            case 5 : printf("Enter the element to be searched : ");
                     scanf("%d", &key);
                     struct node *result = search(root, key);
                     if(result != NULL)
                        printf("%d is found in the Binay Tree\n", key);
                     else
                        printf("%d is not found in the Binary Tree\n", key);
                     break;

            case 6 : printf("Thank You!\n");
                     break;

            default : printf("Invalid Choice\n");                                                            
        }
    } while(choice != 6);

    return 0;
}