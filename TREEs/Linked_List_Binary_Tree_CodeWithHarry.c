#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *creatnode(int data)
{
	struct node *ptr=(struct node *)malloc(sizeof(struct node ));
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;
}
struct node *preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
	printf("%d  ",ptr->data);
	preorder(ptr->left);
	preorder(ptr->right);
	}
}
struct node *inorder(struct node *ptr)
{
	if(ptr !=NULL)
	{
	inorder(ptr->left);
	printf("%d  ",ptr->data);
	inorder(ptr->right);
	}
}
struct node *postorder(struct node *ptr)
{
	if(ptr !=NULL)
	{
	postorder(ptr->left);
	postorder(ptr->right);
	printf("%d  ",ptr->data);
	}
}
int main()
{
	struct node *p=creatnode(50);
	struct node *p1=creatnode(40);
	struct node *p2=creatnode(60);
	struct node *p3=creatnode(30);
	struct node *p4=creatnode(70);
	struct node *p5=creatnode(25);
	struct node *p6=creatnode(35);
	struct node *p7=creatnode(65);
	struct node *p8=creatnode(80);
	struct node *p9=creatnode(20);
	struct node *p10=creatnode(33);
	struct node *p11=creatnode(36);

	p->left=p1;
	p->right=p2;
	p1->left=p3;
	p3->left=p5;
	p3->right=p6;
	p5->left=p9;
	p6->left=p10;
	p6->right=p11;
	p2->right=p4;
	p4->left=p7;
	p4->right=p8;

	printf("\nPre Order of the Tree is :  ");
	preorder(p);
	printf("\nPost order of the Tree is :  ");
	postorder(p);
	printf("\nInorder of the Tree is :  ");
	inorder(p);
	


}