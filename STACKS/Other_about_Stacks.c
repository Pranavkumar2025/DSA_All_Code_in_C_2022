#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_arr[MAX];
int top =-1;
void push(int data);
int pop();
int peek();
int isEmpty();
int isFull();
void display();
int main()
{
    int choice,data,value;
    while(1)
    {
        printf("\n1. PUSH \n");
        printf("2. POP \n");
        printf("3. Display the top elements \n");
        printf("4. Display all the Elements \n");
        printf("5 .Quit \n");

        printf("Enter the Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                value=pop();
                printf("Popping Element is %d \n",value);
                break;
            case 3:
                value=peek();
                printf("Top most Elements is %d \n",value);
                break;
            case 4:
                printf("Stack elements is : \n");
                display();
                break;
            case 5:
                exit(1);

            default:
                printf("Invalid Selection \n");
        }
    }
}
int isFull()
{
    if(top==MAX-1)
    {
        return 1;
    }
    else 
        return 0;
}
int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
void push(int data)
{
    if(isFull())
    {
        printf("Stack is Ov erflow\n");
    }
    else
    {
        int i;
        top = top + i;
        for(i=top;i>0; i--)
        {
            stack_arr[i] = stack_arr[i-1];
        }
        stack_arr[0] = data;
    }
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack is Underflow\n");
    }
    else
    {
        int b=stack_arr[top];
        top=top-1;
        return b;
    }
}
void display()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n ");
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d\n",stack_arr[i]);
        }
        
    }
}
int peek()
{
    if(isEmpty())
    {
        printf("Stack is Underflow\n");
    }
    else
    {
        int b=stack_arr[top];
        return b;
    }
}