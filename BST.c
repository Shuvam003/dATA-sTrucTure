#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
} tnode;

tnode *insert(tnode *, int);
void Inorder(tnode *);
void Preorder(tnode *);
void Postorder(tnode *);
tnode *minValueNode();
tnode *deleteNode(tnode *, int);
void search(tnode*, int);

int main()
{
    tnode *root = NULL;
    int choice, item, n, i;
    printf("\nBinary Tree Operations\n");
    printf("\n1. Insert node in Binaery tree.");
    printf("\n2. Traverse in Inorder.");
    printf("\n3. Traverse in Preorder.");
    printf("\n4. Traverse in Postorder.");
    printf("\n6. Search a element.");
    printf("\n7. Delete a node.");
    printf("\n6. Exit\n");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data for node: ");
            scanf("%d", &item);
            root = insert(root, item);
            break;
        case 2:
            printf("Binary tree Traversal in INORDER \n");
            Inorder(root);
            break;
        case 3:
            printf("Binary tree Traversal in PREORDER \n");
            Preorder(root);
            break;
        case 4:
            printf("Binary tree Traversal in POSTORDER \n");
            Postorder(root);
            break;
        case 5:
            printf("Enter which node you want to delete: ");
            scanf("%d", &item);
            root = deleteNode(root, item);
            break;
        case 6:
            printf("Enter which node you want to search: ");
            scanf("%d", &item);
            search(root, item);
            break;
        case 7:
            printf("\nCODE IS SUCCESSFULLY TERMINATED...\n");
            break;
        default:
            printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
    } while (choice != 7);
    return 0;
}

tnode *newnode(int value)
{
    tnode *newnode = (tnode *)malloc(sizeof(tnode));
    newnode->left = newnode->right = NULL;
    newnode->data = value;
}

tnode *insert(tnode *root, int item)
{
    if (root == NULL)
        return newnode(item);
    else
    {
        if (item < root->data)
            root->left = insert(root->left, item);
        else if (item > root->data)
            root->right = insert(root->right, item);
        else
            printf("Duplicate Element!! Not Allowed...");
        return root;
    }
}

void Inorder(tnode *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf(" %d ", root->data);
        Inorder(root->right);
    }
}

void Preorder(tnode *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(tnode *root)
{
    if (root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ", root->data);
    }
}

tnode *minValueNode(tnode *node)
{
    tnode *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

tnode *deleteNode(tnode *root, int key)
{
    if (root == NULL)
    {
        printf("\nData not present...\n");
        return root;
    }
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            tnode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            tnode *temp = root->left;
            free(root);
            return temp;
        }
        tnode *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void search(tnode *root, int item)
{
    if (root == NULL)
    {
        printf("\nData not present...\n");
        return;
    }
    else
    {
        if (item < root->data)
            search(root->left, item);
        else if (item > root->data)
            search(root->right, item);
        else
            printf("\nData present...\n");
        return;
    }
}