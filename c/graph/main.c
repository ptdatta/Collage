#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct N
{
    int data;
    struct N *next;
} Node;

Node *insert(Node *head, int val)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        return temp;
    }
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return head;
}

int degree(Node** list,int vertex){
    Node* head=list[vertex-1]->next;
    int c=0;
    while(head!=NULL){
        head=head->next;
        c++;
    }
    return c;
}

void degreeInOut(Node** list,int vertex,int n){
    int c=0;
    for(int i=0;i<n;i++){
       Node* temp=list[i]->next;
       while (temp!=NULL)
       {
        if(temp->data==vertex){
            c++;
        }
        temp=temp->next;
       }
    }
    printf("Number of in degree %d & out degree %d\n",c,degree(list,vertex));
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void adj(int** arr,int vertex,int n){
    int x=0;
    int* ans=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        if(arr[vertex-1][i]==1){
            ans[x]=i+1;
            x++;
        }
        if(arr[i][vertex-1]==1){
            ans[x]=i+1;
            x++;
        }
    }
    printf("The adjacent vertices are: ");
    int i=0;
    while(i<n-1){
        printf("%d,",ans[i]);
        i++;
    }
}

bool validPath(char* c,int ** arr){
    int x=c[0]-'0';
    for(int i=1;i<strlen(c);i++){
       if(c[i]-'0'>=0 && c[i]-'0'<=9){
        if(arr[x-1][c[i]-'1']!=1){
            return false;
            break;
        }else{
            x=c[i]-'0';
        }
       }
    }
    return true;
}

int pathLength(int s,int e,int ** arr){
    
}

int main()
{
    FILE *fpr;
    fpr = fopen("E:\\collage\\c\\graph\\graph.txt", "r");
    if (fpr == NULL)
    {
        printf("Not opened");
    }
    char c;
    int n;
    fscanf(fpr, "%c%d", &c, &n);
    int **arr;
    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            fscanf(fpr, "%d", &arr[i][j]);
        }
    }
    Node** listarr=(Node**)malloc(n*sizeof(Node*));
    for (int i = 0; i < n; i++)
    {
        Node *head = NULL;
        head = insert(head, i + 1);
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                head = insert(head, j + 1);
            }
        }
        listarr[i]=head;
    }
    for(int i=0;i<n;i++){
        display(listarr[i]);
    }
    printf("%d\n",degree(listarr,2));
    degreeInOut(listarr,3,n);
    adj(arr,1,n);
    printf("\n%d\n",validPath("1->3->4",arr));
    return 0;
}
