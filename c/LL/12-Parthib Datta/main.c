#include <stdio.h>
#include <stdlib.h>

typedef struct N
{
    int coefficient;
    int exponent;
    struct N *next;
} Node;

Node *avail = NULL;  //Initializing the avail list

Node *delete (Node *head)   //Delete polynomial
{
    Node *temp;
    if (temp != NULL)
    {
        temp = head->next;
        head->next = avail;
        avail = temp;
        head = NULL;
    }
    return head;
}

Node *insert(Node *head, int co, int ex)   //Insert a node in the polynomial
{
    Node *temp;
    Node *newP = (Node *)malloc(sizeof(Node));
    newP->coefficient = co;
    newP->exponent = ex;
    newP->next = NULL;
    if (head == NULL)
    {
        head = newP;
        head->next = head;
    }
    else if (ex > head->exponent)
    {
        newP->exponent = head->exponent;
        newP->coefficient = head->coefficient;
        head->exponent = ex;
        head->coefficient = co;
        newP->next = head->next;
        head->next = newP;
    }
    else
    {
        if (head->exponent == ex)
        {
            head->coefficient = head->coefficient + co;
        }
        else
        {
            temp = head;
            while (temp->next != head && temp->next->exponent >= ex)
            {
                temp = temp->next;
            }
            if (temp->exponent == ex)
            {
                temp->coefficient = temp->coefficient + co;
            }
            else
            {
                newP->next = temp->next;
                temp->next = newP;
            }
        }
    }
    return head;
}

Node *create(Node *head)  // Creating a polynomial
{
    int n;
    int coeff;
    int expo;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the cofficient for term %d: ", i + 1);
        scanf("%d", &coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}

Node *add(Node *head, Node *shead) // Addition of two polynomial
{
    Node *temp1 = head;
    Node *temp2 = shead;
    Node *addition = NULL;
    if (head == NULL)
    {
        head = shead;
    }
    else
    {
        do
        {
            head = insert(head, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        } while (temp2 != shead);
    }
    shead=delete(shead);
    return head;
}

Node *multiply(Node *head, Node *shead)  //Multiplication of two polynomial
{
    Node *temp1 = head;
    Node *temp2 = shead;
    Node *multiplication = NULL;
    if (head == NULL)
        return shead;

    do
    {
        do
        {
            multiplication = insert(multiplication, temp1->coefficient * temp2->coefficient, temp1->exponent + temp2->exponent);
            temp2 = temp2->next;
        } while (temp2 != shead);
        temp1 = temp1->next;
    } while (temp1 != head);
    shead=delete(shead);
    head = multiplication;
    return head;
}

Node *deleteAll(Node *avail)  // Delete all lists with the avail list
{
    if (avail == NULL)
    {
        printf("Avail list is already empty\n");
    }
    else
    {
        Node *temp = avail;
        while (avail != NULL)
        {
            avail = avail->next;
        }
        free(temp);
    }
    return avail;
}

void display(Node *head)  // Display the polynomial
{
    if (head == NULL)
    {
        printf("No Polynomial\n");
    }
    else
    {
        Node *temp = head;
        do
        {
            printf("%dx^%d", temp->coefficient, temp->exponent);
            temp = temp->next;
            if (temp != head)
            {
                printf(" + ");
            }
        } while (temp != head);
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    Node *shead = NULL;
    int n;
    printf("Type 1 to create a polynomial\nType 2 to add another polynomial to the current polynomial \nType 3 to multiply another polynomial to the current polynomial \nType 4 to display a polynomial \nType 5 to delete a polynomial \nType 6 to delete all linked lists in the memory and exit\n\n");
    printf("Please give option between 1 to 6\n");
    do
    {
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            printf("Enter the second polynomial\n");
            shead = create(shead);
            head = add(head, shead);
            break;
        case 3:
            printf("Enter the second polynomial\n");
            shead = create(shead);
            head = multiply(head, shead);
            break;
        case 4:
            display(head);
            break;
        case 5:
            head = delete (head);
            printf("Polynomial Deleted\n");
            break;
        case 6:
            printf("Terminated\n");
            head = delete (head);
            avail = deleteAll(avail);
            break;
        }
    } while (n != 6);
    return 0;
}