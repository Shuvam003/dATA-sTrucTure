#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int data;
    struct tnode *right, *left;
} tnode;

typedef struct node
{
    tnode *key;
    struct node *next;
} queue;

queue *head = NULL;

int isEmpty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

void push(tnode *key)
{
    queue *newnode = (queue *)malloc(sizeof(queue));
    newnode->key = key;
    newnode->next = NULL;
    if (head == NULL)
        head = newnode;
    else
    {
        queue *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

tnode *pop()
{
    if (!isEmpty())
    {
        tnode *key = head->key;
        queue *temp = head;
        head = head->next;
        free(temp);
        return key;
    }
}

void clearQ()
{
    while (head != NULL)
    {
        pop();
    }
    return;
}

tnode *newnode(int data)
{
    tnode *newnode = (tnode *)malloc(sizeof(tnode));
    newnode->data = data;
    newnode->right = newnode->left = NULL;
    return newnode;
}

void insert(tnode **root, int data)
{
    if (*root == NULL)
    {
        *root = newnode(data);
    }
    else
    {
        clearQ();
        push(*root);
        while (!isEmpty())
        {
            tnode *n = pop();
            if (n->left == NULL)
            {
                n->left = newnode(data);
                return;
            }
            else if (n->right == NULL)
            {
                n->right = newnode(data);
                return;
            }
            push(n->left);
            push(n->right);
        }
    }
    return;
}

void removenode(tnode *root, tnode *n)
{
    if (root == NULL)
    {
        return;
    }
    if (root == n)
    {
        free(n);
        root = NULL;
        return;
    }
    if (root->left == n)
    {
        free(n);
        root->left = NULL;
        return;
    }
    if (root->right == n)
    {
        free(n);
        root->right = NULL;
        return;
    }
    removenode(root->left, n);
    removenode(root->right, n);
}

tnode *deletenode(tnode *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == data)
        {
            free(root);
            root = NULL;
            return root;
        }
        printf("Data not present...");
        return root;
    }
    clearQ();
    push(root);
    tnode *current, *keynode = NULL, *ptr;
    while (!isEmpty())
    {
        current = pop();
        if (current->data == data)
        {
            keynode = current;
        }
        if (current->left != NULL)
        {
            push(current->left);
        }
        if (current->right != NULL)
        {
            push(current->right);
        }
    }
    if (keynode != NULL)
    {
        keynode->data = current->data;
        removenode(root, current);
    }
    else
    {
        printf("Data not present...");
    }
    return root;
}

void levelorder(tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    clearQ();
    push(root);
    while (!isEmpty())
    {
        tnode *n = pop();
        printf("%d  ", n->data);
        if (n->left != NULL)
        {
            push(n->left);
        }
        if (n->right != NULL)
        {
            push(n->right);
        }
    }
    return;
}

int main()
{
    tnode *root = NULL;
    int data;
    printf("\n--->Main Menu<---\n1.Insert node in binary tree.\n2.Delete node from binary tree.\n3.Level order traversal.\n4.Exit.");
    int choice = 0;
    while (choice != 5)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("You choose to INSERT a node in Binary tree...");
            printf("\nEnter data: ");
            scanf("%d", &data);
            insert(&root, data);
            printf("A node has been ADDED to Binary tree...");
            break;
        case 2:
            printf("You choose to DELETE a node from Binary tree...");
            printf("\nEnter data: ");
            scanf("%d", &data);
            root = deletenode(root, data);
            break;
        case 3:
            printf("You choose to DISPLAY tree using LEVEL ORDER TRAVERSAL...");
            printf("\nValues in Binary Tree:  [  ");
            levelorder(root);
            printf("]");
            break;
        case 4:
            printf("\nCODE SUCCESSFULLY TERMINATED...\n");
            exit(0);
        default:
            printf("\nEnter valid choice...\n");
            break;
        }
    }
}