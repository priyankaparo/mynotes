#include<bits/stdc++.h>
using namespace std;

void median(int med[] ,int size ,int new_numbercount)
{
 int p,q,k;
 //sorted the array at first
	 sort(med ,med+size);
	 
	 //calculated the mid index
	 k=(size+new_numbercount)%2;
	
	//if number of elemnts are odd then mid elemnt of array will be median;
	if(k!=0)
	{
		cout<<med[(size+new_numbercount)/2];
	}
	
	//if no of elemnts are even then mid of mid elemnt and next of that mid elemnt will be median
	else
	{
	 p =(size+new_numbercount)/2;
	 q= (med[p]+med[p+1])/2;
	 cout<<q;
	}

}
int main()
{
	int n,k,i;
	cout<<"enter the size of array: ";
	cin>>n;
	int arr[n];
	cout<<"enter array elements: ";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"enter the no of stream number: ";
	cin>>k;
	cout<<"enter stream numbers: ";
	for(i=n;i<n+k;i++)
	{
		cin>>arr[i];
	}
	cout<<"median of stream is : ";
    median(arr,n,k);
}



