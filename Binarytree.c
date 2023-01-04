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
} node;

node *head = NULL;

int isEmpty()
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

void enq(tnode *key)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->key = key;
    newnode->next = NULL;
    if (head == NULL)
        head = newnode;
    else
    {
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

tnode *deq()
{
    if (!isEmpty())
    {
        tnode *key = head->key;
        node *temp = head;
        head = head->next;
        free(temp);
        return key;
    }
}

tnode *newnode(int data)
{
    tnode *newnode = (tnode *)malloc(sizeof(tnode));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

tnode *insert(tnode *root, int data)
{
    if (root == NULL)
    {
        root = newnode(data);
    }
    enq(root);
    while (!isEmpty())
    {
        tnode *n = deq();
        if (n->left == NULL)
        {
            n->left = newnode(data);
            return root;
        }
        else if (n->right == NULL)
        {
            n->right = newnode(data);
            return root;
        }
        else
        {
            enq(n->left);
            enq(n->right);
        }
    }
}

void inorder(tnode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

void preorder(tnode *root)
{
    if (root == NULL)
        return;

    printf("%d  ", root->data);
    preorder(root->left);
    preorder(root->right);
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

tnode *delete (tnode *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
        {
            free(root);
            root = NULL;
            return root;
        }
        return root;
    }
    tnode *keynode = NULL, *current;
    enq(root);
    while (!isEmpty())
    {
        current = deq();
        if (current->data == key)
        {
            keynode = current;
        }
        if (current->left != NULL)
        {
            enq(current->left);
        }
        if (current->right)
        {
            enq(current->right);
        }
    }
    if (keynode != NULL)
    {
        keynode->data = current->data;
        removenode(root, current);
    }
    return root;
}

int main()
{
    tnode *root = newnode(10);
    root->left = newnode(11);
    root->left->left = newnode(7);
    root->right = newnode(9);
    root->right->left = newnode(15);
    root->right->right = newnode(8);
    printf("Inorder traversal before insertion: ");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    int key = 12;
    root = insert(root, key);
    key = 14;
    root = insert(root, key);
    printf("Inorder traversal after insertion: ");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    int k = 11;
    root = delete (root, k);
    k = 7;
    root = delete (root, k);
    printf("Inorder traversal after insertion: ");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");

    return 0;
}