#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node* link;

};
struct node* head= NULL;
void append();
int lengthofthelist();
void display();
void insert();
void delete();



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
			printf("the length of the list is %d",length);
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
	temp = (struct node*) malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d", &temp->data);
	temp->link = NULL;

	if( head == NULL)
	{
			head = temp;
	}
	else
	{
		   anotemp = head;
		
		while(anotemp->link != NULL)
		{
			anotemp = anotemp->link;

		}

		anotemp->link = temp;
	}

}

int lengthofthelist()
{
	int count = 0;
	struct node* temp;
	temp = head;


	if(temp == NULL)
	{
		printf("the list is empty\n");

	}
	else
	{
		while(temp->link != NULL)
		{
			count++;
			temp = temp->link;
		}
		count++; 
		
	}
	printf("\n");
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
		while(temp->link != NULL)
		{
			printf("%d--->",temp->data);
			temp = temp->link;	
		}

		printf("%d",temp->data);
		printf("\n");
	}
}

void insert()
{	
	int loc;
	int present  = 1;
	printf("enter the location after you want to insert\n");
	printf("if the location you want to insert is in the beginning, then its zero\n");
	scanf("%d", &loc);
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter the data");
	scanf("%d",&temp->data);
	temp->link =NULL;
	struct node* anotemp;
	anotemp= head;


	if(loc == 0)
	{
		if(anotemp == NULL)
		{
			append();
		}
		else  
		{
			temp->link = anotemp;
			head = temp;
		}
	}

	else
	{
		while(present < loc)
		{
			present++;
			anotemp = anotemp->link;
		}
		temp->link = anotemp->link ; 
		anotemp->link = temp;

	}
}

void delete()   
{
	int loc;
	int present = 0;
	printf("enter the location you wanna delete\n");
	scanf("%d",&loc);
	struct node* temp;
	struct node* anotemp;
	temp = head;
	//anotemp = temp->link;

	if((head == NULL))
	{
		printf("nothing to delete");
	}

	else
	{
	 if(loc == 0)
	
	{
		anotemp = temp->link;
		head = anotemp;
		temp->link = NULL;
		free(temp);
	}
	else
	{
		anotemp = temp->link;
		while(present < loc-1)
		{	
			present++;
			anotemp = anotemp->link;
			temp = temp->link; 
		}
		temp->link = anotemp->link;
		anotemp->link =NULL;
		free(anotemp);
	}
	}
}


//WORKS FINE.