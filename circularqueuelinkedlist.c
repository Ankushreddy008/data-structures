#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
int isempty();
void peek();

struct node
{
	int data;
	struct node* link;
};

struct node* front = NULL;
struct node* rear = NULL;

int main()
{

	int choice;
	int referee;
	while(1)
	{
		printf("1.enqueue\n");
		printf("2.dequeue\n");
		printf("3.display\n");
		printf("4.isempty\n");
		printf("5.peek\n");
		printf("6.exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: enqueue();
					break;
			case 2:dequeue();
					break;
			case 3:display();
					break;
			case 4: referee = isempty();
			printf("the result is %d\n",referee);
					break;
			case 5: peek();
					break;
			case 6:	exit(1);
					break;				
		}

	}
	return 0;
}

void enqueue()
{

	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the element to insert\n");
	scanf("%d",&temp->data);
	temp->link = NULL;

	if(front == NULL && rear == NULL)
	{
		 front = temp;
		 rear = front;
		 temp->link = rear;
	}
	else
	{	
		
		temp->link = front;
		rear->link = temp;
		rear = temp;
	}
}

void dequeue()
{	
	struct node* temp = front;

	if(front == NULL && rear == NULL)
	{
		printf("the queue is empty\n");
	}

	if(front == rear)
	{
		front= NULL;
		rear = NULL;
		free(temp);
	}
	else
	{
		//struct node* temp = front;
		rear->link = temp->link;
		front = temp->link;
		free(temp);
	}
}

int isempty()
{
	if(front == NULL && rear == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void display()
{
	struct node* temp = front;

	if(front == NULL && rear == NULL)
	{
		printf("the list is empty\n");
	}
	else
	{
		printf("queue:");
		while(temp->link !=front)
		{
			printf("%d  ",temp->data);
			temp =temp->link;
		}
		printf("%d\n",temp->data);
	}
}

void peek()
{
	printf("the latest element to enter the queue is %d\n",rear->data);
}



//	WORKS FINE.
