// C program to insert a root in AVL tree
#include<stdio.h>
#include<stdlib.h>

// An AVL tree root
struct node
{
	int data;
	struct node *left;
	struct node *right;
	int height;
};

// A utility function to get the height of the tree
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
	    return 1 + h_right; 
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a new root with the given data and
	NULL left and right pointers. */
// struct node* newnode(int data)
// {
// 	struct node* root = (struct node*)malloc(sizeof(struct node));
// 	root->data = data;
// 	root->left = NULL;
// 	root->right = NULL;
// 	root->height = 1; // new root is initially added at leaf
// 	return(root);
// }

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *y)
{
	struct node *x;
	x = y->left;
	y->left= x->right;
	x->right = y;
	return x;
}
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *y)
{
	struct node *x;
	x = y->right;
	y->right = x->left;
	x->left = y;
	return x;
}

// Get Balance factor of root N
int getBalance(struct node *root)
{
	return height(root->left) - height(root->right);
}
// Recursive function to insert a data in the subtree rooted
// with root and returns the new root of the subtree.
struct node* insert(struct node* root, int ikey)
{
	if(root == NULL)
	{
		root= (struct node *)malloc(sizeof(struct node));
		root->data= ikey;
		root->left=NULL;
		root->right= NULL;
	}
	else if(ikey < root->data)
	{
		root->left=insert(root->left,ikey);
	}
	else if(ikey > root->data)
	{
		root->right= insert(root->right,ikey);
	}
	else
	{
		return root;
	}
	/* 2. Update height of this ancestor root */
	root->height = 1 + max(height(root->left),height(root->right));

	/* 3. Get the balance factor of this ancestor
		root to check whether this root became
		unbalanced */
	int balance = getBalance(root);

	if(balance > 1 && ikey < root->left->data)
	{
		return rightRotate(root);
	}
	if(balance < -1 && ikey > root->right->data)
	{
		return leftRotate(root);
	}
	if(balance > 1 && ikey >root->left->data)
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
struct node* deletenode(struct node* root, int data)
{
    struct node *tmp , *succ;
	// STEP 1: PERFORM STANDARD BST DELETE

	if (root == NULL)
		return root;

	// If the data to be deleted is smaller than the
	// root's data, then it lies in left subtree
	if ( data < root->data )
		root->left = deletenode(root->left, data);

	// If the data to be deleted is greater than the
	// root's data, then it lies in right subtree
	else if( data > root->data )
		root->right = deletenode(root->right, data);

	// if data is same as root's data, then This is
	// the node to be deleted
	else
	{
        if(root ->left != NULL && root->right != NULL)
        {
            succ = root->right;
            while(succ ->left)
                succ = succ->left;
            root->data= succ->data;
            root->right = deletenode(root->right, succ->data);
        }
        else
        {
            tmp = root;
            if(root->left != NULL)
            {
                root = root->left;
            }
            else if(root->right != NULL)
                root = root->right;
            else 
                root = NULL;
            free(tmp);
        }
	}
	// If the tree had only one node then return
	if (root == NULL)
	return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left),height(root->right));

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every root
void preOrder(struct node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
 
/* Driver program to test above function*/
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
	root = deletenode(root,33);
	printf("\nPreorder traversal after the deletion: ");
    preOrder(root);

}
