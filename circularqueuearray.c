#include<stdio.h>
#include<stdlib.h>
# define CAPACITY 7

int queue[CAPACITY];
int front = -1;
int rear = -1;
void enqueue();
void dequeue();
void display();
int isempty();
void peek();

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
	int element;
	printf("enter the element to push into the queue");
	scanf("%d",&element);

	if(front == -1 && rear == -1)
	{
		front = front + 1;
		rear = rear + 1;
		queue[rear] = element;
	}
	else
	{
		if((rear +1)%CAPACITY != front)
		{
			rear = rear + 1;
			queue[rear] = element ; 
		}
		else
		{
			printf("the queue is full");
		}
	}

}

void dequeue()						//problem in this.
{
	//printf("front %d",front);
	//printf("rear %d",rear);

		if(front == -1 && rear == -1)
	{
		printf("the list is empty");
	}

	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = (front + 1)%CAPACITY;

	}

}

void display()
{
	int disp;
	disp = front;
	if(disp == -1 && rear == -1)
	{
		printf("the list is empty");
	}
	else
	{

	while(disp != rear)
	{
		printf("%d  ",queue[disp]);
		disp = disp + 1;
	}
	printf("%d",queue[disp]);
	printf("\n");

	}
}

int isempty()
{
	if(front == -1 && rear == -1)
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
	if(front == -1 && rear == -1)
	{
		printf("the queue is empty");
	}
	else
	{
		printf("the latest element in the queue is %d",queue[rear]);
	}
}

// 	WORKS FINE.