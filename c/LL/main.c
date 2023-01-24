#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Queue;

Queue *insertatfirst(Queue *head, int val)  //Insert at first position
{
    Queue *temp;
    temp = (Queue *)malloc(sizeof(Queue));
    temp->data = val;
    if (head == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = head;
    }
    head = temp;
    return head;
}

Queue *insertatlast(Queue *head, int val)  //Insert at last position
{
    Queue *temp;
    temp = (Queue *)malloc(sizeof(Queue));
    temp->data = val;
    temp->next = NULL;
    Queue *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return head;
}

Queue *insertatpos(Queue *head, int val, int pos) //Insert at given position
{
    if (pos == 0)
    {
        head = insertatfirst(head, val);
        return head;
    }
    Queue *temp;
    temp = (Queue *)malloc(sizeof(Queue));
    temp->data = val;
    temp->next = NULL;
    int i = pos - 1;
    Queue *p = head;
    while (i > 0)
    {
        p = p->next;
        i--;
    }
    Queue *new = p->next;
    p->next = temp;
    temp->next = new;
    return head;
}

int search(Queue *head, int val)  //Find he index of a node
{
    Queue *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return i;
        }
        i++;
        temp = temp->next;
    }
    return -1;
}

Queue *deleteatfirst(Queue *head)   //Delete the first node
{
    head = head->next;
    return head;
}

Queue *deleteatlast(Queue *head)    //Delete the last node
{
    Queue *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

Queue *deleteatpos(Queue *head, int pos)    //Delete the node of the given position
{
    if (pos == 0)
    {
        head = deleteatfirst(head);
        return head;
    }
    Queue *temp = head;
    int i = pos - 1;
    while (i > 0)
    {
        temp = temp->next;
        i--;
    }
    temp->next = temp->next->next;
    return head;
}

void display(Queue *head)          //Display the entire list
{
    Queue *temp = head;
    while (temp != NULL)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Queue *head = NULL;
    printf("Type 1 to insert at first\nType 2 to insert at last \nType 3 to insert at any pos \nType 4 to search \nType 5 to print the list \nType 6 to delete the first element \nType 7 to delete at last position\nType 8 to delete at a given position\nTYpe 0 to terminate\n");
    int x, pos, val;
    do
    {
        scanf("%d", &x);
        switch (x)
        {
        case 0:
            break;
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            head = insertatfirst(head, val);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            head = insertatlast(head, val);
            break;
        case 3:
            printf("Enter value & position: ");
            scanf("%d %d", &val, &pos);
            head = insertatpos(head, val, pos);
            break;
        case 4:
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Index at: %d\n", search(head, val));
            break;
        case 5:
            display(head);
            break;
        case 6:
            head = deleteatfirst(head);
            break;
        case 7:
            head = deleteatlast(head);
            break;
        case 8:
            printf("Enter position: ");
            scanf("%d", &pos);
            head = deleteatpos(head, pos);
            break;
        }
    }while (x!=0);
    printf("Terminated");
    return 0;
}
