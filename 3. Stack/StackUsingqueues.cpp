#include <iostream> 
using namespace std; 

#define capacity 100
int size;

int rear1=-1;
int rear2=-1;
int front1=-1;
int front2=-1;
int queue1[capacity],queue2[capacity];
//creation of queue1 and queue2
void enqueue1(int x)
{
	if((rear1 +1)% size ==front1)
	{
		cout<<"queue is full "<<endl;
		return;
	}
	else if(front1==-1 && rear1==-1)
	{
		front1=0;
		rear1=0;
	}
	else
	{
	rear1 = (rear1+1)% size;
    }
	queue1[rear1]= x;
}

int dequeue1()
{
	int y;
	if(front1==-1 && rear1==-1)
	{
		cout<<"queue is empty "<<endl;
		return 0;
	}
	else
	{	
        y=queue1[front1];
        front1=(front1+1);
        if(front1 > rear1)
            front1 = rear1 = -1;
        return y;
    }
	
}
void enqueue2(int x)
{
	if((rear2 +1)% size ==front2)
	{
		cout<<"queue is full "<<endl;
		return;
	}
	else if(front2==-1 && rear2==-1)
	{
		front2=0;
		rear2=0;
	}
	else
	{
	rear2 = (rear2+1)% size;
    }
	queue2[rear2]= x;
}

int dequeue2()
{
	int y;
	if(front2==-1 && rear2==-1)
	{
		cout<<"queue is empty "<<endl;
		return 0;
	}
	else
	{	
        y=queue2[front2];
        front2=(front2+1);
        if(front2 > rear2)
            front2 = rear2 = -1;
        return y;
    }
	
}


 // push operation using queue1 and queue2
void push(int x)
{
	int p,q,k,i;
	//if q1 is empty then directly push the elemnt
	if(front1==-1 && rear1==-1)
	{
		enqueue1(x);
	}
	//if queue1 having some elemnts then enque them into queue2 and push new elemnt to queue1 and then whole items of queue2 again enqueue into queue1
	else
	{
		q=rear1;
		for(i=0;i<=q;i++)
		{
			p=dequeue1();
			enqueue2(p);
		}
		enqueue1(x);
		for(i=0;i<=q;i++)
		{
			k=dequeue2();
			enqueue1(k);
		}
	}
}

 // pop operation using queue1
int pop()
{
	//dequeue elemnts from queue1
	int y;
	y=dequeue1();
	return y;

}

int main() 
{ 
    int i,k,l;
	cout<<"Enter no of elemnts : ";
	cin>>size;
	int arr[size];
	cout<<" Enter elements(push in stack): ";
	for(i=0;i<size;i++)
	{
		cin>>arr[i];
		push(arr[i]);
	}
	cout<<"no of elements u want to pop: ";
	cin>>l;
	cout<<"elements of stack(which has been popped out): ";
	for(i=0;i<l;i++)
	{
		k=pop();
		cout<<k<<" ";
	}
} 



