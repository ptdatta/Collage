#include <stdio.h>
#include <stdlib.h>

typedef struct N
{
    int val;
    struct N *right;
    struct N *left;
} Node;

Node *root = NULL;

Node *createNode(int val)
{
    Node *branch = (Node *)malloc(sizeof(Node));
    branch->val = val;
    branch->left = NULL;
    branch->right = NULL;
    return branch;
}

Node *insertNode(Node *root, int val)
{
    if (root == NULL)
    {
        Node *temp = createNode(val);
        return temp;
    }
    if (val > root->val)
    {
        root->right = insertNode(root->right, val);
    }
    else
    {
        root->left = insertNode(root->left, val);
    }
    return root;
}

void insert(int val)
{
    root = insertNode(root, val);
}

void display(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    display(root->left);
    printf("%d->", root->val);
    display(root->right);
}

// Total no of nodes
int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = countNodes(root->left);
    int r = countNodes(root->right);
    return l + r + 1;
}

// Sum of height of all Nodes
int totalHeight(Node *root, int h)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = totalHeight(root->left, h + 1);
    int r = totalHeight(root->right, h + 1);
    return l + r + h;
}

int main()
{
    // inserting elements to the Tree
    insert(20);
    insert(12);
    insert(30);
    insert(10);
    insert(35);
    insert(32);

    // Calculating average search length
    printf("Average Search Length= %.2f\n", (float)totalHeight(root, 1) / countNodes(root));
    return 0;
}