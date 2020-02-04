#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

int stacktop = -1;
int a[MAXSIZE];
void display();
void push(int);
int pop();
int peek();
void isEmpty();



int main()
{	
	int choice;
	int result;
	int element;
	while(1)
	{
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.isEmpty\n");
		printf("4.display\n");
		printf("5.peek\n");
		printf("6.exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the element to push\n");
					scanf("%d",&element);
					push(element);
					break;
			case 2: result = pop();
					printf("the popped value is %d\n",result);
					break;
			case 3:	isEmpty();
					break;
			case 4: display();
					break;
			case 5: result = peek();
			        printf("the value is %d\n",result);
					break;
			case 6: exit(1);
					break;
		}

	}
}
 
 void push( int x)
{	
	stacktop = stacktop + 1;
	a[stacktop] = x;	
}

int pop()
{	
	int temp = 0;
	if(stacktop == -1)
	{
		printf("the stack is empty");

	}
	else
	{
		temp = a[stacktop];
		stacktop = stacktop-1;
	}
	return temp;
	
}

int peek()
{
	return a[stacktop];
}

void isEmpty()
{
	if(stacktop == -1)
	{
		printf("the stack is empty");
	}

	else
	{
		printf("the elements are present in the stack\n");
		display();
	}
}

void display()
{
	int i;
	if(stacktop == -1)
	{
		printf("the stack is empty");
	}

	else
	{
		printf("stack:");
		for(i =0 ; i<= stacktop; i++)
		{	
			//printf("stack:");
			printf(" %d  ", a[i]);
		}
		printf("\n");
	}
}

// WORKS FINE.
