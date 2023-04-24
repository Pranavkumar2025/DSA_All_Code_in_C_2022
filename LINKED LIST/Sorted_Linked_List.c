#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node *insert_s(struct node *start,int data);
void search(struct node *start,int data);
void display(struct node *start);
void selection_sort(struct node *start);

int main()
{
    int choice,data;
    struct node *start=NULL;
    while(1)
    {
        printf("\n1.Insert\n");
        printf("2.Display\n");
        printf("3.Search\n");
        printf("4.Exit\n");

        printf("Enter your Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                start = insert_s(start,data);
                break;
            case 2:
                display(start);
                break;
            case 3:
                printf("Enter the element to be searched : ");
                scanf("%d",&data);
                search(start,data);
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong Choice \n");
        }
    }
}
struct node *insert_s(struct node *start,int data)
{
    struct node *p,*tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->data=data;
    
    if(start == NULL || data < start->data)
    {
        tmp->next = start;
        start = tmp;
        return start;
    }
    else
    {
        p=start;
        while(p->next != NULL && p->next->data < data)
        {
            p-p->next;
        }
        tmp->next = p->next;
        p->next = tmp;
    }
    return start;
}
void search(struct node *head,int data)
{
	if(head->data == data)
	{
		printf("%d is found at 1st Position",data);
	}
	else
	{
		struct node *p=head;
		int count =1;
		while(p->next != NULL && p->data <=data)
		{
			p=p->next;
			count ++;
		}
		printf("%d found at %d position",data,count);
	}
}
void display(struct node *start)
{
    struct node *q;
    if(start == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    q = start;
    printf("List is : \n");
    while(q != NULL)
    {
        printf("%d  ",q->data);
        q=q->next;
    }
    printf("\n");
}

