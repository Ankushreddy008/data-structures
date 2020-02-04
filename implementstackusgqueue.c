#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 7

void enqueue(int,int);
int dequeue(int);
void display();
void push();
int pop();

int frontone = -1;
int rearone = -1;
int fronttwo = -1;
int reartwo = -1;
int turn = 0;


int queueone[CAPACITY];
int queuetwo[CAPACITY];

int main()
{
	int choice;
	int popped;
	printf("1.push\n");
	printf("2.pop\n");
	printf("3.display\n");
	printf("4.exit\n");


	while(1)
	{	
		printf("enter the choice\n");
	    scanf("%d",&choice);
		switch(choice)
		{

			case 1: push();
					break;
			case 2: popped = pop();
					printf("the value popped is %d\n",popped);
					break;
			case 3: display();
					break;
			case 4: exit(1); 
					//break;
		}


	}
	return 0;

}

void enqueue(int element,int turn)
{

	if(turn  == 0)
	{
		if(frontone == -1 && rearone == -1)
		{
			frontone = 0;
			rearone = 0;
			queueone[rearone] = element;
		}
		else
		{
			//frontone = 0;
			rearone = rearone + 1;
			queueone[rearone] = element;
		}

	}
	else
	{
		if(fronttwo == -1 && reartwo == -1)
		{
			fronttwo = 0;
			reartwo = 0;
			queuetwo[reartwo] = element;
		}
		else
		{
			//fronttwo = 0;
			reartwo = reartwo + 1;
			queuetwo[reartwo] = element;
		}
	}

}
int dequeue(int turn)
{
	int temp;

	if(turn  == 0)
	{

		if(frontone == -1)
		{
			printf("the list is empty\n");
		}

		if(frontone == rearone)
		{
			temp = queueone[frontone];
			frontone = -1;
			rearone = -1;
		}

		else
		{
			
			temp = queueone[frontone];
			frontone = frontone + 1;

		}
		return temp;
	
	}

	else
	{
		if(fronttwo == -1)
		{
			printf("the list is empty");
		}


		if(fronttwo == reartwo)
		{
			
			temp = queuetwo[fronttwo];
			fronttwo = -1;
			reartwo= -1;

		}
		else
		{
			temp = queuetwo[fronttwo];
			fronttwo = fronttwo + 1;
		}
		return temp;

	}

}

void display()
{
	
	int disp;
	printf("%d %d %d %d \n", frontone, rearone, fronttwo, reartwo);

	if(turn == 1)
	{
		disp = frontone;
		printf("Stack : ");
		while(disp != rearone)
		{
			printf("%d ",queueone[disp]);
			disp = disp + 1;
		}
		printf("%d\n",queueone[disp]);
	}
		else
	{
		disp = fronttwo;
		printf("Stack : ");
		while(disp!= reartwo)
		{
			printf("%d ",queuetwo[disp]);
			disp = disp + 1;
		}
		printf("%d\n",queuetwo[disp]);

		//printf("%d %d %d %d \n", frontone, rearone, fronttwo, reartwo);
	}
}

void push()
{
	int popped;
	int element;

	printf("enter the element to push");
	scanf("%d",&element);

	if (turn  == 0)
	{
		enqueue(element, turn);

		while(fronttwo != -1)
		{
			popped = dequeue((turn+1)%2); 
			enqueue(popped,turn);
		}
		
		//turn= (turn + 1)%2;
	}

	if(turn == 1)
	{
		enqueue(element,turn);

		while(frontone != -1)
		{
			popped = dequeue((turn+1)%2);
			enqueue(popped,turn);
		}
	}

	turn = (turn + 1) % 2;
}

int pop()
{
	int popped;
	popped = dequeue((turn+1)%2);
	//turn = (turn+1) % 2;
	return popped;
}

//	WORKS FINE
