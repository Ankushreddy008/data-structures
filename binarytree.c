#include<stdio.h>
#include<stdlib.h>


struct node
{
	int value;
	struct node* left;
	struct node* right;
};

struct node* insert(struct node* root, int data)
{
	struct node* temp = NULL;
	struct node* anotemp = NULL;
	temp = (struct node*) malloc(sizeof(struct node));
	anotemp = root;

		if(root == NULL)
		{
			root = temp;
			root->value = data;
			root->left = NULL;
			root->right = NULL;
		}

		else
		{
			while(anotemp->left != NULL || anotemp->right != NULL)
			{
				if(anotemp->value > data)
				{
					anotemp = anotemp->left;

				}

				else if(anotemp->value < data)
				{
					anotemp = anotemp->right;
				}
			}

			if(anotemp->value > data)
			{
				anotemp->left = temp;
				temp->value = data;
				temp->left = NULL;
				temp->right = NULL;
			}
			else if(anotemp->value < data)
			{
				anotemp->right = temp;
				temp->value = data;
				temp->right = NULL;
				temp->left = NULL;
			}
		}

		return root;
}


void delete(struct node* root, int data)
{
	struct node* parent = NULL;
	struct node* temp = NULL;
	temp = root;
	

	while(temp->value != data)
	{
		if(temp->value > data)
		{
			parent = temp;
			temp = temp->left;
		}
		else if(temp->value < data)
		{
			parent = temp;
			temp = temp->right;
		}
	}

if(temp->left == NULL && temp->right == NULL)           //leaf node
{
	if(parent->left == temp)
	{
		parent->left = NULL;
	}
	else if(parent->right == temp)
	{
		parent->right = NULL;
	}

	temp->right = NULL;
	temp->left = NULL;
	

	free(temp);
}

else if(temp->left == NULL && temp->right != NULL)         //right child exists
{
	parent->right = temp->right;

	temp->right = NULL;
	temp->left = NULL;
	
	free(temp);
}

else if(temp->right == NULL && temp->left != NULL)        // left child exists
{
	parent->left = temp->left;

	temp->left = NULL;
	temp->right = NULL;
	
	free(temp);
}

else if(temp->right != NULL && temp->left != NULL)       // both children exists
{
	struct node* min_node = NULL;
	struct node* subtree_parent = NULL;

	min_node = temp->right;
	subtree_parent = min_node;

	while(min_node->left != NULL)
	{
		subtree_parent = min_node;
		min_node = min_node->left;
	}

	temp->value = min_node->value;

	subtree_parent->left = NULL;

	min_node->left = NULL;
	min_node->right = NULL;

	free(min_node);

}   

}


void inorder_display(struct node* root)
{
	if(root == NULL)
	{
		return;
	}


	//left root right

	inorder_display(root->left);

	printf("value = %d\n", root->value);

	inorder_display(root->right);
}



void preorder_display(struct node* root)
{
	if(root == NULL)
	{
		return;
	}

	//root left right

	printf("value = %d\n", root->value);

	preorder_display(root->left);

	preorder_display(root->right);
}


void postorder_display(struct node* root)
{
	if(root == NULL)
	{
		return;
	}

	//left right root

	postorder_display(root->left);

	postorder_display(root->right);

	printf("value = %d\n", root->value);

}










