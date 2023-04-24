#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node*creatlist(struct node *head);
struct node*addatEmpty(struct node *head,int data);
struct node*addatEnd(struct node *head,int data);
struct node*display(struct node *head);
struct node*count(struct node *head);
struct node*search(struct node *head,int data);
struct node*addatindex(struct node *head, int data,int index);
struct node*addatfirst(struct node *head, int data);
struct node*delete(struct node *head,int index);
struct node *insertafterNode(struct node *head, int elements,int data);
struct node *mychoice(struct node *head, int data);


int main()
{
    struct node *head;
    //struct node *prev=NULL;
    //struct node *next=NULL;
    int data,choose,index,elements;
    while(1)
    {
        printf("\n1.Create the doubly linked list\n");
        printf("2.Add at End of the list. \n");
        printf("3.Add when list is Empty.\n");
        printf("4.For display the doubly linked lists.\n");
        printf("5.Count \n");
        printf("6.Search the elements of the lists\n");
        printf("7.insert the data at specific Position .\n");
        printf("8.Add at first of the list\n");
        printf("9.Dlelete at any position\n");
        printf("10.Enter after the nodes \n");
        printf("112.taking previous data\n");
        printf("0.for Exit the list. \n");
    
        printf("\nEnter the choice :");
        scanf("%d", &choose);
        switch(choose)
        {
            case 1:
                head=creatlist(head);
                break;
            case 2:
                printf("Enter the data of the nodes: ");
                scanf("%d", &data);
                head=addatEnd(head,data);
                break;
            case 3:
                printf("Enter the data of the nodes: ");
                scanf("%d", &data);
                head=addatEmpty(head,data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                count(head);
                break;
            case 6:
                printf("Enter the data which is to be searched: ");
                scanf("%d",&data);
                search(head,data);
                break;
            case 7: 
                printf("Enter the data of the nodes: ");
                scanf("%d", &data);
                printf("Enter the position in which data is inserted : ");
                scanf("%d", &index);
                head=addatindex(head,data,index);
                break;
            case 8:
                printf("Enter the data : ");
                scanf("%d", &data);
                head=addatfirst(head,data);
                break;
            case 9:
                printf("Enter the position : ");
                scanf("%d",&index);
                head=delete(head,index);
                break;
            case 10:
                printf("Enter the data after which you want to insert : ");
                scanf("%d",&elements);
                printf("Enter the data : ");
                scanf("%d", &data);
                head=insertafterNode(head,elements,data);
                break;
            case 112:
                printf("ente the data: ");
                scanf("%d",&data);
                head=mychoice(head,data);
                break;
            case 0:
                exit(1);

            default:
               printf("Invalid Selection");

                
        }
    }
}
struct node *addatEmpty(struct node *head,int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->prev=NULL;
    ptr->data=data;
    ptr->next=NULL;
    head=ptr;
    return head;
}
struct node *addatEnd(struct node *head, int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data=data;
    ptr->prev=p;
    p->next=ptr;
    ptr->next=NULL;
    //head=p;
    return head;
}
struct node *creatlist(struct node *head)
{
    int data,n,i;
    printf("enter the number of nodes: ");
    scanf("%d", &n);
    head=NULL;
    printf("Enter the Elements: ");
    scanf("%d", &data);
    head=addatEmpty(head,data);
    
    for(i=2;i<=n;i++)
    {
        printf("Enter the Elements: ");
        scanf("%d", &data);
        head=addatEnd(head,data);
    }
    return head;
}
struct node* display(struct node *head)
{
    struct node *p=head;
    while(p!=NULL)
    {
        printf("%d   ", p->data);
        p=p->next;
    }
    
}
struct node *count(struct node *head)
{
    int count =0;
    struct node *p=head;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    printf("Total number of Nodes: %d",count);
}
struct node *search(struct node *head, int data)
{
    struct node *p=head;
    int pos=1;
    
    while(p!=NULL)
    {
        if(p->data==data)
        {
            printf("%d data is at %d postition ", data,pos);
        }
        pos++;
        p=p->next;
    }
}
struct node *addatindex(struct node*head,int data, int index)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    int i;
    for(i=0;i<index-1;i++)
    {
        p=p->next;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    ptr->prev=p;
    //head=ptr;
    return head;
}
struct node *addatfirst(struct node *head, int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("list is Empty \n");
        return head;
    }
    ptr->data=data;
    ptr->next=head;
    head->prev=ptr;
    ptr->prev=NULL;
    head=ptr;
    return head;
}
struct node*delete(struct node *head,int index)
{
    struct node *p=head;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
    return head;
}
struct node *insertafterNode(struct node *head, int elements,int data)
{
    struct node*ptr=(struct node *)malloc(sizeof(struct node ));
    if(head->data==elements)
    {
        ptr->data=data;
        ptr->next=head;
        head->prev=ptr;
        ptr->prev=NULL;
        head=ptr;
        return head;
    }
    struct node*p=head;
    while(p!=NULL)
    {
        if(p->data==elements)
        {
            ptr->data=data;
            ptr->next=p->next;
            p->next=ptr;
            ptr->prev=p;
            return head;
        }
        p=p->next;

    }
}
struct node*mychoice(struct node *head, int data)
{
    struct node*p=head;
    while(p!=NULL)
    {
    if(p->data==data)
    {
        printf("Data of previous elements is: %d",p->prev->data);
    }
    p=p->next;
    }
}