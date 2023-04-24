#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(struct node *start);
struct node *insert_s(struct node *start,int data);
struct node *insert(struct node *start,int data);
void display(struct node *start);
void merge(struct node *p1,struct node *p2);
int main()
{
    struct node *start1 = NULL,*start2 = NULL;
    start1 = create(start1);
    start2 = create(start2);
    printf("List1 : "); display(start1);
    printf("\nList2 : "); display(start2);
    merge(start1,start2);
}
void merge(struct node *p1,struct node *p2)
{
    struct node *start3;
    start3 = NULL;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data < p2->data)
        {
            start3 = insert(start3,p1->data);
            p1 = p1->next;
        }
        else if(p2->data < p1 ->data)
        {
            start3 = insert(start3,p2->data);
            p2 = p2->next;   
        }
        else if(p1->data == p2->data)
        {
            start3 = insert(start3,p1->data);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while( p1 != NULL)
    {
        start3 = insert(start3,p1->data);
        p1 = p1->next;
    }
    while( p2 != NULL)
    {
        start3 = insert(start3,p2->data);
        p2 = p2->next;
    }
    printf("\nMerged list is : ");
    display(start3);
}
struct node *create(struct node *start)
{
    int i,n,data;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    start=NULL;
    for(i=1;i<=n;i++)
    {
        printf("Enter the element of inserted : ");
        scanf("%d",&data);
        start = insert_s(start,data);
    }
    return start;
}
struct node *insert_s(struct node *start,int data)
{
    struct node *p,*tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    if(start == NULL || data<start->data)
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
            p=p->next;
        }
        tmp->next = p->next;
        p->next = tmp;
    }
    return start;
}
struct node *insert(struct node *start,int data)
{
    struct node *p,*tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->data=data;
    if(start == NULL)
    {
        tmp->next = start;
        start=tmp;
        return start;
    }
    else 
    {
        p = start;
        while(p->next != NULL)
        {
            p=p->next;
        }
        tmp->next = p->next;
        p->next = tmp;
    }
    return start;
}
void display(struct node *start)
{
    struct node *p;
    if(start == NULL)
    {
        printf("List is Empty \n");
        return;
    }
    p=start;
    while(p!=NULL)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
}
