#include<iostream>
using namespace std;

int front =0;
int rear=0;
int find (int arr[],int x,int size)
{
	int sum =0;
	int min_window=999999;
	int n=size;
	while(rear<n && front < n)
	{
		//summ of all elemnts until required sum is reached
		while(sum < x && rear < n)
		{
		
					sum=sum+arr[rear++];
		}
		
		//the sum has reached greater than num
		while(sum >x && front<rear)
		{
			if(rear-front < min_window)
			{
				min_window=rear-front;//updating the window;
				sum=sum-arr[front++];
			}
		}
		return min_window;
	}
	
}
int main()
{
	int size,i,num;
	cout<<"enter the size of array: ";
	cin>>size;
	int arr[size];
	cout<<"enter the elements of array: ";
	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<"enter the given number: ";
	cin>>num;
	int k=find (arr,num,size);
	if(k==999999)
	{
		cout<<"not possible\n";
	}
	else
	{
		cout<<"\n window_size: ";
		cout<<k;
		cout<<"\noutput subarray: ";
		for(int i=front-1;i<rear;i++)
		{
			cout<<arr[i]<<" ";
		}
	}
}


