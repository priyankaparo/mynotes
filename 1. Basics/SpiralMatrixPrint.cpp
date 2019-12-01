#include<iostream>  
using namespace std;

int main()
{
 	int n;                                                                      //Size of the array
	cout<<"Enter the size of the array :";
	cin>>n;                                
	int A[n][n];
	int len=n,k=1,p=0,i,j;             //k is to assign the values to the array from 1...n*n 
	cout<<"enter the elements of matrix: \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>A[i][j];
		}
	}		
	cout<<"entered matrix: \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}		
	cout<<"spiral print: \n";						
	while(k<=n*n)                      
	{
		for(i=p;i<len;i++)                      //Loop to access the first row of the array
		{
			cout<<A[p][i]<<" ";
		}
		for(i=p+1;i<len;i++)            //Loop to access the last column of the array
		{
		    cout<<A[i][len-1]<<" ";
		}
		for(i=len-2;i>=p;i--)                 //Loop to access the last row of the array 
		{
			cout<<A[len-1][i]<<" ";
		}
		

                      for(i=len-2;i>p;i--)              //Loop to access the first column of the array
		{
			cout<<A[i][p]<<" ";
		}
		p++;
                     len=len-1;
		
	}

	return 0;
}



