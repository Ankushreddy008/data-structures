#include<stdio.h>
#include<stdlib.h>
void append();
int lengthofthelist();
void display();
void insert();
void delete();
struct node
{
	int data;
	struct node* link;
};

struct node* head = NULL;

int main()
{	
	while(1)
	{
		int choice;
		int len;
		printf("1.append\n");
		printf("2.length of the list\n");
		printf("3.display\n");
		printf("4.insert\n");
		printf("5.delete\n");
		printf("6.exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: append();
					break;
			case 2: len = lengthofthelist();
					printf("the length of the list is %d\n",len);
					break;
			case 3: display();
					break;		
			case 4: insert();
					break;
			case 5:	delete();
					break;	
			case 6: exit(1);
					break;
		}			
	}
		
return 0;

}

void append()
{
	struct node* temp;
	struct node* anotemp;
	temp =(struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->link = NULL;

	if(head == NULL)
	{
		head = temp;
		temp->link = temp;
	}
	else
	{
		anotemp = head;
		while(anotemp->link != head)
		{
			anotemp = anotemp->link;
		}
			anotemp->link = temp;
			temp->link = head;
	}
}

int lengthofthelist()
{		
		int count = 1;
		struct node* temp;
		temp = head;

		if(head == NULL)
			{
				printf("the list is empty\n");
			}

		else
		{
			while(temp->link != head)
			{
				count++;
				temp = temp->link;
			}
		}

	return count;
}

void display() 
{
	struct node* temp;
	temp = head;

	if(temp == NULL)
	{
		printf("the list is empty\n");

	}
	else
	{
		while(temp->link != head)
		{
			printf("%d-->",temp->data);
			temp = temp->link;
		}
		printf("%d\n",temp->data);
	}
}

void insert()
{	
	int loc;
	int present = 0;
	printf("enter the location you wanna insert\n");
	printf("if you want to insert it in the beginning, then enter 0\n");
	scanf("%d", &loc);
	struct node* temp;
	temp= (struct node*)malloc(sizeof(struct node));
	printf("enter the data to be entered");
	scanf("%d",&temp->data);
	temp->link = NULL;
	struct node* anotemp;
	anotemp = head;

	if(head == NULL)
	{
		append();
	}
	else
	{
		if(loc == 0)
		{
			temp->link = head;
			while(anotemp->link != head)
			{
				anotemp = anotemp->link;
			}
			head = temp;
			anotemp->link = temp;
		}
		else
		{
			while(present < loc -1)
			{
				present++;
				anotemp = anotemp->link;
			}
			temp->link = anotemp->link;
			anotemp->link = temp;
		}
	}
}

	
void delete()
{
	int loc;
	int present = 0;
	printf("enter the location to delete");
	printf("if the node you want to delete in the  first node, then choose 0");
	scanf("%d",&loc);
	struct node* temp;
	temp= head;
	struct node* anotemp;
	anotemp = head;

	if( head == NULL)
	{
		printf("the list is empty");
	}

	else
	{
		if(loc == 0)
		{
			while(anotemp->link != head)
			{
				anotemp = anotemp->link;
			}
			head = temp->link;
			anotemp->link = head;
			temp->link = NULL;
			free(temp);
		}
		else
		{
			while(present < loc)
			{
				present++;
				temp = temp->link;
			}
			anotemp = temp->link;
			temp->link = anotemp->link;
			anotemp->link = NULL;
			free(anotemp);
		}
	}

}

// WORKS FINE.