#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5
void enqueue();
void dequeue();
void display();
int isempty();
void peek();

int queue[CAPACITY];
int front = 0;
int rear = 0;
int element,i;

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
	if(rear == CAPACITY)
	{
		printf("queue is full");
	}
	else
	{
		int element;
		printf("enter the element");
		scanf("%d",&element);
		queue[rear] = element;
		rear =rear + 1;
	}
}

void dequeue()
{
	if(front == rear)
	{
		printf("the queue is empty");
	}
	else
	{
		element = queue[front];
		for(i=front;i< rear;i++)
		{
			queue[i] = queue[i+1];
		}
		rear = rear -1;
	}
}

void display()
{
	if(front == rear)
	{
		printf("the list is empty");
	}
	else
	{
		printf("queue:");
		for(i  = front;i < rear;i++)
		{
			printf("%d  ",queue[i]);
		}
		printf("\n");
	}
}

int isempty()
{
	if(front == rear)
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
	if(front == rear)
	{
		printf("the list is empty\n");
	}
	else
	{
		rear = rear-1;
		printf("the latest element in the queue is %d\n",queue[rear]);
		rear = rear+1;
	}
}

//WORKS FINE.
