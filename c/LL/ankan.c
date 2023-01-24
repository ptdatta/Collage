#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int expo;
	float coefficient;
	struct node * next;
}Node;

Node* avail = NULL;
int linkedlistSize(Node* avail)
{
	Node* temp = avail;
	int length = 0;
	while ( temp != NULL)
	{
		temp = temp->next;
		length++;
	}
	temp = NULL;
	return length;
}
/* function to create a node */
Node* create(int expo,float coefficient)
{
	Node* create = (Node*)malloc(sizeof(Node));
	create->expo = expo;
	create->coefficient = coefficient;
	create->next = NULL;
	return create;
}
/* function to insert a node in a circular linked list in sorted way */
Node* circularinsert(Node* head,int expo,float coefficient)
{
	Node* temp = create(expo,coefficient);/* cretaing node */
	
	if ( head == NULL )/* if no circular linked list is there so temp will be new head */
	{
		head = temp;
		head->next = head ;
		return head;
	}
	else if ( head->expo < expo )/* inserting the node before head */
	{
	    /* copying the contents of head to temp */
		temp->expo = head->expo;
		temp->coefficient = head->coefficient;
		/* coping the contents of created node i.e temp to head  as a result a swaping occurs */
		head->expo = expo;
		head->coefficient = coefficient;
		/* after swaping temp contains the contents of previous head so it is joined to head->next and head is joined to tem*/
		temp->next = head->next;
		head->next = temp;
		return head;
	}
	else if ( head->next == head )
	{
	    /* if only one node is there */
	    if ( head->expo == expo) /* adding  when same exponent */
		{
			head->coefficient = head->coefficient + coefficient;			
		}
		else
		{
		    /* joining the node to last i.e when exponent < head->expo as for lesser and equal conditions are checked */
			temp->next = head->next;
			head->next = temp;			
		}
		return head;
	}
	else if ( head->next != head )
	{
	    if ( head->expo == expo )/* adding for same exponent */
	    {
    	    head->coefficient = head->coefficient + coefficient;
    	    
	    }
	    else
	    {
	        Node* ptr = head;/* traversing and checking upto last node */	
    		while (( ptr->next != head) && ( ptr->next->expo >= expo))
    		{
    			ptr = ptr->next;
    		}
    		if ( ptr->expo == expo )/* adding for ame exponent */
    		{
    			ptr->coefficient = ptr->coefficient + coefficient;
    		}
    		else
    		{
    		    /* joining before the exponent where which is less than that of temp */
    			temp->next = ptr->next;
    			ptr->next = temp;
     		}
	    }
		
		return head;							
	}
}
Node* erasePolynomial(Node* head)
{
	Node* temp;
	if ( head != NULL)
	{
		temp = head->next;
		head->next = avail;
		avail = temp;
		head = NULL;
	}
	return head;
}
Node* create_polynomial(Node* head)
{
	head = erasePolynomial(head);
	int term,expo;
	float coefficient;
		
	printf("\nEnter the number of terms\n");
	scanf("%d",&term);
	
	for ( int i = 0 ; i < term ; i++ )	
	{
		printf("Enter distinct exponent of the variable x of the (i+1)th term\n");
		scanf("%d",&expo);
		printf("Enter the coefficient of this term\n");
		scanf("%f",&coefficient);
		head = circularinsert(head,expo,coefficient);
				
	}
	return head;	
}


void display_polynomial(Node* head)
{
	if ( head == NULL)
	{
		printf("\n There is no polynomial present\n");
	}
	else
	{
		printf("P(x) = ");
		Node* ptr = head;
		do{
		    
			if ( ptr->expo == 0) 
			{
				printf("%0.2f",ptr->coefficient);
				
			}
			else if ( ptr->coefficient != 0 )
			{
				printf("%0.2fx^%d",ptr->coefficient,ptr->expo);
			}			
			ptr = ptr->next;
			if (( ptr != head ) &&( ptr->coefficient != 0))
			{
				printf("  +  ");
			}
		
	    }while ( ptr != head );
	}
}

Node* delete_linearnode(Node* avail)
{

	if ( avail == NULL )
	{
		return avail;
	}
	else
	{
		 
		Node* ptr = avail;
		avail = avail->next;
		
		free(ptr);
	}
	return avail;
}
Node* delete_avail_list(Node* avail)
{
	int length = linkedlistSize(avail);
	if ( length == 0 )
	{
		printf("\n Avail list is already empty\n");
	}
	for( int i = 0 ; i < length ; i++)
	{
		avail = delete_linearnode(avail);
	}
	return avail;	
}
Node* polynomial_addition(Node* head,Node* variablehead)
{
	Node* headAdd = NULL;
	Node* temp1 = head;
	Node* temp2 = variablehead;
	if ( head == NULL )
	{
		head = variablehead;
		return head;
	}
	else
	{
	    do
	    {
	        head = circularinsert(head,temp2->expo,temp2->coefficient);
	        temp2 = temp2->next;
	    }while ( temp2 != variablehead );
	    headAdd = head;
	    head = NULL;
	
	}
	
	head = erasePolynomial(head);
	variablehead = erasePolynomial(variablehead);
	head = headAdd;
	return head;	
}
Node* polynomial_multiplication( Node* head,Node* variablehead)	
{
	Node* multiplyAdd = NULL;
	Node* temp1 = head;
	Node* temp2 = variablehead;
	int expo;
	float coefficient;
	
	if ( head == NULL )
	{
		printf("\nThere is no current polynomial so resultant polynomial is P(x) = 0\n");
		return head;
	}
	else
	{
		
		do
		{
			do
			{
				expo = temp1->expo + temp2->expo;
				coefficient = temp1->coefficient * temp2->coefficient;
				multiplyAdd = circularinsert(multiplyAdd,expo,coefficient);
				temp2 = temp2->next;
			}while ( temp2 != variablehead );
			temp1 = temp1->next;
		}while ( temp1 != head );
	}
	head = erasePolynomial(head);
	variablehead = erasePolynomial(variablehead);
	head = multiplyAdd;
	return head;
}

int main()
{
	int option;
	Node* head = NULL;
	Node* variablehead = NULL;
	
	do
	{
		/* the options are given */
		printf("\n\n*****Menu of options******\n\n");
		printf("1:Create a polynomial\n");
		printf("2:Add another polynomial to the current polynomial\n");
		printf("3:Multiply another polynomial to the current polynomial\n");
		printf("4:Display a polynomial\n");
		printf("5:Delete a polynomial\n");
		printf("6:Delete all linked lists in the memory and exit\n");
		
		printf("\n***Enter option***\n");
		scanf("%d",&option);
		 
		switch(option)/* the cases are designed according to the opertions listed above */
		{
		  case 1:
		  printf("Enter the details of the polynomial to be created\n");
		  head = create_polynomial(head);
		  break;
		  		  
		  case 2:
		  printf("Enter the details of the polynomial to be added to the current polynomial\n");
		  variablehead = create_polynomial(variablehead);
		  head = polynomial_addition(head,variablehead);
		  break;
		  
		  case 3:
		  printf("Enter the details of the polynomial to be multiplied to the current polynomial\n");
		  variablehead = create_polynomial(variablehead);
		  head = polynomial_multiplication(head,variablehead);
		  break;
		  
		  case 4:
		  printf("\nThe current polynomial is ");
		  display_polynomial(head);  
		  break;
		  
		  case 5:
		  head = erasePolynomial(head);
		  break;
		  		  
		  case 6:
		  head = erasePolynomial(head);
		  avail = delete_avail_list(avail);
		  break;
		  
		  default:		  
		  printf("Please give option withen (1-6)\n");
		}
	}while ( option != 6 );
	return 0;
}