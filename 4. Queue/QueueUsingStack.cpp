#include <iostream> 
using namespace std; 
#define capacity 100

int top1=-1,top2=-1;
int stack1[capacity],stack2[capacity];
int size;
//stack 1
void push1(int x , int size)
{
	if(top1== size-1 )
	{
		cout<<"stack is full: overflow ";
		return;
	}
	stack1[++top1]=x;
	
}
int pop1()
{
	int y;
	if(top1==-1)
	{
		cout<<"stack is empty:underflow ";
		return 0;
	}	
	y=stack1[top1];
	top1--;

	return y;
}
 //stack 2 
 void push2(int x , int size)
{
	if(top2== size-1 )
	{
		cout<<"stack is full: overflow ";
		return;
	}
	stack2[++top2]=x;
	
}
int pop2()
{
	int y;
	if(top2==-1)
	{
		cout<<"stack is empty:underflow ";
		return 0;
	}	
	y=stack2[top2];
	top2--;
	return y;
}
void enqueue(int k,int size)
{
	int i,p , q ;

	if(top1 ==-1)
	{
		push1(k,size);
	}
	else
	{
		q=top1;
		for(i=0;i<top1;i++)
		{
			p=pop1();
			push2(p,size);
		}	
	  push1(k,size);
	  for(i=0;i<q;i++)
		{
			p=pop2();
			push1(p,size);
		}		
	}	
}

int dequeue(int size)
{
	int i,y,p;
	for(i=0;i<size;i++)
	{
	  p=pop1();
	  push2(p,size);
	}
	y=pop2();
	return y;
}
int main() 
{ 
    int size,i,k,l;
	cout<<"Enter no of elemnts : ";
	cin>>size;
	int arr[size];
	cout<<" Enter elements(enqueue): ";
	for(i=0;i<size;i++)
	{
		cin>>arr[i];
		enqueue(arr[i],size);
	}
	cout<<"no of elemnets u want to dequeue: ";
	cin>>l;
	cout<<"elements of queue(after popping): ";
	for(i=0;i<l;i++)
	{
		k=dequeue(size);
		cout<<k<<" ";
	}
} 


