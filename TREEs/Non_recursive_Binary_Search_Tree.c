#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct node 
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
struct node *stack[MAX];
int top=-1;
void push_stack(struct node *item)
{
    if( top == (MAX -1))
    {
        printf("Stack Overflow \n");
        return;
    }
    top = top+1;
    stack[top]=item;
}
struct node *pop_stack()
{
    struct node *item;
    if(top == -1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    item= stack[top];
    top = top -1;
    return item;
}
int stack_empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
void nrec_pre(struct node *root)
{
	struct node *ptr=root;
	push_stack(ptr);
	while(!stack_empty())
	{
		ptr=pop_stack();
		printf("%d  ",ptr->data);
		if(ptr->rchild != NULL)
		{
			push_stack(ptr->rchild);
		}
		if(ptr->lchild != NULL){
			push_stack(ptr->lchild);
		}
	}
}
void nrec_in(struct node *root)
{
    struct node *ptr=root;
    if(ptr == NULL)
    {
        printf("Tree is Empty\n");
    }
    while(1)
    {
        while(ptr->lchild != NULL)
        {
            push_stack(ptr);
            ptr = ptr->lchild;
        }
        while(ptr ->rchild == NULL)
        {
            printf("%d ",ptr->data);
            if(stack_empty())
                return ;
            ptr = pop_stack();
        }
        printf("%d ", ptr->data);
        ptr = ptr ->rchild;
    }
    printf("\n");
}
void nrec_post(struct node *root)
{
    struct node *q, *ptr = root;
    if(ptr == NULL)
    {
        printf("Tree is Empty\n");
        return;
    }
    q=root;
    while(1)
    {
        while(ptr ->lchild != NULL)
        {
            push_stack(ptr);
            ptr = ptr->lchild;
        }
        while(ptr ->rchild == NULL || ptr->rchild == q)
        {
            printf("%d  ",ptr->data);
            q = ptr;
            if(stack_empty())
            {
                return;
            }
            ptr = pop_stack();
        }
        push_stack(ptr);
        ptr = ptr->rchild;
    }
    printf("\n");
}
struct node *search_nrec(struct node *ptr,int skey)
{
    while(ptr != NULL)
    {
        if(skey< ptr->data)
            ptr = ptr->lchild;
        else if(skey > ptr->rchild)
            ptr = ptr->rchild;
        else
            return ptr;
    }
    return NULL;
}
struct node *min_nrec(struct node *ptr)
{
    if(ptr != NULL)
    {
        while(ptr->lchild == NULL)
        {
            ptr = ptr ->lchild;
        }
        return ptr;
    }
}
struct node *max_nrec(struct node *ptr)
{
    if(ptr != NULL)
    {
        while(ptr->rchild != NULL)
        {
            ptr = ptr->rchild;
        }
        return ptr;
    }
}
struct node *insert_nrec(struct node *root,int data)
{
    struct node *p,*tmp,*ptr;
    ptr = root;
    tmp = NULL;
    while(ptr != NULL)
    {
        tmp = ptr;
        if(data < ptr->data)
            ptr = ptr->lchild;
        else if(data > ptr->data)
            ptr = ptr->rchild;
        else
        {
            printf("Duplicate Key");
            return root;
        }
    }
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->lchild=NULL;
    p->rchild=NULL;

    if(tmp == NULL)
    {
        root = p;
    }
    else if(data < tmp->data)
    {
        tmp->lchild = p;
    }
    else
    {
        tmp->rchild = p;
    }
    return root;
}
struct node *case_a(struct node *root,struct node *p,struct node *ptr)
{
    if(p == NULL)
    {
        root = NULL;
    }
    else if(ptr == p->lchild)
    {
        p->lchild = NULL;
    }
    else
    {
        p->rchild = NULL;
    }
    free(ptr);
    return root;
}
struct node *case_b(struct node *root, struct node *p, struct node *ptr)
{
    struct node *child;
    if(ptr ->lchild != NULL)
        child = ptr->lchild;
    else
        child = ptr->rchild;
    if(p == NULL)
    {
        root == child;
    }
    else if(ptr == p ->lchild)
    {
        p->lchild = child;
    }
    else
    {
        p->rchild = child;
    }
    free(ptr);
}
struct node *case_c(struct node *root, struct node *p,struct node *ptr)
{
    struct node *succ, *parsucc;
    parsucc = ptr;
    succ = ptr->rchild;
    while(succ->lchild != NULL)
    {
        parsucc = succ;
        succ = succ->lchild;
    }
    ptr->data = succ->data;
    if(succ ->lchild == NULL && succ->rchild == NULL)
    {
        root = case_a(root,parsucc,succ);
    }
    else
    {
        root = case_b(root,parsucc,succ);
    }
    return root;
}
struct node *del_nrec(struct node *root,int dkey)
{
    struct node *p,*ptr;
    ptr=root;
    p= NULL;
    while(ptr != NULL)
    {
        if(dkey == ptr->data)
             break;
        p = ptr;
        if(dkey <ptr->data)
        {
            ptr = ptr->lchild;
        }
        else
            ptr = ptr->rchild;
    }
    if( ptr == NULL)
    {
        printf("Element is not present in the tree \n");
    }
    else if(ptr ->lchild != NULL  && ptr->rchild != NULL)
    {
        root = case_c(root,p,ptr);
    }
    else if(ptr ->lchild != NULL)
    {
        root = case_b(root,p,ptr);
    }
    else if(ptr ->rchild != NULL)
    {
        root = case_b(root,p,ptr);
    }
    else
    {
        root = case_a(root,p,ptr);
    }
    return root;
}
int main()
{
    struct node *root = NULL,*ptr;
    int choice,k;
    while(1)
    {
        printf("\n");
        printf("1.Search\n");
        printf("2.Insert\n");
        printf("3.Delete\n");
        printf("4.Preorder Traversal\n");
        printf("5.Inorder Traversal\n");
        printf("6.Postorder Traversal\n");
        printf("7.Height of tree\n");
        printf("8.Find Minimum and maximum\n");
        printf("9.Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the key to be searched: ");
                scanf("%d",&k);
                ptr=search_nrec(root,k);
                if(ptr==NULL)
                {
                    printf("Key not present \n");
                }
                else
                {
                    printf("Key present\n");
                }
                break;
            case 2:
                printf("Enter the key to be inserted: ");
                scanf("%d",&k);
                root = insert_nrec(root,k);
                break;
            case 3:
                printf("Enter the key to be deleted: ");
                scanf("%d",&k);
                root=del_nrec(root,k);
                break;
            case 4:
                nrec_pre(root);
                break;
            case 5:
                nrec_in(root);
                break;
            case 6:
                nrec_post(root);
                break;
            /*case 7:
                printf("Height of tree is %d\n",height(root));
                break;*/
            case 8:
                ptr = min_nrec(root);
                if(ptr !=NULL)
                {
                    printf("Minimum key is %d\n",ptr->data);
                }
                ptr = max_nrec(root);
                if(ptr != NULL)
                {
                    printf("Maximum key is %d\n",ptr->data);
                }
                break;
            case 9:
                exit(1);
            default:
                printf("Wrong Choice \n");
        }
    }
}












