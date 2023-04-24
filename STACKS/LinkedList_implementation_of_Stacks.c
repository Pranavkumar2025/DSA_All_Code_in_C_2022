#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;
void push(int item);
int pop();
int peek();
int isEmpty();
void display();

int main()
{
    int choice,item;
    while(1)
    {
        printf("1.Push\n");
        printf("2.pop\n");
        printf("3.Display item at the top \n");
        printf("4.Display all the elements of the stacks\n");
        printf("5.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                printf("enter the item to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2: 
                item=pop();
                printf("Popped item is : %d\n",item );
                break;
            case 3: 
                printf("Item at the top is %d\n",peek());
                break;
            case 4: 
                display();
                break;
            case 5: 
                exit(1);
            default: 
                printf("Wrong Choice\n");
        }
    }
}
void push(int item)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    if(tmp==NULL)
    {
        printf("Stack Overflow\n");
        return ;
    }
    tmp->data=item;
    tmp->next=top;
    top=tmp;
}
int pop()
{
    struct node *tmp;
    int item;
    if(isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    tmp=top;
    item=tmp->data;
    top=top->next;
    free(tmp);
    return item;
}
int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return top->data;
}
int isEmpty()
{
    if(top==NULL)
        return 1;
    else  
        return 0;
}
void display()
{
    struct node *ptr;
    ptr = top;
    if(isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements : \n");
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
