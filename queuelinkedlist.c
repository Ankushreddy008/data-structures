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
		temp = (struct node*)malloc(sizeof(struct node));
		printf("enter the data");
		scanf("%d",&temp->data);
		temp->link = NULL;

	if(front == NULL && rear == NULL)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		while(rear->link != NULL)
		{
			rear->link =rear;
		}
		rear->link = temp;
		rear = temp;
	}
}

void dequeue()
{
	struct node* temp;
	if(front == NULL && rear == NULL)
	{
		printf("the list is empty");
	}
	else
	{
		temp = front;
		front = front->link;
		free(temp);
	}
}

void display()
{
	struct node* temp;
	temp = front;

	if(front == NULL && rear == NULL)
	{
		printf("the list is empty");

	}
	
	else
	{
		printf("queue:");
		while(temp->link != NULL)
		{
			printf("%d-->", temp->data);
			temp = temp->link;
		}
		printf("%d",temp->data);
		printf("\n");
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

void peek()
{
	struct node* temp;
	temp = front;
	if(front == NULL && rear == NULL)
	{
		printf("the list is empty");
	}
	else
	{
		while(temp->link != NULL)
		{
			temp = temp->link;
		}

		printf("the latest element in the queue is %d",temp->data);
	}
}

//WORKS FINE.