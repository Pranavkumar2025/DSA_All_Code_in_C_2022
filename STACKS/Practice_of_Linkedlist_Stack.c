#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int push(int data);
int pop();
int peek();
int isEmpty();
int display();
struct node *top=NULL;
int main()
{
    int choose,data,item;
    while(1)
    {
        printf("\n1.PUSH \n");
        printf("2.POP \n");
        printf("3.Display the topmost elements \n");
        printf("4.Display the element of the stack \n");
        printf("5.for Exit the loop \n");

        printf("Choose the above Option: ");
        scanf("%d",&choose);
        
        switch(choose)
        {
            case 1:
                printf("Enter the Data: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                item=pop();
                printf("Popping data is %d \n",item);
                break;
            case 3:
                printf("Top element is %d", peek());
                break;
            case 4:
                printf("Stack elements is :  "); 
                display();
                break;
            case 5:
                exit(1);
            
            default:
                printf("Invalid Selection \n");

                
        }
    }

}
int isEmpty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int push(int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr ==NULL)
    {
        printf("Stack Overflow\n");
        return 0;
    }
    ptr->data=data;
    ptr->next=top;
    top=ptr;
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack is Underflow\n");
        return 0 ;
    }
    struct node *ptr;
    int item;
    ptr=top;
    item=ptr->data;
    top=top->next;
    free(ptr);
    return item;
    
}
int peek()
{
    if(isEmpty())
    {
        printf("Stack is underflow \n");
    }
    return top->data;
}
int display()
{
    if(isEmpty())
    {
        printf("Stack is Empty \n");
    }
    else
    {
        struct node *p=top;
        while(p != NULL)
        {
            printf("%d  ",p->data);
            p=p->next;
        }
    }
}