//this program is for both {finding nth ugly number and to print whole ugly number till count }
#include<iostream>
using namespace std;

int Divideby235(int num)
{
	if(num%2==0)
	{
	 return 1;	
	}
	if(num%3==0)
	{
		return 1;
	}
	if(num%5==0)
	{
		return 1;
	}
	return 0;
}
int arr[1000];

//for finding uglynumbers of count k

void uglynumbers(unsigned int k)
{
	int count=1,i,p;
	i=1;
	while(k>=count)
		{
			if(i<7)
			{
				cout<<i<<" ";
				arr[count++]=i;
		    }
		   else
		   {
		   	p = Divideby235(i);		   	   
		   	   if(p==1)
			   	{
			   			cout<<i<<" ";
			   			arr[count++]=i;
			   			
			    }
	
			} 
			i++;
		}
	
}

int main()
{
	unsigned int n,k;
	cout<<"enter how many (only positive) ugly number: ";
	cin>>n;
	uglynumbers(n);
	cout<<"\n nth ugly element: ";
	cin>>k;
	cout<<arr[k];
}


