#include<iostream>
#define capacity 100


using namespace std;
int rear=-1,front=-1;
int top=-1;
int stack[capacity];
//stck push and pop fucntion;
void push(int x)
{
	if(top== capacity-1)
	{
		cout<<"stack overflow";
		return;
		
	}
	top++;
	stack[top]=x;
}
int pop()
{
	int y;
	if(top == -1)
	{
		cout<<"stack underflowflow";
		return -1;
		
	}
	else
	{
		y= stack[top];
		top--;	
	}
	return y;
}

//queue ...enqueue adn dequue functions
int queue[capacity];
void enqueue(int x, int n)
{
	if(rear+1 == front || rear==capacity )
	{
		cout<<"queue is full ";
		return;
	}
	else if(front==-1)
	{
		front=0;
		
	}
	++rear;
	rear= rear % n;
	queue[rear]=x;
	
}
int dequeue()
{
	int y;
	if(front==-1 && rear == -1)
	{
		cout<<"queue is empty: ";
		//exit();
		return 0;
	}	
	y= queue[front++];

	return y;
}

//reversequeue program using stack;

void reverseQueue(int size)
{
	int k,p,i;
	
	// at first pushing elements in stack from dequeing the queue;
	for(i=0;i<size;i++)
	{
		k= dequeue();
	    push(k);
	}
	
	//then will pop elemnts from stack and it will be reverse of the queue;
	
	cout<<" Popping out from stack: "<<endl;
	
	for(i=0;i<size;i++)
	{
		p=pop();
		cout<<p<<" ";
	}
}

int main()
{
	int size,i;
	cout<<"Enter no of elemnts : ";
	cin>>size;
	int arr[size];
	cout<<" Enter elements: ";
	for(i=0;i<size;i++)
	{
		cin>>arr[i];
		enqueue(arr[i],size);	
	}
	reverseQueue(size);
	
	
}


