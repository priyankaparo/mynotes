#include<iostream>

using namespace std;

int size,top=-1;
int stack[100];
void push(int x)
{
	if(top >= size-1)
	{
		cout<<"stack overflow "<<endl;
		return;
	}
	top++;
	stack[top]= x;
}

int pop()
{
	int y;
	if(top<=-1)
	{
		cout<<"stack underflow "<<endl;
	}
	else
	{
	  y = stack[top];
	  top--;	
	}
	return y;
}
 
int Isempty()
{
	if(top<=-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
 
int main()
{
	size=3;
	push(1);
	push(2);
	push(3);
	pop();
	pop();
	while(!Isempty())
	{
		cout<<pop()<<" ";
	}
	
	
}
