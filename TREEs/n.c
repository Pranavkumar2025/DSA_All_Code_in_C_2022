// C program to delete a node from AVL Tree
#include<stdio.h>
#include<stdlib.h>

// An AVL tree node
struct node
{
	int data;
	struct node *left;
	struct node *right;
	int height;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(struct node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given data and
	NULL left and right pointers. */
struct node* newnode(int data)
{
	struct node* node = (struct node*)
						malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *y)
{
	struct node *x = y->left;
	struct node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
	struct node *y = x->right;
	struct node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, int data)
{
	/* 1. Perform the normal BST rotation */
	if (node == NULL)
		return(newnode(data));

	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	else // Equal datas not allowed
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && data < node->left->data)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && data > node->right->data)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return the
node with minimum data value found in that tree.
Note that the entire tree does not need to be
searched. */
struct node * minValuenode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

// Recursive function to delete a node with given data
// from subtree with given root. It returns root of
// the modified subtree.
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
	root->height = 1 + max(height(root->left),
						height(root->right));

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

// A utility function to print preorder traversal of
// the tree.
// The function also prints height of every node
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

/* Constructing tree given in the above figure */
	root = insert(root, 9);
	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 0);
	root = insert(root, 6);
	root = insert(root, 11);
	root = insert(root, -1);
	root = insert(root, 1);
	root = insert(root, 2);

	/* The constructed AVL Tree would be
			9
		/ \
		1 10
		/ \	 \
	0 5	 11
	/ / \
	-1 2 6
	*/

	printf("Preorder traversal of the constructed AVL "
		"tree is \n");
	preOrder(root);

	root = deletenode(root, 10);

	/* The AVL Tree after deletion of 10
			1
		/ \
		0 9
		/	 / \
	-1 5	 11
		/ \
		2 6
	*/

	printf("\nPreorder traversal after deletion of 10 \n");
	preOrder(root);

	return 0;
}
