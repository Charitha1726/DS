#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head=NULL, *new=NULL;
int len;


void Begin(int a)
{
	new = (struct node*)malloc(sizeof(struct node));
	new->data = a;
	new->next=NULL;
	if(head==NULL)
	{
		head= new;
	}
	else
	{
		new->next=head;
		head = new;
	}
	
}	

void End(int a)
{
	struct node *temp=NULL;
	new = (struct node*)malloc(sizeof(struct node));
	new->data = a;
	new->next = NULL;
	temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next=new;
}
	
int length()
{
	struct node *temp;
	int count=0;
	
	temp = head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

void Middle(int a)
{
	struct node *p, *temp;
	int loc, i =1;
	len = length();
	if(len==0)
	{
		printf("The list is Empty \n");
	}
	else
	{
		printf("Entet the location to be Inserted ");
		scanf("%d", &loc);
		if(loc>len)
		{
			printf("Invalid Location \n");
		}
		else
		{
			temp = head;
			while(i<loc)
			{
				temp=temp->next;
				i++;
			}
			new = (struct node*)malloc(sizeof(struct node));
			new->data = a;
			new->next = temp->next;
			temp->next = new;
		}
	}
}

void Search(int key)
{
    struct node *temp = head;
    int pos = 1, found = 0;

    if (head == NULL)
    {
        printf("The list is empty. Cannot search.\n");
        return;
    }
	else
	{
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				printf("Element %d found at position %d\n", key, pos);
				found = 1;
				break;
			}
			temp = temp->next;
			pos++;
		}
	}
    if (!found)
    {
        printf("Element %d not found in the list.\n", key);
    }
}

void DBegin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("The list is empty\n");
		return;
	}
	temp = head;
	head = head->next;
	free(temp);
	
}
void DEnd()
{
	struct node *temp = head, *prev;
	if (head == NULL) 
	{
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    // If there is only one node in the list
    if (head->next == NULL) 
    {
        free(head);
        head = NULL;
        printf("Last node deleted, list is now empty.\n");
        return;
    }

    // Traverse to the second last node
    while (temp->next != NULL) 
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL; // Remove the last node
    free(temp); // Free memory
    printf("Last node deleted successfully.\n");
}

void Display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("The List is MT \n");
		
	}
	else
	{
		temp = head;
		while(temp!=NULL)
		{
			printf("%d-->", temp->data);
			temp=temp->next;
		}
		printf("\n\n");
		len = length();
		printf("The Total Elements == %d \n", len);
	}
}	
void DMid()
{
	struct node *temp, *nextnode;
	int loc, i=1;
	len = length();
	if(len==0)
	{
		printf("The Lisy is MT \n");
	}
	else
	{
		printf("Please Enter the Postion to delete \n");
		scanf("%d", &loc);
		if(loc>len)
		{
			printf("Invalid Location \n");
		}
		else
		{
			temp = head;
			while(i < loc - 1)
			{
				temp = temp->next;
				i++;
			}
			nextnode = temp->next;
			temp->next = nextnode->next;
			free(nextnode);
		}
	}
	
}
	
	
void main()
{
	int a;
	
	while(1)
	{
		int ch;
		printf("\n1.Insert Begining\n");
		printf("2. Insert Middle\n");
		printf("3. Insert End \n");
		printf("4. Display \n");
		printf("5. Search \n");
		printf("6. Delete Begining \n");
		printf("7. Delete End \n");
		printf("8. Delete Middle \n");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be inserted \n");
				scanf("%d", &a);
				Begin(a);
				break;
			case 2:
				printf("Enter the element to be inserted \n");
				scanf("%d", &a);
				Middle(a);
				break;
			case 3:
				printf("Enter the element to be inserted \n");
				scanf("%d", &a);
				End(a);
				break;
			case 4: Display();
					break;
					
			case 5:  // Search case
                printf("Enter the element to search: \n");
                scanf("%d", &a);
                Search(a);
                break;
            case 6: DBegin();
				 break;
			case 7: DEnd();
				break;
			case 8: DMid();
				break;
            default:
                printf("Enter the choice Correctly\n");
                break;
		}
		
		
	}
}

