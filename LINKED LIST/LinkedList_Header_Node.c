#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create_list(struct node *head);
void display(struct node *head);
struct node *addatEnd(struct node *head,int data);
struct node *addBefore(struct node *head,int data,int item);
struct node *addatPos(struct node *head, int data,int pos);
struct node *del(struct node *head,int data);
struct node *reverse(struct node *head);
int main()
{
    int choice,data,item,pos;
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node ));
    head->data=45;
    head->next=NULL;
    head = create_list(head);
    while(1)
    {
        printf("\n1.Display\n");
        printf("2.Add at End\n");
        printf("3.Add Before node \n");
        printf("4.Add at Position\n");
        printf("5.Delete\n");
        printf("6.Reverse\n");
        printf("7.Quit\n\n");

        printf("Enter your Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
                display(head);
                break;
            case 2:
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                head=addatEnd(head,data);
                break;
            case 3:
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                printf("Enter the element before which to insert : ");
                scanf("%d",&item);
                head=addBefore(head,data,item);
                break;
            case 4:
                printf("Enter the Element to be inserted : ");
                scanf("%d",&data);
                printf("Enter the Position at which to insert : ");
                scanf("%d",&pos);
                head=addatPos(head,data,pos);
                break;
            case 5:
                printf("Enter the element to be deleted : ");
                scanf("%d",&data);
                head=del(head,data);
                break;
            case 6:
                head= reverse(head);
                break;
            case 7:
                exit(1);
            default: 
                printf("Wrong Choice\n\n");
        }
    }
}
struct node *create_list(struct node *head)
{
    int i,n,data;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        head= addatEnd(head,data);
    }
    return head;
}
void display(struct node *head)
{
    struct node *p;
    if(head->next == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    p= head->next;
    printf("List is : \n");
    while(p != NULL)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
}
struct node *addatEnd(struct node *head,int data)
{
    struct node *p,*tmp;
    tmp=(struct node *)malloc(sizeof (struct node ));
    tmp->data=data;
    p=head;
    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next=tmp;
    tmp->next=NULL;
    return head;
}
struct node *addBefore(struct node *head,int data, int item)
{
    struct node *tmp, *p;
    p=head;
    while(p->next!=NULL)
    {
        if(p->next->data == item)
        {
            tmp=(struct node *)malloc(sizeof(struct node ));
            tmp->data=data;
            tmp->next=p->next;
            p->next=tmp;
            return head;
        }
        p=p->next;
    }
    printf("%d not present in the list\n",item);
    return head;
}
struct node *addatPos(struct node *head,int data, int pos)
{
    struct node *tmp,*p;
    int i;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data=data;
    p= head;
    for (i=1;i<=pos-1;i++)
    {
        p = p->next;
        if(p== NULL)
        {
            printf("There are less than %d elements \n",pos);
            return head;
        }
    }
    tmp->next = p->next;
    p->next = tmp;
    return head;
}
struct node *del(struct node *head, int data)
{
    struct node *tmp, *p;
    p=head;
    while(p->next != NULL)
    {
        if(p->next->data == data)
        {
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
            return head;
        }
        p = p->next;
    }
    printf("Element %d not found \n",data);
    return head;
}
struct node *reverse(struct node *head)
{
    struct node *prev, *ptr,*next;
    prev = NULL;
    ptr = head->next;
    while(ptr != NULL)
    {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    head->next = prev;
    return head;
}