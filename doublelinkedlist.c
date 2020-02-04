#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void append();
int lengthofthelist();
void insert();
void display();
void delete();
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* head = NULL;
//head= NULL;

int main()
{
		while(1)
	{


		int choice;
		int length;
		printf("1.append\n");
		printf("2.the length of the list\n");
		printf("3.display\n");
		printf("4.insert\n");
		printf("5.delete\n");
		printf("6.exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
switch(choice)
{
	case 1:  append();
			 break;
	case 2: length = lengthofthelist();
			printf("the length of the list is %d \n",length);
			break;
	case 3: display();
			break;
	case 4: insert();
			break;
	case 5: delete();
			break;
	case 6: exit(1);
			break;
	default: printf("invalid input");
			break;		

}

}
return 0;
}

void append()
{
	struct node* temp;
	struct node* anotemp;
	anotemp = head;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter the node data\n");
	scanf("%d",&temp->data);
	temp->left = NULL;
	temp->right = NULL;

	if(head == NULL)
	{
		head = temp;
	}

	else
	{
		while(anotemp->right !=NULL)
		{
			anotemp = anotemp->right;
		}
		anotemp->right = temp;
		temp->left = anotemp;
	}
}

 
int lengthofthelist()
{
	int count = 1;
	struct node* temp;
	temp = head;

	if(temp == NULL)
	{
		printf("the list is empty\n");

	}

	else
	{
		while(temp->right != NULL)
		{	
			count++;
			temp = temp->right; 
		}
	}
	return count;

}

void display()
{
	struct node* temp;
	temp= head;

	if(temp == NULL)
		{
			printf("the list is empty\n");
		}

		else
		{
				while(temp->right != NULL)
				{
				printf("%d-->",temp->data);
				temp = temp->right;
				}
				printf("%d\n",temp->data);	

		}
}

void insert()
{	
	int loc;
	int present = 0;
	printf("enter the location to insert\n");
	printf("if the location is beginning of the list, then input loc to be 0\n");
	scanf("%d",&loc);
	struct node* temp;
	temp = (struct node*) malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d", &temp->data);
	temp->right = NULL;
	temp->left = NULL;
	struct node* anotemp;
	anotemp = head;


	if(loc == 0)
	{
		if(head == NULL)
		{
			append();
		}
		else
		{
			temp->right = head; 
	 		head->left = temp;
	 		head = temp;
		}
	}

	 
	 else
	 {
	 	while(present < loc - 1)
	 	{
	 		present ++;
	 		anotemp = anotemp->right;
	 	}
	 	temp->right = anotemp->right;
	 	temp->left = anotemp;
	 	anotemp->right = temp;
	 	temp = temp->right;

	 	if(temp != NULL)
	 	{
	 		temp->left = anotemp->right;
	 	}

	 	//temp->left = anotemp->right; 
	 }
	 
}

void delete()
{

	int present = 0;
	int loc;
	printf("enter the location you want to delete");
	scanf("%d",&loc);
	struct node* temp;
	temp = head;
	struct node* duptemp = NULL;
	struct node* anotemp = NULL;

	if( head == NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		if(loc == 0)
		{
			head = temp->right;
			temp->right = NULL;
			free(temp);
		}
		else
		{
			while(present < loc)
			{
				present++;
				temp = temp->right;
			}
			duptemp = temp;
			duptemp = temp->left;
			duptemp->right = temp->right;

			if(temp->right != NULL)
			{
				anotemp = temp->right;
				anotemp->left = duptemp;
			}

			temp->left = NULL;
			temp->right = NULL;
			free(temp);
		}
	}
}		
		





//WORKS FINE.