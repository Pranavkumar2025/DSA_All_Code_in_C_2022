#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *addatEmpty(struct node *last, int data);
struct node *addatEnd(struct node *last ,int data);
struct node *createlist(struct node *last);
struct node *displaythelist(struct node *last);
struct node *addatBegn(struct node *last,int data);
struct node *addatNode(struct node *last, int data,int index);
struct node *deletionofNode(struct node *last,int index);
void search(struct node *last,int data);
void count(struct node *last);


int main()
{
    struct node *last=NULL;
    int data,choose,index,elements;
    while(1)
    {
    printf("\n1.Creat the list.\n");
    printf("2.Insert at empty list. \n");
    printf("3.Insert at end of the list \n");
    printf("4.Display the list\n");
    printf("5.Insert at beginning of the list\n");
    printf("6.Insert at any node of the list \n");
    printf("7.Search the element of the lsit \n");
    printf("8.Deletion of the data of the list \n");

    printf("Choose the above option: ");
    scanf("%d", &choose);
    switch(choose)
    {
        case 1:
            last=createlist(last);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d",&data);
            last=addatEmpty(last,data);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d",&data);
            last=addatEnd(last,data);
            break;
        case 4:
            displaythelist(last);
            break;
        case 5:
            printf("Enter the data: ");
            scanf("%d",&data);
            last=addatBegn(last,data);
            break;
        case 6:
            printf("Enter the index of the data: ");
            scanf("%d",&index);
            printf("enter the data: ");
            scanf("%d",&data);
            last=addatNode(last,data,index);
            break;
        case 7:
            printf("Enter the data to be searched: ");
            scanf("%d",&data);
            search(last,data);
            break;
        case 8:
            printf("enter the data index :");
            scanf("%d",&index);
            last=deletionofNode(last,index);
            break;

        default:
            printf("INVALID SELECTION");
            break;
            
    }
    }
}

struct node *addatEmpty(struct node *last, int data)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node ));
    ptr->data=data;
    last=ptr;
    last->next=last;
    return last;
}
struct node *addatEnd(struct node *last, int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    if(last == NULL)
    {
        printf("list is Empty");
        return last;
    }
    ptr->data=data;
    ptr->next=last->next;
    last->next=ptr;
    last=ptr;
    return last;
    
}
struct node *createlist(struct node *last)
{
    int n,i,data;
    printf("Enter the no of nodes in the list: ");
    scanf("%d",&n);
    printf("Enter the data: ");
    scanf("%d",&data);
    last=addatEmpty(last,data);
    for(i=2;i<=n;i++)
    {
        printf("Enter the data: ");
        scanf("%d",&data);
        last=addatEnd(last,data);
    }
    return last;
}
struct node *displaythelist(struct node *last)
{
    if(last==NULL)
    {
        printf("list is Empty");
        return last;
    }
    struct node *p=last->next;
    do
    {
        printf("%d ",p->data);
        p=p->next;

    }while(p !=last->next);
}
struct node *addatBegn(struct node *last, int data)
{
    if(last == NULL)
    {
        printf("List is Empty \n");
        return last;
    }
    struct node *ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data=data;
    ptr->next=last->next;
    last->next=ptr;
    return last;
}
struct node *addatNode(struct node *last,int data, int index)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    if(last==NULL)
    {
        printf("List is Empty \n");
    }
    if(last->next->data==index)
    {
        last=addatBegn(last,data);
        return last;
    }
    if(last->data==index)
    {
        last=addatEnd(last,data);
        return last;
    }
    struct node *p=last->next;
    p=p->next;
    while(p != last->next)
    {
        if(p->data==index)
        {
            ptr->data=data;
            ptr->next=p->next;
            p->next=ptr;
            return last;
        }
        p=p->next;
    }    
}
void search(struct node *last, int data)
{
    struct node *p=last->next;
    if(last->next->data==data)
    {
        printf("%d is found at 1 positon.\n", data);
    }
    p=p->next;
    for(int i=2;p != last->next; i++)
    {
        if(p->data==data)
        {
            printf("%d is found at %d positon.\n", data,i);
        }
        else
        {
            printf("%d is not found in the list\n",data);
        }
        p=p->next;
    }
}
struct node *deletionofNode(struct node *last,int index)
{
    struct node *p=last->next;
    if(last->next->data==index)
    {
        struct node *ptr=last->next;
        last->next=ptr->next;
        free(ptr);
        return last;
    }
    while(p ->next != last)
    {
        if(p->next->data==index)
        {
            struct node *ptr=p->next;
            p->next=ptr->next;
            free(ptr);
            return last;
        }
        p=p->next;

    }
    if(last->data==index)
    {
        struct node *ptr=last;
        p->next=last->next;
        last=p;
        free(ptr);
        return last;
    }
}