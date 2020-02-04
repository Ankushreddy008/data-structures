#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void topofthestack();
int isEmpty();
void display();

struct node
{
	int data;
	struct node* link;
};

struct node* stacktop = NULL;

int main()
{
	while(1)
	{
		int choice,result;
		printf("enter the operation\n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.topofthestack\n");
		printf("4.isEmpty\n");
		printf("5.display\n");
		printf("6.exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 : push();
					 break;
			case 2 : pop();
					 break;
			case 3 : topofthestack();
					 break;
			case 4: result = isEmpty();
					printf(" the result is %d\n",result);
					 break;
			case 5: display();
					break;	
			case 6: exit(1);
					break;
		}						 		 
	}
	return 0;
}

void push()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("enter the data to be pushed\n");
	scanf("%d",&temp->data);
	temp->link = NULL;

	if(stacktop == NULL)
	{
		stacktop = temp;
	}
	else
	{
		temp->link = stacktop;
		stacktop = temp;
	}

}
void pop()
{
	struct node* temp;
	temp = stacktop;

	if(temp ==NULL)
	{
		printf("the stack is empty\n");

	}
	else
	{
		stacktop = temp->link;
		temp->link = NULL;
		free(temp); 
	}

}

void topofthestack()
{
	if(stacktop == NULL)
	{
		printf("the stack is empty\n");
	}
	else
	{
		printf("%d",stacktop->data);
		printf("\n");
	}
}

int isEmpty()
{
	if(stacktop == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

void display()
{
	if(stacktop == NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		struct node* temp;
		temp = stacktop;
		printf("stack:");
		while(temp->link !=NULL)
		{
			printf("%d  ",temp->data);
			temp = temp->link;
		}
		printf("%d",temp->data);
		printf("\n");
	}
}

//WORKS FINE.