#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *front=NULL;
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
	if(ptr==NULL)
	{
		printf("Memory not available\n");
		return ;
	}
	ptr->data=item;
	ptr->next=NULL;
	if(front==NULL)
	{
		front = ptr;
	}
	else
	{
		rear->next=ptr;
	}
	rear=ptr;
}
int del()
{
	struct node *ptr=front;
	int item;
	if(isEmpty())
	{
		printf("Queue is Underflwo\n");
	}
	item=ptr->data;
	front =front->next;
	free(ptr);
	return item;
}
int peek()
{
	if(isEmpty())
	{
		printf("Queue is Underflow\n");
	}
	return front->data;
}
int isEmpty()
{
	if(front == NULL)
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
	struct node *ptr=front;
	if(isEmpty())
	{
		printf("Queue is Empty\n");
	}
	printf("Queue element is: \n\n");
	while(ptr!= NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
	printf("\n\n");
}