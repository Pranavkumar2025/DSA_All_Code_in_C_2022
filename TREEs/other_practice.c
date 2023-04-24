#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
};
int height(struct node *root)
{
	int h_left,h_right;
	if(root == NULL)
	{
		return 0;
	}
	h_left=height(root->left);
	h_right=height(root->right);
	if(h_left > h_right)
	{
		return 1 + h_left;
	}
	else
	{
		return 1 + h_right;
	}
}
struct node *rightRotate(struct node *y)
{
	struct node *x;
	x = y->left;
	y->left = x->right;
	x->right = y;
	return x;
}
struct node *leftRotate(struct node *y)
{
	struct node *x;
	x = y->right;
	y->right = x->left;
	x->left= y;
	return x;
}
int max(int a, int b)
{
	return (a>b)? a: b;
}
int getBalance(struct node *root) 
{
	return height(root->left)-height(root->right);
}
struct node *insert(struct node *root,int ikey)
{
	if(root == NULL)
	{
		root = (struct node*)malloc(sizeof(struct node));
		root->data=ikey;
		root->left= NULL;
		root->right= NULL;
	}
	else if(ikey < root->data)
	{
		root->left = insert(root->left,ikey);
	}
	else if(ikey > root->data)
	{
		root->right = insert(root->right,ikey);
	}
	else 
	{
		return root;
	}

	root->height = 1 + max(height(root->left),height(root->right));

	int balance = getBalance(root);
	if(balance > 1 && ikey < root->left->data)
	{
		return rightRotate(root);
	}
	if(balance < -1 && ikey > root->right->data)
	{
		return leftRotate(root);
	}
	if(balance > 1 && ikey > root->left->data)
	{
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance < -1 && ikey < root->right->data)
	{
		root->right=rightRotate(root->right); 
		return leftRotate(root);
	}
	return root;
}
struct node *del(struct node *root, int dkey)
{
	struct node *succ , *tmp;
	if(dkey < root->data)
	{
		root->left = del(root->left, dkey);
	}
	else if(dkey > root->data)
	{
		root->right = del(root->right , dkey);
	}
	else
	{
		if(root->left != NULL && root->right != NULL)
		{
			succ = root->right;
			while(succ->left)
			{
				succ= succ->left;
			}
			root->data = succ->data;
			root->right = del(root->right, succ->data);
		}
		else
		{
			tmp = root;
			if(root->left != NULL)
			{
				root= root->left;
			}
			else if(root->right != NULL)
			{
				root= root->right;
			}
			else 
			   root = NULL;
			free(tmp);
		}
	}
	return root;

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = getBalance(root);
	if(balance > 1 && getBalance(root->left) >= 0)
	{
		return rightRotate(root);
	}
	if(balance < -1 && getBalance(root->right) <= 0);
	{
		return leftRotate(root);
	}
	if(balance >1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;

}
void preOrder(struct node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
int main()
{
	struct node *root = NULL;
	
	root = insert(root,50);
	root = insert(root,40);
	root = insert(root,35);
	root = insert(root,58);
	root = insert(root,48);
	root = insert(root,42);
	root = insert(root,60);
	root = insert(root,30);
	root = insert(root,33);
	root = insert(root,25);
	
	printf("Preorder of the root is : ");
	preOrder(root);

	root = del(root,33);
	printf("\nPreorder traversal after the deletion: ");
    preOrder(root);

	// printf("\nInorder of the roo is : ");
	// inorder(root);
}