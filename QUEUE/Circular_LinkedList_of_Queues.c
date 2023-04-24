#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *rear=NULL;
int del();
int peek();
void insert(int data);
int isEmpty();
int isFull();
void display();
int main()
{
	int data,choice;
	while(1)
	{
		printf("\n1.Insert the Element\n");
		printf("2.Delete \n");
		printf("3.Display all the element of the Queues\n");
		printf("4.Display the front element\n");
		printf("5.Quit\n");
		
		printf("Enter the choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the data: ");
				scanf("%d",&data);
				insert(data);
				break;
			case 2:
				data=del();
				printf("Deleted element is %d",data);
				break;
			case 4:
				printf("Front element is : %d",peek());
			    break;
			case 3:
				display();
				break;
			case 5:
				exit(1);
			default:
				printf("Invalid Selection\n");		
		}
	}
}
void insert(int item)
{
	struct node *ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data=item;
	if(ptr==NULL)
	{
		printf("Memory not available\n");
		return ;
	}
    if(isEmpty())
    {
        rear=ptr;
        ptr->next=rear;
    }
    else
    {
        ptr->next=rear->next;
        rear->next=ptr;
        rear=ptr;
    }
}
int del()
{
	struct node *ptr;
	int item;
	if(isEmpty())
	{
		printf("Queue is Underflwo\n");
	}
	if(rear->next==rear)
    {
        ptr=rear;
        rear=NULL;
    }
    else
    {
        ptr=rear->next;
        rear->next=rear->next->next;
    }
    item=ptr->data;
    free(ptr);
    return item;
}
int peek()
{
	if(isEmpty())
	{
		printf("Queue is Underflow\n");
	}
	return rear->next->data;
}
int isEmpty()
{
	if(rear == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void display()
{
	struct node *ptr=rear->next;
	if(isEmpty())
	{
		printf("Queue is Empty\n");
	}
	printf("Queue element is: \n\n");
    printf("%d\n",ptr->data);
    ptr=ptr->next;
	while(ptr!= rear->next)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
	printf("\n\n");
}