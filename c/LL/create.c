#include<stdio.h>
#include<stdlib.h>

typedef struct N{
    int data;
    struct N * next;
} Node;

void linkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1
Node * insertAtFirst( Node *head, int data){
     Node * ptr = (Node *) malloc(sizeof(Node));
    ptr->data = data;

    ptr->next = head;
    return ptr; 
}
// Case 1: Deleting the first element from the linked list
Node * deletefirst(Node * head){
    Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}


// Case 2
Node * insertAtIndex(Node *head, int data, int index){
    Node * ptr = (Node *) malloc(sizeof(Node));
    Node * p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
 Node * deleteAtIndex( Node * head, int index){
     Node *p = head;
     Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

// Case 3
 Node * insertAtEnd( Node *head, int data){
     Node * ptr = ( Node *) malloc(sizeof( Node));
    ptr->data = data;
     Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
 Node * deleteAtLast( Node * head){
     Node *p = head;
     Node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}

// Case 4
 Node * insertAfterNode( Node *head,  Node *prevNode, int data){
     Node * ptr = ( Node *) malloc(sizeof( Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    
    return head;
}



int main(){
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (Node *)malloc(sizeof( Node));
    // second = (struct Node *)malloc(sizeof( Node));
    // third = (struct Node *)malloc(sizeof( Node));
    // fourth = (struct Node *)malloc(sizeof( Node));

    // Link first and second nodes
    head->data = 7;
    // head->next = second;

    // // Link second and third nodes
    // second->data = 11;
    // second->next = third;

    // // Link third and fourth nodes
    // third->data = 41;
    // third->next = fourth;

    // // Terminate the list at the third node
    // fourth->data = 66;
    // fourth->next = NULL;
    insertAtEnd(head,11);
    insertAtEnd(head,41);
    insertAtEnd(head,66);



    printf("Linked list before insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 56);
    head = insertAtIndex(head, 67, 1);
    head = insertAtEnd(head, 78);
    head = insertAfterNode(head, third, 45);
    head=deletefirst(head);
    // head=head->next;
    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    
    return 0;
}