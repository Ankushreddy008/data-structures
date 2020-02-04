#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define CAPACITY 7
void push(int, int);
int pop(int);
void enqueue(int);
int dequeue();
void display();
int isempty();
int stackone[CAPACITY];
int stacktwo[CAPACITY];
int stacktopone = -1;
int stacktoptwo = -1;
int turn = 0;
int count = 0;

int main()
{
	int choice;
	int result;
	int element;
	while(1)
	{
		printf("1.enqueue\n");
		printf("2.dequeue\n");
		printf("3.isempty\n");
		printf("4.display\n");
		printf("5.exit\n");
		printf("enter the choice");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: printf("enter the element to enqueue");
					scanf("%d",&element);
					enqueue(element);
					break;
			case 2: result= dequeue();
					printf("the value popped is %d\n",result);
					break;
			case 3: result = isempty();
					printf("the result is %d\n",result);
					break;
			case 4: display();
					break;		
			case 5: exit(1);
					break;
		}
	}
}

void push(int element, int turn)
{
	if(turn == 0)
	{
		if(stacktopone == -1)
		{
			stacktopone = 0;
			stackone[stacktopone] = element;
		}
		else
		{
			stacktopone++;
			stackone[stacktopone] = element;
		}	
	}
	else
	{
		if(stacktoptwo == -1)
		{
			stacktoptwo = 0;
			stacktwo[stacktoptwo] = element;
		}
		else
		{
			stacktoptwo++;
			stacktwo[stacktoptwo] = element;
		}
	}

}

int pop(int turn)
{
	int temp = 0;

	if(turn == 0)
	{
		if(stacktopone == -1)
		{
			printf("the stack is empty");
		}
		else
		{
			temp = stackone[stacktopone];
			stacktopone--;
			return temp;
		}
	}
	else
	{
		if(stacktoptwo == -1)
		{
			printf("the stack is empty");
		}
		else
		{
			temp = stacktwo[stacktoptwo];
			stacktoptwo--;
			return temp;
		}
	}
}

void enqueue(int element)
{
	if(stacktopone == CAPACITY-1)
	{
		printf("the queue is full");
	}
	else
	{
		push(element,turn);
		count++;
	}
}

int dequeue()
{
	int popped = 0;
	int temp = 0;

while(stacktopone >= 0)
{
	if(turn == 0)
	{
		popped = pop(turn);

		if(stacktopone == -1) 
		{
			temp = popped;
			break;
		}
			turn = (turn+1)%2;
			push(popped,turn);
			turn = (turn+1)%2;
	}

}

memset(stackone,0,CAPACITY*sizeof(stackone[0]));

turn = (turn+1) % 2;

//memset(stackone,0,CAPACITY*sizeof(stackone[0]));

while(stacktoptwo >= 0)
{
	if(turn == 1)
	{
		popped = pop(turn);
		turn = (turn+1)%2;
		push(popped,turn);
		turn = (turn+1)%2;
	}
}
turn = (turn+1)%2;
return temp;
}

int isempty()
{
	if(stacktopone == -1)
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
	int i=0;
	printf("stack: ");

	for(i=0;i<=stacktopone;i++)
	{
		printf("%d ",stackone[i]);
	}
	printf("\n");
}

//WORKS FINE.