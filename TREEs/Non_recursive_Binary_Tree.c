#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *stack[MAX];
int top =-1;
void push_stack(int item)
{
    if(top ==(MAX-1))
    {
        printf("Stack Overflow\n");
    }
    top=top +1;
    stack[top]=item;

}
struct node *pop_stack()
{
    struct node *item;
    if(top ==-1)
    {
        printf("Stack Underlow...\n");
        exit(1);
    }
    item = stack[top];
    top = top-1;
    return item;
}
int stack_empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

struct node *createnode(int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
}
struct node *preorder(struct node *ptr)
{
    if(ptr != NULL)
    {
    printf("%d ",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
    }
}
struct node *inorder(struct node *ptr)
{
    if(ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d ",ptr->data);
        inorder(ptr->right);
    }
}

int main()
{
    struct node *p=createnode(67);
    struct node *p1=createnode(34);
    struct node *p2=createnode(80);
    struct node *p3=createnode(12);
    struct node *p4=createnode(45);
    struct node *p5=createnode(78);
    struct node *p6=createnode(95);
    struct node *p7=createnode(10);
    struct node *p8=createnode(38);
    struct node *p9=createnode(60);
    struct node *p10=createnode(86);

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p3->left=p7;
    p4->left=p8;
    p4->right=p9;
    p2->left=p5;
    p2->right=p6;
    p6->left=p10;
  
   printf("Tree is in Preorder: ");
   preorder(p);
   printf("\nTree is in Inorder: ");
   inorder(p);

}