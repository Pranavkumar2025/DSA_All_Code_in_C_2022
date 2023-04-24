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
struct node *addafter(struct node *start , int data, int item);
struct node *addbefore(struct node *start , int data, int item);
struct node *addatpos(struct node *start, int data , int pos);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);
struct node *delete_all_list(struct node *start);

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
    printf("5.Add to empty list/ Add at beginning\n");
    printf("6.Add at end\n");
    printf("7.Add after node\n");
    printf("8.Add before node\n");
    printf("9.Add at position\n");
    printf("10.Delete\n");
    printf("00.For Delete whole list\n");
    printf("11.Reverse\n");
    printf("12.Quit\n\n");

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
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            start=addatbeg(start,data);
            break;
        case 6:
            printf("Enter the element to be inserted: ");
            scanf("%d",&data);
            start=addatend(start,data);
            break;
        case 7: 
            printf("Enter the element to be inserted: ");
            scanf("%d",&data);
            printf("Enter the element after which to insert: ");
            scanf("%d", &item);
            start=addafter(start,data, item);
            break;
        case 8: 
            printf("Enter the element to be inserted: ");
            scanf("%d",&data);
            printf("Enter the element before which to insert: ");
            scanf("%d", &item);
            start=addbefore(start,data,item);
            break;
        case 9: 
            printf("Enter the element to be inserted: ");
            scanf("%d",&data);
            printf("Enter the position at which to insert:");
            scanf("%d", &pos);
            start=addatpos(start,data,pos);
            break;
        case 10:
            printf("Enter the element to be deleted: ");
            scanf("%d", &data);
            start=del(start,data);
            break;
        case 00:
            start=delete_all_list(start);
            if(start==NULL)
                printf("linked list is deleted Succesfully\n");   
            break;
        case 11:
            start=reverse(start);
            break;
        case 12:
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

struct node *addafter(struct node *start , int data, int item)
{
    struct node *tmp,*p;
    p=start;
    while(p!=NULL)
    {
        if(p->data ==item)
        {
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->data=data;
            tmp->next=p->next;
            p->next=tmp;
            return start;
        }
       p=p->next; 
    }
    printf("%d not present in the list\n", item);
    return start;  
}
struct node *addbefore(struct node *start,int data, int item)
{
    struct node*tmp, *p;
    if(start==NULL)
    {
        printf("List is Empty\n");
        return start;
    }
    if(item == start->data)
    {
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->data=data;
        tmp->next=p->next;
        p->next=tmp;
        return start;
    }
    p = start;
    while(p->next != NULL)
    {
        if(p->next->data == item)
        {
            tmp = (struct node*)malloc(sizeof(struct node));
            tmp->data=data;
            tmp->next=p->next;
            p->next=tmp;
            return start;
        }
        p=p->next;
    }
    printf("%d not present in the list \n",item);
    return start;
}
struct node *addatpos(struct node *start, int data,int pos)
{
    struct node *tmp,*p;
    int i;
    tmp =(struct node *)malloc(sizeof(struct node));
    tmp->data=data;
    if(pos==1)
    {
        tmp->next=start;
        start=tmp;
        return start;
    }
    p=start;
    for(i=1;i<pos-1 && p!=NULL;i++)
    {
        p=p->next;
    }
    if(p==NULL)
        printf("There are less than %d elements\n",pos);
    else
    {
        tmp->next=p->next;
        p->next=tmp;
    }
    return start;
}

struct node *del(struct node *start,int data)
{
    struct node *tmp,*p;
    if(start == NULL)
    {
        printf("List is Empty\n");
        return start;
    }
    if(start->data == data)
    {
        tmp=start;
        start = start->next;
        free(tmp);
        return start;
    }
    p=start;
    while(p->next!=NULL)
    {
        if(p->next->data ==data)
        {
            tmp=p->next;
            p->next =tmp->next;
            free(tmp);
            return start;
        }
        p=p->next;
    }
}
struct node*reverse(struct node *start)
{
    struct node *prev,*ptr,*after;
    prev=NULL;
    ptr = start;
    while(ptr!=NULL)
    {
        after=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=after;
    }
    start=prev;
    return start;
}
struct node *delete_all_list(struct node *start)
{
    struct node *ptr=start;
    while(ptr != NULL)
    {
        ptr=ptr->next;
        free(start);
        start=ptr;
    }
    return start;
}