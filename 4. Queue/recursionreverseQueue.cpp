#include <iostream> 
using namespace std; 
#define capacity 100
int rear=-1,front=-1;
int queue[capacity];
int size;
int n = size;
void enqueue(int x)
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
		return 0;
	}	
	y= queue[front++];

	return y;
}
  
// Recursive function to reverse the queue 
void recursionreverseQueue(int queue[]) 
{ 
    
    if (front==-1 && rear == -1) 
        return; 
  
    // dequeue current item   
     int data = dequeue();  
  
    // reverse remaining queue   
    recursionreverseQueue(queue); 
  
    // enqueue current item (to rear)   
    enqueue(data); 
} 
  
// Driver code 
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
		enqueue(arr[i]);	
	}
    
    recursionreverseQueue(queue); 
    while (front!= size-1) 
	{ 
        cout << dequeue << " "; 
        
    } 
} 


