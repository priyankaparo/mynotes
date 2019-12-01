#include<iostream>
using namespace std;

#define max_size 1000

int arr[max_size],n;
void RestructureHeapUp(int n,int i)
{
    int parent=(i-1)/2;
    if(i && arr[parent] >arr[i])
    {
    	int temp = arr[i];
    	arr[i]=arr[parent];
    	arr[parent]=temp;
    	RestructureHeapUp(n , parent);

	}
}

void RestructureHeapDown(int i,int n)
{
	int left = 2*i+1;
    int right = 2*i+2;
    int smallest = i;
    
    if(left<n && arr[left]<arr[smallest])
          smallest = left;
    if(right<n && arr[right]<arr[smallest])
          smallest = right;
          
    if(smallest !=i)
    {
    	int temp = arr[i];
    	arr[i]=arr[smallest];
    	arr[smallest]=temp;
    	RestructureHeapDown(smallest,n);
	}
}


void insertinHeap(int k,int n)
{
	n = n+1;
	arr[n-1]=k;
    RestructureHeapUp(n, n-1);
}

int deleteFromHeap(int n)
{
	int lastElement = arr[n - 1]; 
  
    // Replace root with first element 
    int temp=arr[0];
    arr[0] = lastElement; 
  
    // Decrease size of heap by 1 
    n --;
  
    // heapify the root node 
    RestructureHeapDown(0,n); 
    return temp;
}
int main()
{
	int i;
	cout<<"enter the number of elements which u want for min heap: ";
	cin>>n;
	cout<<"enter the elements which u want for min heap: ";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		insertinHeap(arr[i],i);
	}
	cout<<"min heap:\n";
	for (i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<"\nafter 5 times deletion: deleted elemnts";
    for(i=0;i<5;i++)
    {
    	int p=	deleteFromHeap(n);
         cout<<p<<" ";
	}
	cout<<"\nafter 5 times deletion updated heap: \n";
	for (i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    
	
    
	return 0;
}


