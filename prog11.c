/*  11. Design, Develop and Implement a menu driven Program for the following operations on Binary Search Tree (BST) of Integers.
    a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2.
    b. Traverse the BST in Inorder, Preorder and Post Order.
    c. Search the BST for a given element (KEY) and report the appropriate message.
    d. Exit.
*/

#include<stdio.h>
#include<stdlib.h>

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

struct node *insert(struct node *root, int data) {
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    return root;            
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

    if(key > root->data)
        return search(root->right, key);
    else
        return search(root->left, key);        
}

int main() {
    struct node *root = NULL;
    int n, choice, key;
    int values[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};

    n = (sizeof(values)/sizeof(values[0]));

    for(int i=0; i<n; i++)
        root = insert(root, values[i]);

    printf("\nMENU :\n");
    printf("1. Inorder Traversal\n");
    printf("2. Preorder Traversal\n");
    printf("3. Postorder Traversal\n");
    printf("4. Search an element\n");
    printf("5. Exit\n");

    do {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 : printf("Inorder Traversal : ");
                     inorder(root);
                     printf("\n");
                     break;

            case 2 : printf("Preorder Traversal : ");
                     preorder(root);
                     printf("\n");
                     break;

            case 3 : printf("Postorder Traversal : ");
                     postorder(root);
                     printf("\n");
                     break;

            case 4 : printf("Enter the element to be searched : ");
                     scanf("%d", &key);
                     struct node *result = search(root, key);
                     if(result != NULL)
                        printf("%d is found in the BST\n", key);
                     else
                        printf("%d is not found in the BST\n", key);
                     break;

            case 5 : printf("Thank You!\n");
                     break;

            default : printf("Invalid Choice\n");                                                   
        }
    } while(choice != 5);

    return 0;
}