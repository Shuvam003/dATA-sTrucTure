#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right, *left;
} tnode;

int cright = 0, cleft = 0;

tnode *newnode(int data)
{
    tnode *newnode = (tnode *)malloc(sizeof(tnode));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int height(tnode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
void printCurrentLevel(tnode *root, int level, int data)
{
    if (root == NULL)
        return;
    if (level == 1)
        return;
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1, data);
        if (root->left == NULL)
        {
            root->left = newnode(data);
        }
        else if (root->right == NULL)
        {
            root->right = newnode(data);
        }
        printCurrentLevel(root->right, level - 1, data);
        if (root->left == NULL)
        {
            root->left = newnode(data);
        }
        else if (root->right == NULL)
        {
            root->right = newnode(data);
        }
    }
}

void printLevelOrder(struct node *root, int data)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i, data);
}



/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/

tnode *insert(tnode *key, int data)
{
    if (key == NULL)
        return newnode(data);
    else
    {
    }
    return key;
}

void insertorder(tnode *rootNode)
{
    if (rootNode == NULL)
        return;
    insertorder(rootNode->left);
    printf("%d ", rootNode->data);
    insertorder(rootNode->right);
}

void preorder(tnode *rootNode)
{
    if (rootNode == NULL)
        return;
    printf("%d ", rootNode->data);
    insertorder(rootNode->left);
    insertorder(rootNode->right);
}

void postorder(tnode *rootNode)
{
    if (rootNode == NULL)
        return;
    insertorder(rootNode->left);
    insertorder(rootNode->right);
    printf("%d ", rootNode->data);
}

int main()
{
    tnode *rootNode = NULL;
    printLevelOrder(rootNode, 7);
    printLevelOrder(rootNode, 4);
    printLevelOrder(rootNode, 8);
    printLevelOrder(rootNode, 1);
    printLevelOrder(rootNode, 5);
    printLevelOrder(rootNode, 2);
    printLevelOrder(rootNode, 9);
    printLevelOrder(rootNode, 3);
    insertorder(rootNode);
    printf("\n");
    preorder(rootNode);
    printf("\n");
    postorder(rootNode);
    printf("\n");
    printf("\n%d %d\n", cright, cleft);
    return 0;
}