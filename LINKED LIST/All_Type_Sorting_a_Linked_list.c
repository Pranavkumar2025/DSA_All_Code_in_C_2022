#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start , int data);
struct node *addatbeg(struct node*start,int data);
struct node *addatend(struct node *start , int data);
void selection_sort(struct node *start);
void bubble_sort(struct node *start);

int main()
{
    struct node *start;
    int choice,data,item,pos;
    while(1)
    {
    printf("\n1.Create List\n");
    printf("2.Display\n");
    printf("3.count\n");
    printf("4.Search\n");
    printf("5.Selection Sorting of Linked list\n");
    printf("6.Bubble Sorting of Linked list\n");
    printf("0.Exit\n");


    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            count(start);
            break;
        case 4:
            printf("Enter the element to be searched: ");
            scanf("%d", &data);
            search(start,data);
            break;
        case 5:
            selection_sort(start);
            break;
        case 6:
            bubble_sort(start);
            break;
        case 0:
            exit(1);
        default:
            printf("wrong choice\n");
    }
    }
}
struct node *addatbeg(struct node *start,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->next=start;
    start=tmp;
    return start;
}
struct node *addatend(struct node *start,int data)
{
    struct node *p,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    p=start;
    while(p->next!=NULL)
        p=p->next;
    p->next=tmp;
    tmp->next=NULL;
    return start;
}
struct node *create_list(struct node *start)
{
    int i,n, data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    start=NULL;
    if(n==0)
    {
        return start;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d",&data);
    start=addatbeg(start,data);
    for(i=2;i<=n;i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d",&data);
        start=addatend(start,data);
    }
    return start;
}
void display(struct node *start)
{
    struct node *p;
    if(start == NULL)
    {
        printf("List is Empty\n");
        return ;
    }
    p=start ;
    printf("List is : \n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void count(struct node *start)
{
    struct node *p;
    int cnt=0;
    p=start;
    while(p!=NULL)
    {
        p=p->next;
        cnt++;
    }
    printf("Number of elements are %d\n",cnt);
}
void search(struct node *start,int item)
{
    struct node *p=start;
    int pos=1;
    while (p!=NULL)
    {
        if(p->data == item)
        {
            printf("Item %d found at position %d\n",item,pos);
            return ;
        }
        p=p->next;
        pos++;
    }
}
void selection_sort(struct node *start)
{
    struct node *p,*q;
    int tmp;
    p = start;

    for(p = start; p->next != NULL; p=p->next)
    {
        for(q=p->next; q != NULL; q= q->next)
        {
            if(p->data > q->data)
            {
                tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
}
void bubble_sort(struct node *start)
{
    struct node *end,*p,*q;
    int tmp;
    for(end = NULL; end != start->next; end=q)
    {
        for(p=start; p->next != end; p=p->next)
        {
            q=q->next;
            if(p->data > q->data)
            {
                tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
}