#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
int top = -1;
char stack[MAX];
char pop();
void push(char);
int main()
{
    char str[20];
    unsigned int i;
    printf("Enter the String : ");
    gets(str);
    for(i=0; i<strlen(str); i++)
    {
        push(str[i]);
    }
    for(i=0; i<strlen(str); i++)
    {
        str[i] = pop();
    }
    printf("Reversed string is : ");
    puts(str);
}
void push(char item)
{
    if(top== (MAX-1))
    {
        printf("Stack Overflow \n");
        return ;
    }
    stack[++top] = item;
}
char pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}