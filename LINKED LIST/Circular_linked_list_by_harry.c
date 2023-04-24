#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void userinput(struct node*head)
{
    struct node *ptr=head;
    while(ptr->next!=head)
    {
        scanf("%d", &ptr->data);
        ptr=ptr->next;
    }
    scanf("%d",&ptr->data);
}
void traverseofnode(struct node *head)
{
    struct node *ptr=head;
    while(ptr->next!=head)
    {
        printf("%d\n", ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);

}
struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr=(struct node *)malloc (sizeof(struct node));
    ptr->data=data;
    struct node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}
struct node *insertatend(struct node *head,int data)
{
    struct node*ptr=(struct node *)malloc (sizeof(struct node));
    ptr->data=data;
    struct node*p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return head;

}
struct node *insertatindex(struct node*head, int data,int index)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    for(int i=0;i<=index-1;i++)
    {
        p=p->next;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
  

    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));

    head->data;
    head->next=second;

    second->data;
    second->next=third;

    third->data;
    third->next=fourth;

    fourth->data;
    fourth->next=head;
    
    printf("enter the element of node : \n");
    userinput(head);
    printf("element of node\n");
    traverseofnode(head);
    int a;
    printf("\nenter the number which you want to insert: ");
    scanf("%d", &a);
    printf("element after insertion \n");
    //head=insertatfirst(head,a);
    //head=insertatend(head,a);
    head=insertatindex(head,a,2);
    traverseofnode(head);
 
}